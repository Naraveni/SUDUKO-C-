#ifndef __STATE__H__
#define __STATE__H__

/*
Harsha Vardhan Reddy Bana
Sreethi Sasikumar
*/

#include "tools.hpp"
#include "logger.hpp"
#include "gameLogicError.hpp"

class State{
    protected:
        short poss = 0x3fe;
        char value = '-';
        bool fixed = false;
    public:
        State()=default; 
        State(char cellValue);
        ~State() = default;
        virtual void mark(char ch);
        virtual ostream& print(ostream &out) const;
        char getValue(){return value;};
        void turnOff(int n);
        short getPoss(){return poss;}
};
 
inline ostream& operator << (ostream& out, const State& s) {
	return s.print(out);
}
#endif  //!__STATE__H__
