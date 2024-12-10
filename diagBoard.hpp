#ifndef __DIAGBOARD__H__
#define __DIAGBOARD__H__

#include "tradBoard.hpp"

class DiagBoard: public TradBoard{
    public:
        DiagBoard(ifstream& puzzFile);
};
#endif  //!__DIAGBOARD__H__