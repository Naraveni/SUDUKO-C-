#include "board.hpp"

//checking the puzzle is valid or not
void Board::getPuzzle(){
    char c;
    char ch = '0' + n;
    for(int m=1; m<=n;m++){
        for(int k=1;k<=n;k++){
            puzzle >> c;
            if ((c!='-') && (c<'1' || c>ch)){ 
                throw InvalidInputFile();};
            (*this)(m,k) = Square(c,m,k);
        }
        puzzle.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (puzzle >> c) {
        throw InvalidInputFile();
    }
}

//constructor
Board::Board(char gameType, ifstream& puzzFile):puzzle(puzzFile) ,type(gameType){
    try{
        Logger::getStream()<< "Contructing The Board"<<'\n';
        if(gameType == 't' || gameType == 'd'){
            n=9;
        }
        else if(gameType=='s'){
            n=6;
        }
        else{
            throw GameTypeNotValid();
        }
    }
    catch(GameTypeNotValid e){
        e.print();
    }
    bd = new Square[n*n];
    emptySquares = n*n;
    getPuzzle();
    makeClusters();
    Logger::getStream()<< "Board Construction Done"<<'\n';
}

//printing all clusters from the board
ostream& Board::print(ostream& out) const{
    for(Cluster* cl: clstrs){
        out << *cl;
    }
    return out<< '\n';
}

//making clusters for each row, column and box
void Board::makeClusters(){
    for (short m = 1; m <= n; ++m){
        createRow(m);
    }
    for (short m = 1; m <= n; ++m){
        createColumn(m);
    }
}

//creating row cluster
void Board::createRow(short j) {
    Square* rowSquares[n];
    for (short m = 1; m <= n; ++m) {
        rowSquares[m-1] = &(*this)(j,m);
    }
    Cluster* rowCluster = new Cluster(rowSquares, ClusterT::ROW,n);
    clstrs.push_back(rowCluster);
}

//creating column cluster
void Board::createColumn(short k) {
    Square* columnSquares[n];
    for (short m = 1; m <= n; ++m) {
        columnSquares[m-1] = &(*this)(m,k);
    }
    Cluster* columnCluster = new Cluster(columnSquares,ClusterT::COLUMN,n);
    clstrs.push_back(columnCluster);
}

//Shoops the entire board
void Board::shoopBoard(){
    Square s;
    char ch = '0' + n;
    for(int k = 1; k<=n; k++){
        for(int m =1; m<=n; m++){
            s = (*this)(k,m);
            char val =  s.getValue();
            //shooping only for non empty states
            if(val>='1' && val<=ch){
                s.shoop(val);
            }
        };
    }
}

//return the value of square at the requested index
char Board::getMarkChar(int r, int c) const{
    Square s = (*this)(r,c);
    return s.getValue();
}

//returns possibility string of the square at the requested index
string Board::getPossibilityString(int r, int c) const{
    short poss = (*this)(r, c).getPoss();
    string possibilty = "";
    for(int m = 9; m>=1 ; m--){
        possibilty = possibilty + ((((poss >> m & 1)) ? (char)(48+m) : '-'));
    }
    return possibilty;
}

//performs a board move (marking the squares)
Frame* Board::move() {
    char val;
    Frame* frame;
    vector<int> rowCol;
    rowCol = getSudukoIndex();
    while(true){
        try {
            // Input Value
            val = getValidValInput();
            (*this)(rowCol[0], rowCol[1]).mark(val);
            break;
        } 
        catch (StateNotEmpty& e) {
            e.print();
            return nullptr;
        } 
        catch (ValueNotPossible& e) {
            e.print();
            return nullptr;
        }
    }
    frame = new Frame(bd);
    return frame;
}

//restores the board to the supplied frame state
void Board::restore(Frame* frame){
    for(int x=0; x<(n*n); x++){
        bd[x].updateState(frame->getStateAtI(x));
    }
}

//turnoffs possibility for a value in a square at the requested index
Frame* Board::turnOffPoss(){
    char val;
    Frame* frame;
    vector<int> rowCol;
    rowCol = getSudukoIndex();
    val = getValidValInput();
    (*this)(rowCol[0], rowCol[1]).turnOff(val-'0');
    frame = new Frame(bd);
    return frame;
}

//helper function for checking valid value input for a square
char Board::getValidValInput(){
    char val;
    char ch = '0' + n;
    while (true) {
        cout << "\n\nPlease Enter Your Value: ";
        cin >> ws >> val;
        if (val > '0' && val <= ch){
            return val;
        }
        else {
            cout << "\n\nError: Entered Value Is Not A Valid Value, Please Try Again\n\n ";
        }
    }
}

vector<int> Board::getSudukoIndex(){
    vector<int> rowCol;
    string index;
    char ch = '0' +n ;
    while (true) {
        try {
            cout << "Please Enter Index of Row And Column(EX: 12 for Row 1 and Column 2): ";
            cin >> index;
            if(index.length() >2){
                throw InvalidIndex();
            }
            else if(index[0] < '1' || index[0] > ch || index[1] < '1' || index[1] > ch){
                throw InvalidIndex();
            } 
            else {
                rowCol.push_back(index[0] - '0');
                rowCol.push_back(index[1]-'0');
                break;
            }
        } catch (InvalidIndex& e) {
            e.print(n);
        }
    }
    return rowCol;
}

void Board::save(){
    ofstream outFile("sudoku_board.txt");
    outFile << type << '\n';
    // Loop through the board to print its state
    for (int row = 1; row <= n; ++row) {
        for (int col = 1; col <= n; ++col) {
            Square& square = (*this)(row, col);  // Get the square at (row, col)
            char value = square.getValue();      // Get the value of the square
            // If the value is not empty, print it; otherwise, print '-'
            outFile << (value != '0' ? value : '-');
        }
        outFile << '\n';  // End of row
    }
    // Close the file
    outFile.close();
    cout << "Board state saved to sudoku_board.txt" << '\n';
}

void Board::restoreFromSave() {
    try {
        std::ifstream inputFile("sudoku_board.txt");
        if (!inputFile) {
            throw SaveFileError();
        }
        char boardType;
        inputFile >> boardType;
        if (boardType != type) {
            throw SaveFileCorrupted();
        }
        // Dynamically allocate memory for n*n Squares
        Square* tempSquares = new Square[n * n];
        int row = 1;
        string line;
        getline(inputFile, line);
        while (getline(inputFile, line)) {
            if (line.length() != static_cast<size_t>(n)) {
                delete[] tempSquares;
                throw SaveFileCorrupted();
            }
            for (int col = 1; col <= n; ++col) {
                char ch = line[col - 1];
                int index = (row - 1) * n + (col - 1);
                tempSquares[index] = Square(ch, row, col);
            }
            ++row;
        }
        if (row != n + 1) {
            delete[] tempSquares; // Cleanup before throwing
            throw SaveFileCorrupted();
        }
        // Create a Frame using the dynamically allocated Square array
        Frame* frame = new Frame(tempSquares);
        // Use the restore function with the created frame
        restore(frame);
        delete frame;
        delete[] tempSquares;
        cout << "Game state restored from file: sudoku_board.txt" << std::endl;
        shoopBoard();
    }
    catch (SaveFileError& e) {
        e.print();
        return;
    }
    catch (SaveFileCorrupted& e) {
        e.print();
        return;
    }
}
