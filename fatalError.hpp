#ifndef __FATALERROR__H__
#define __FATALERROR__H__

#include "tools.hpp"
class FatalError{
    public:
        virtual void print(){
            fatal("A Fatal Error Has Occured\n");
        }
};

class InputFileNotFoundError: public FatalError{
    public:
        void print(){
            fatal("Input Puzzle File Is Absent/Not Found\n");
        }
};

class InvalidInputFile: public FatalError{
    public:
        void print(){
            fatal("Input Puzzle File Contents Are Not Valid For Constructing The Suduko\n");
        }
};

class GameTypeNotValid: public FatalError{
    public:
        void print(){
            fatal("Game Type In The Input Puzzle FIle Is Not Valid\n");
        }
};

#endif  //!__FATALERROR__H__