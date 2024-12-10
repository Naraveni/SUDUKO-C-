#ifndef __GAME__H__
#define __GAME__H__

#include "tools.hpp"
#include "board.hpp"
#include "logger.hpp"
#include "diagBoard.hpp"
#include "Viewer.hpp"
#include "Stack.hpp"
#include "Frame.hpp"
#include "tradBoard.hpp"
#include "sixyBoard.hpp"

class Game{
    private:
        const string menu[7] = {"M: Mark","U: Undo","R: Redo","T: Turnoff Possibility","S: Save game","X: Restore game","Q: Quit and discard game"};
        Board* board;
        char gameType;
        short gameSize;
        ifstream& inputFile;
        Viewer* fancyView;
        Stack* undo;
        Stack* redo;
        void perUndo();
        void perRedo();
        void clearStack(Stack* stack);
    public:
        Game(ifstream& in);
        ~Game(){
            clearStack(undo);
            clearStack(redo);
        }
        void run();

        
        //XXXXXXXXXXXXXXXXX
        // The Below Code for testing purposes only will be removed in the future development
        //XXXXXXXXXXXXXXXXX
        Board* getBoard() {return board;}
};
#endif  //!__GAME__H__