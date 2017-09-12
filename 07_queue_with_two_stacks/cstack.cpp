#include "cstack.h"

template <typename T>
CStack<T>::CStack(void)
{

}

template <typename T>
CStack<T>::~CStack(void)
{

}

template <typename T>
void CStack<T>::push(const T& node)
{
    if(!queue1.empty())
    {
        queue1.push(node);
        return NULL;
    }
    if(!queue2.empty())
    {
        queue2.push(node);
        return NULL;
    }
    if(queue1.empty() && queue2.empty())
    {
        queue1.push(node);
    }
}

template <typename T>
T CStack<T>::pop(void)
{
    T temp;

    if(queue1.empty() && queue2.empty())
    {
        return NULL;
    }

    if(!queue1.empty())
    {
        while(queue1.size() > 1)
        {
            temp = queue1.front();
            queue1.pop();
            queue2.push(temp);
        }
        temp = queue1.front();
        cout << temp << endl;
        queue1.pop();
    }
    else
    {
        while(queue2.size() > 1)
        {
            temp = queue2.front();
            queue2.pop();
            queue1.push(temp);
        }
        temp = queue2.front();
        cout << temp << endl;
        queue2.pop();
    }

    return temp;
}

template <typename T>
bool CStack<T>::empty()
{
    if(!queue1.empty() && !queue2.empty())
    {
        return true;
    }
    return false;
}
