#include "diagBoard.hpp"

//diagonal clusters creation
DiagBoard::
DiagBoard(ifstream& puzzFile):  TradBoard('d', puzzFile){
    Square* diagonal1[9];
    Square* diagonal2[9];

    //creating the two diagonal clusters
    for(int m = 1;m<=9;m++){
        diagonal1[m-1] = &sub(m,m);
        diagonal2[m-1] = &sub(10-m,m);
    }
    Cluster* diagonalClstr1 = new Cluster(diagonal1, ClusterT::DIAG);
    Cluster* diagonalClstr2 = new Cluster(diagonal2, ClusterT::DIAG);
    clstrs.push_back(diagonalClstr1);
    clstrs.push_back(diagonalClstr2);
    shoopBoard();
}