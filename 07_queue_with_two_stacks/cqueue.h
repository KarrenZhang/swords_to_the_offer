#ifndef CQUEUE_H
#define CQUEUE_H

#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class CQueue
{
public:
    CQueue();
    ~CQueue();

    void appendTail(const T& node);
    T deletedHead();
    bool empty();
private:
    stack<T> stack1;
    stack<T> stack2;
};

#endif // CQUEUE_H
