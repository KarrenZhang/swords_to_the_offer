#ifndef CSTACK_H
#define CSTACK_H

#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class CStack
{
public:
    CStack(void);
    ~CStack(void);

    void push(const T& node);
    T pop(void);
    bool empty();
private:
    queue<T> queue1;
    queue<T> queue2;
};

#endif // CSTACK_H
