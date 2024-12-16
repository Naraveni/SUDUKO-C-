#include "sixyBoard.hpp"
//constructor
SixyBoard::SixyBoard(ifstream& puzzFile): Board('s', puzzFile){
    for (short rowStart = 1; rowStart <= 6; rowStart += 2) { 
        for (short colStart = 1; colStart <= 6; colStart += 3) {
            short rowEnd = rowStart + 1; 
            short colEnd = colStart + 2;
            createHbox(rowStart, colStart, rowEnd, colEnd); 
        }
    }
    for (short colStart = 1; colStart <= 6; colStart += 2) {
        for (short rowStart = 1; rowStart <= 6; rowStart += 3) {
            short rowEnd = rowStart + 2;
            short colEnd = colStart + 1;
            createVbox(rowStart, colStart, rowEnd, colEnd);
        }
    }
    sixyTurnOff();
    //shooping the board
    shoopBoard();
}

//creates horizontal boxes
void SixyBoard::createHbox(short rowStart, short colStart, short rowEnd, short colEnd){
    Square* hBoxSquares[9];
    short index = 0;
    // Loop through the rows and columns defined by the HBox range
    for (short i = rowStart; i <= rowEnd; ++i) {
        for (short j = colStart; j <= colEnd; ++j) {
            hBoxSquares[index++] = &sub(i, j);
        }
    }
    // Create the Cluster for HBox and add it to the list
    Cluster* hBoxCluster = new Cluster(hBoxSquares, ClusterT::HBOX, 6);
    clstrs.push_back(hBoxCluster);
}

//creates vertical boxes
void SixyBoard::createVbox(short rowStart, short colStart, short rowEnd, short colEnd) {
    // This function creates a vertical box (VBox) from the start to end indices
    Square* vBoxSquares[9];
    short index = 0;
    // Loop through the rows and columns defined by the VBox range
    for (short i = rowStart; i <= rowEnd; ++i) {
        for (short j = colStart; j <= colEnd; ++j) {
            vBoxSquares[index++] = &sub(i, j);
        }
    }
    // Create the Cluster for VBox and add it to the list
    Cluster* vBoxCluster = new Cluster(vBoxSquares, ClusterT::VBOX,6);
    clstrs.push_back(vBoxCluster);
}

//turnoffs possibilities of 7,8 and 9 for sixy board
void SixyBoard::sixyTurnOff(){
    for(int m =0 ;m <(n*n); m++){
        bd[m].turnOff(7);
        bd[m].turnOff(8);
        bd[m].turnOff(9);
    }
}