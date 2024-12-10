#ifndef __TRADBOARD__H__
#define __TRADBOARD__H__

#include "board.hpp"

class TradBoard : public Board {
private:
    // Helper function to create all the box clusters
    void createAllBoxes();
    // Function to create a single box cluster
    void createBox(short rowStart, short colStart);
public:
    // Constructor for TragBoard
    TradBoard(char gameType, ifstream& puzzFile) : Board(gameType, puzzFile) {createAllBoxes();shoopBoard();}
};
#endif  //!__TRADBOARD__H__
