#include <QCoreApplication>
#include <iostream>
#include <stack>

using namespace std;

typedef struct ListNode_
{
    int n_value;
    struct ListNode_ *p_next;
}ListNode;

void reverse_print_list_recursive(ListNode *pListHead)
{
    if(pListHead != NULL)
    {
        if(pListHead->p_next != NULL)
        {
            reverse_print_list_recursive(pListHead->p_next);
        }

        cout << pListHead->n_value << " ";
    }
    cout << endl;
}

void reverse_print_list_iterate(ListNode *pListHead)
{
    stack<ListNode*> nodeStack;

    if(pListHead != NULL)
    {
        ListNode *pTemp1 = pListHead;

        while(pTemp->p_next != NULL)
        {
            nodeStack.push(pTemp->p_next);
            pTemp = pTemp->p_next;
        }

        ListNode *pTemp2;
        while(!nodeStack.empty())
        {
            pTemp2 = nodeStack.top();
            cout << pTemp2->n_value << " ";
            nodeStack.pop();
        }
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
