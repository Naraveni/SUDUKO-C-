#ifndef __BOARD__H__
#define __BOARD__H__

#include "tools.hpp"
#include "square.hpp"
#include "logger.hpp"
#include "cluster.hpp"
#include "Enums.hpp"
#include "fatalError.hpp"
#include "gameLogicError.hpp"
#include "CanView.hpp"
#include "Viewer.hpp"
#include "Frame.hpp"

class Board: public CanView{
    protected:
        ifstream& puzzle;
        int n;
        Square* bd;
        short emptySquares;
        Square& sub(int r, int c) const {return bd[n*(r-1)+(c-1)];}
        void getPuzzle();
        vector<Cluster*> clstrs;
        void makeClusters();
        void createRow(short j);
        void createColumn(short k);
        void createBox(short j, short k);
        void shoopBoard();
        //helper function to get valid value input
        char getValidValInput();
        vector<int> getSudukoIndex();
        
    public:
        Board(char gameType, ifstream& puzzFile);
        ~Board(){delete[] bd; Logger::getStream()<<"Board Destructed"<<'\n';}
        ostream& print(ostream& out) const;
        Square* getSquares(){return bd;}
        char getMarkChar(int r, int c) const override;
        string getPossibilityString(int r, int c) const override;
        Frame* move();
        void restore(Frame* frame);
        Frame* turnOffPoss();
        // Square& operator()(int row, int col) const {return bd[n * (row - 1) + (col - 1)];}
};

inline ostream& operator<< (ostream& out, const Board& b) { 
	return b.print(out);
}
#endif  //!__BOARD__H__