#ifndef __GAMELOGICERROR__H__
#define __GAMELOGICERROR__H__
class GameLogicError {
    public:
        virtual void print(){
            cout <<  "\n\nA Game Logic Error Has Occured\n\n";
        }
};

class StateNotEmpty: public GameLogicError{
    public:
        void print(){
            cout <<  "\n\nAttempt To Insert Value Failed, Square has an already a value fixed\n\n";
        }
};

class ValueNotPossible: public GameLogicError{
    public:
        void print(){
            cout <<  "\n\nAttempt To Insert Value Failed, Attempted Value Is Not Possible In This Square\n\n";
        }
};

class InvalidIndex: public GameLogicError{
    public:
        void print(int n){
            cout << "\n\nRow Or Column Index Should Be An Integer and Should Lie between 1 and "<<n<<" In Value\n\n";
        }
};

class UndoOperationRestricted: public GameLogicError{
    public:
        void print(){
            cout << "\n\n Undo Operation Cannot Be Performed At This Stage\n\n";
        }
};

class RedoOperationRestricted: public GameLogicError{
    public:
        void print(){
            cout << "\n\n Redo Operation Cannot Be Performed At This Stage\n\n";
        }
};
class SaveFileCorrupted: public GameLogicError{
    public:
        void print(){
            cout << "\n\n Save File Corrupted\n\n";
        }
};

#endif
