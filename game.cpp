#include "game.hpp"

Game::Game(ifstream& in): inputFile(in) {
    //valid game types
    undo = new Stack();
    redo = new Stack();
    Frame* frame;
    string validGameType = "TtDdSs";
    inputFile >> gameType;
    try{
        if(validGameType.find(gameType) == string::npos) throw GameTypeNotValid();;     
        if(gameType == 't' || gameType == 'T'){
            board = new TradBoard(tolower(gameType),inputFile);
        }
        else if(gameType == 'd' || gameType == 'D'){
            board = new DiagBoard(inputFile);
        }
        else{
            board = new SixyBoard(inputFile);
        }
        fancyView =  new Viewer(9, 9, *board);
        fancyView->show(cout);
    }
    catch(InvalidInputFile e){
        e.print();
    }
    catch(GameTypeNotValid e){
        e.print();
    }
    frame = new Frame(board->getSquares());
    undo->push(frame);
    Logger::getStream() << *board;
}

void Game::run(){
    //stores valid menu choices
    string validMenuChoice = "MmUuRrSsXxQqTt";
    char choice;
    Frame* frame;

    //loop to keep asking the user for input after every operation unitl he chooses to exit
    while(true){    
        choice = menu_c("Please Select The Action From The Below Menu: ",7,menu,validMenuChoice);

        switch(choice){
            case 'm':
            case 'M':
            {
                //pushing the frame onto the undo stack
                frame = board->move();
                if(frame != nullptr){
                    undo->push(frame);
                    redo->zap();
                }
                Logger::getStream() << *board;
                fancyView->show(cout);
                break;
            }
            case 'U':
            case 'u':
            {
                perUndo();
                Logger::getStream() << *board;
                fancyView->show(cout);
                break;
            }
            case 'R':
            case 'r':
            {
                perRedo();
                Logger::getStream() << *board;
                fancyView->show(cout);
                break;
            }
            case 'T':
            case 't':
            {
                frame  = board->turnOffPoss();
                if(frame != nullptr){
                    undo->push(frame);
                    redo->zap();
                }
                Logger::getStream() << *board;
                fancyView->show(cout);
                break;

            }
            case 'Q':
            case 'q':{
                Logger::getStream() << "Qutting The Game!!";
                return;
            }
            default:{
                Logger::getStream()<<"Program Is Still In Development Phase. Several Operations Are Restricted"<<'\n';
            }
        }
    }  
}


//performs undo operation
void Game::perUndo(){
    try{
        if(undo->size()>1){
            redo->push(undo->top());
            undo->pop();
            board->restore(undo->top());
        }
        else{
            throw UndoOperationRestricted();
        }
    }
    catch(UndoOperationRestricted& e){
        e.print();
    }
}

//performs redo operation
void Game::perRedo(){
    try{
        if(redo->size() >0){
            undo->push(redo->top());
            redo->pop();
            board->restore(undo->top());
        }
        else{
            throw RedoOperationRestricted();
        }
    }
    catch(RedoOperationRestricted& e){
        e.print();
    }
}


//deletes the frames and stacks
void Game::clearStack(Stack* stack) {
    while (stack->size() > 0) {
        Frame* frame = stack->top();
        stack->pop();
        delete frame;
    }
    delete stack;
}

