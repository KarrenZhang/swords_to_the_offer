#include <QCoreApplication>
#include "cqueue.h"
#include "cstack.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CQueue<int> queue;
    queue.appendTail(3);
    queue.appendTail(4);
    queue.appendTail(2);
    queue.appendTail(6);
    queue.appendTail(8);
    queue.appendTail(7);
    queue.appendTail(9);
    queue.appendTail(1);
    while(!queue.empty())
    {
        queue.deletedHead();
    }

    CStack<int> stack;
    stack.push(3);
    stack.push(4);
    stack.push(2);
    stack.push(6);
    stack.push(8);
    stack.push(7);
    stack.push(9);
    stack.push(1);
    while(!stack.empty())
    {
        stack.pop();
    }

    return a.exec();
}
