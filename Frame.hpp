#ifndef __FRAME__H__
#define __FRAME__H__

class Frame{
    private:
        State states[81];
    public:
        Frame(Square* squares) {
            for (int i = 0; i < 81; ++i) {
                states[i] = squares[i];
            }
        }
        State getStateAtI(int i){return states[i];}
};
#endif  //!__FRAME__H__