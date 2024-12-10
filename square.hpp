/*
Harsha Vardhan Reddy Bana
Sreethi Sasikumar
*/
#ifndef __SQUARE__H__
#define __SQUARE__H__
#include "state.hpp"
#include "logger.hpp"

//foward declaration to avoid circular dependency
class Cluster;

class Square: public State{
    private:
        short row;
        short column;
        vector<Cluster*> nbours;
    public:
        Square() = default;
        ~Square(){
            Logger::getStream()<< "Deleting Square["<<row<<","<<column<<"]"<<'\n';
        }
        Square(char ch, short rowIndex, short colIndex);
        ostream& print(ostream& out) const;
        void mark(char value);
        void shoop(char val);
        void addCluster(Cluster* cl){nbours.push_back(cl);}
        void updateState(State state);
};
#endif  //!__SQUARE__H__