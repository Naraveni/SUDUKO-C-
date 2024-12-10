#ifndef __STACK__H__
#define __STACK__H__
#include <vector>
#include "Frame.hpp"
class Stack : private vector<Frame*> {
public:
    Stack() = default;
    ~Stack() = default;

    void push(Frame* frame) {
        push_back(frame);
    }

    void pop() {
        pop_back();
    }

    Frame* top() {
        return back();
    }

    int size() const {
        return vector<Frame*>::size();
    }

    void zap() {
        while (size()>0) {
            pop_back();
        }
    }

};
#endif  //!__STACK__H__