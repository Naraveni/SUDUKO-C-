
/*
Harsha Vardhan Reddy Bana
Sreethi Sasikumar
*/
#include "state.hpp"

//constructor
State::State(char cellValue): value(cellValue){    
    if(cellValue>='1' && cellValue<='9'){
        poss = 0;
        fixed =  true;
    }
    else {
        poss = 0x3fe;
        fixed =  false;
    }       
}

//state value can be set using this function
void State::mark(char ch) {
    if (fixed) {
        throw StateNotEmpty();
    } else {
        if ((poss >> (ch - '0')) & 1) {
            value = ch;
            poss = 0;
            fixed = true;
        } else {
            throw ValueNotPossible();
        }
    }
}

//custom output print format for State objects
ostream& State::print(ostream &out) const{
    out << "Value: " << value<<" ,Possibilities: ";
    for(int m = 9; m>=1 ; m--){
        out << (((poss >> m & 1)) ? (char)(48+m) : '-');
    }
    return out<< '\n';
}

//turning off possibility of a value in the state
void State::turnOff(int n){
    short mask = ~(1<<(n));
    poss &= mask;
}
