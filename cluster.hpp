#ifndef __CLUSTER__H__
#define __CLUSTER__H__

#include "square.hpp"
#include "board.hpp"
#include "Enums.hpp"

static const string ClusterType[] = {"Row","Column","Box","Diagonal","HBox","VBox"};

class Cluster{
    private:
        const char* type;
        Square* sq[9];
        int n;
    public:
        Cluster(Square* sqr[9], ClusterT cltype, int n=9);
        ostream& print(ostream& out) const;
        void shoop(char val);
};

inline ostream& operator << (ostream& out, const Cluster& s) { 
	return s.print(out);
}

#endif  //!__CLUSTER__H__