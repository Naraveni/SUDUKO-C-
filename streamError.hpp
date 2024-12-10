#ifndef __STREAMERROR__H__
#define __STREAMERROR__H__
#include "logger.hpp"

class StreamError {
    virtual void print(){
        Logger::getStream() <<  "A Stream  Error Has Occured\n";
    }
};
#endif  //!__STREAMERROR__H__