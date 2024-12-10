#ifndef __SIXYBOARD__H__
#define __SIXYBOARD__H__
#include "board.hpp"
class SixyBoard: public Board{
    private:
        void createHbox(short rowStart, short colStart, short rowEnd, short colEnd);
        void createVbox(short rowStart, short colStart, short rowEnd, short colEnd);
        //turnoffs possibility of 7,8 an 9 for sixy board
        void sixyTurnOff();
    public:
        SixyBoard(ifstream& puzzFile);
};
#endif  //!__SIXYBOARD__H__