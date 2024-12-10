/*
Harsha Vardhan Reddy Bana
Sreethi Sasikumar
*/
#include "square.hpp"
#include "cluster.hpp"

//constructor
Square::Square(char ch, short rowIndex, short colIndex): State(ch), row(rowIndex), column(colIndex) {
    Logger::getStream() << "Square[" << rowIndex << "," << colIndex << "] created."<<'\n';
}

//customized outputting
ostream& Square::print(ostream& out) const {
    out << "Square ["<<row<<","<<column<<"] ";
    State::print(out);
    return out<<'\n';
}

//mark function
void Square::mark(char value){
    State::mark(value);
    for(Cluster* cl: nbours){
        cl->shoop(value);
    }
}

//manipulating possibility of all squares in the clusters of a square of which value is changed
void Square::shoop(char val){
    for(Cluster* cl: nbours){
        cl->shoop(val);
    }
}

//updates the state part
void Square::updateState(State state){
    value = state.getValue();
    poss = state.getPoss();
}




