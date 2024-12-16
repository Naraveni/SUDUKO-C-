#ifndef __STREAMERROR__H__
#define __STREAMERROR__H__

class StreamError {
    public:
        virtual void print(){
            cout <<  "A Stream  Error Has Occured\n";
        }
};
class SaveFileError: public StreamError{
    public:
        void print(){
            cout <<endl<< "Error While Opening The Saved File (Cannot Find suduko_board.txt)"<<endl<<endl;
        }
};
#endif  //!__STREAMERROR__H__
