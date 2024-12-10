#include "tradBoard.hpp"

void TradBoard::createAllBoxes() {
        for (short rowStart = 0; rowStart < n; rowStart += 3) {
            for (short colStart = 0; colStart < n; colStart += 3) {
                createBox(rowStart, colStart);
            }
        }
    }

void TradBoard::createBox(short rowStart, short colStart) {
        Square* boxSquares[n];
        short index = 0;
        for (short i = 1; i <= 3; ++i) {
            for (short j = 1; j <= 3; ++j) {
                boxSquares[index++] = &sub(rowStart + i, colStart + j);
            }
        }
        Cluster* boxCluster = new Cluster(boxSquares, ClusterT::BOX);
        cout << "Cluster Pushed";
        clstrs.push_back(boxCluster);
    }