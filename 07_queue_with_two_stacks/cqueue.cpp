#include "cqueue.h"

template <typename T>
CQueue<T>::CQueue()
{

}

template <typename T>
CQueue<T>::~CQueue()
{

}

/*!
 * 将操作“弹出栈1的元素并压入栈2中”放到appendTail()中，
 * 会导致一个问题：第一次将元素插入到队列中时，栈2中会有
 * 一个元素，再之后，所有的元素都在栈1中；如果连续执行两
 * 次从队列中删除的操作，第二次将会失败，因为栈2中不再有
 * 元素（但此时队列不为空，可是却删除不了元素）；只有当再
 * 次插入时，才会将栈1的所有元素放到栈2中。
 * 正确做法是将该操作放到deleteHead()中。
 */
/*
template <typename T>
void CQueue<T>::appendTail(const T& node)
{
    stack1.push(node);
    if(stack2.empty())
    {
        while(!stack1.empty())
        {
            T temp = stack1.top();
            stack2.push(temp);
            stack1.pop();
        }
    }
}

template <typename T>
T CQueue<T>::deletedHead()
{
    if(stack2.empty())
    {
        return NULL;
    }

    T temp = stack2.top();
    stack2.pop();
    cout << temp << endl;

    return temp;
}
*/

template <typename T>
void CQueue<T>::appendTail(const T& node)
{
    stack1.push(node);
}

template <typename T>
T CQueue<T>::deletedHead()
{
    if(stack2.empty())
    {
        if(stack1.empty())
        {
            return NULL;
        }
        while(!stack1.empty())
        {
            T temp = stack1.top();
            stack2.push(temp);
            stack1.pop();
        }
    }

    T temp = stack2.top();
    stack2.pop();
    cout << temp << endl;

    return temp;
}

template <typename T>
bool CQueue<T>::empty()
{
    if(stack1.empty() && stack2.empty())
    {
        return true;
    }

    return false;
}
