#include <QCoreApplication>
#include <iostream>
#include <stack>

using namespace std;

typedef struct BinaryTreeNode_
{
    int m_nValue;
    BinaryTreeNode_* m_pLeft;
    BinaryTreeNode_* m_pRight;
}BinaryTreeNode;

int preorder_traversal_recursive(BinaryTreeNode *root_node)
{
    if(root_node != NULL)
    {
        cout << root_node->m_nValue << " " << endl;
        preorder_traversal_recursive(root_node->m_pLeft);
        preorder_traversal_recursive(root_node->m_pRight);
    }

    return 0;
}

/*!
 * \brief preorder_traversal_iterate1
 *  二叉树前序遍历，非递归方式，额外采用栈；
 *  栈中元素：未被访问的节点
 *  压栈：如果一个节点未被访问过，就将其压入栈中；
 *  出栈：要访问一个节点或一个节点将要被访问，就将其弹出栈；
 * \param root_node
 * \return
 */
int preorder_traversal_iterate1(BinaryTreeNode *root_node)
{
    stack<BinaryTreeNode*> node_stack;
    BinaryTreeNode* temp = root_node;

    if(temp == NULL)
    {
        return 0;
    }

    node_stack.push(temp);
    while(!node_stack.empty())
    {
        temp = node_stack.top();
        node_stack.pop();
        cout << temp->m_nValue << " " << endl;
        //[1]
        /* 若将此处换成“先压入左结点，continue，再弹出栈中第一个结点处理”，
           会导致最左侧分支最底部的孩子节点和其父亲，不断压栈、弹栈，
           程序进入死循环，这个方法行不通，该换成如下方法
         */
        //[2]
        /* 先压入右结点，再压入左结点，目的是先访问左结点 */
        if(temp->m_pRight != NULL)
        {
            node_stack.push(temp->m_pRight);
        }
        if(temp->m_pLeft != NULL)
        {
            node_stack.push(temp->m_pLeft);
        }
    }

    return 0;
}

int preorder_traversal_iterate2(BinaryTreeNode *root_node)
{
    stack<BinaryTreeNode*> node_stack;
    BinaryTreeNode* temp = root_node;

    if(temp == NULL)
    {
        return 0;
    }

    //错误解法
    /*
    while(temp != NULL || !node_stack.empty())
    {
        if(temp == NULL)
        {
            temp = node_stack.top();
            node_stack.pop();
        }
        cout << temp->m_nValue << endl;
        temp = temp->m_pLeft;
        while(temp != NULL)
        {
            cout << temp->m_nValue << endl;
//            node_stack.push(temp);
            temp = temp->m_pLeft;
        }

        temp = temp->m_pRight;
    }
    */

    //正确解法
    while(temp != NULL || !node_stack.empty())
    {
        while(temp != NULL)
        {
            cout << temp->m_nValue << endl;
            node_stack.push(temp);
            temp = temp->m_pLeft;
        }
        temp = node_stack.top();
        node_stack.pop();
        temp = temp->m_pRight;
    }

    return 0;
}

int inorder_traversal_recursive(BinaryTreeNode *root_node)
{
    if(root_node != NULL)
    {
        inorder_traversal_recursive(root_node->m_pLeft);
        cout << root_node->m_nValue << " " << endl;
        inorder_traversal_recursive(root_node->m_pRight);
    }

    return 0;
}

/*!
 * \brief inorder_traversal_iterate
 *  迭代中的每一次循环，模拟的都是递归遍历方式的一次递归调用，因此，
 *  一次循环模拟的要么是调用新的递归，要么是结束一次递归，具体执行
 *  哪一个操作，由递归的判断条件决定，而该判断条件，迭代要与递归相
 *  同。另外，以二叉树遍历问题为例，递归结束的条件是所有节点均遍历
 *  完成，也就是递归中不再有其它调用栈，所以，迭代中要加循环终止条
 *  件，即栈为空时，退出循环。
 * \param root_node
 * \return
 */
int inorder_traversal_iterate(BinaryTreeNode *root_node)
{
    stack<BinaryTreeNode*> node_stack;
    BinaryTreeNode* temp = root_node;

    if(temp == NULL)
    {
        return 0;
    }

    node_stack.push(temp);
    /**
      1. 初始解法-错误
        真实递归过程：递归过程中，如果当前元素不为NULL，则压入
      该元素的左孩子，至于它的左孩子是否为NULL，交由下一次递
      归调用判断。如果一次递归返回，表明上次压入的孩子节点为
      NULL，并且“返回”即表示出栈，所以，迭代中要弹出该空节点；
      接下来是访问先于已弹出的空节点压入的节点，该节点已访问，
      在迭代中就需要将其出栈，并将它的右孩子压入栈中，至于右孩
      子是否为NULL，交由下一次递归判断。
        错误原因：未真实按照递归调用模拟栈的压入和弹出。一次迭代
      循环中，首先判断的是它的左孩子是否为空，如果不为空，就将其
      压入栈中，并没有在循环中以当前节点为根本，而是以它的左孩子
      节点是否为空为判断根本,这样就会导致在最左侧的一支分支，最
      下面的节点没有左右孩子时，该节点就会频繁的入栈、出栈；如果
      它有右孩子，则将会循环打印该节点本身及其右孩子；
      */
    /*
    while(!node_stack.empty())
    {
        temp = node_stack.top();
        while(temp->m_pLeft != NULL)
        {
            node_stack.push(temp->m_pLeft);
            temp = node_stack.top();
        }
        node_stack.pop();
        cout << temp->m_nValue << " " << endl;
        if(temp->m_pRight != NULL)
        {
            node_stack.push(temp->m_pRight);
        }
    }
    */

    /**
      2. 正确解法
      原理：迭代中的每一次循环，模拟的都是递归遍历方式的一次递归调用，因此，
       一次循环模拟的要么是调用新的递归，要么是结束一次递归，具体执行
       哪一个操作，由递归的判断条件决定，而该判断条件，迭代要与递归相
       同。另外，以二叉树遍历问题为例，递归结束的条件是所有节点均遍历
       完成，也就是递归中不再有其它调用栈，所以，迭代中要加循环终止条
       件，即栈为空时，退出循环。
      */
    while(!node_stack.empty())
    {
        temp = node_stack.top();
        while(temp != NULL)
        {
            node_stack.push(temp->m_pLeft);
            temp = node_stack.top();
        }
        //弹空指针
        node_stack.pop();
        if(!node_stack.empty())
        {
            temp = node_stack.top();
            node_stack.pop();
            cout << temp->m_nValue << endl;
            node_stack.push(temp->m_pRight);
        }
    }

    return 0;
}

int postorder_traversal_recursive(BinaryTreeNode *root_node)
{
    if(root_node != NULL)
    {
        postorder_traversal_recursive(root_node->m_pLeft);
        postorder_traversal_recursive(root_node->m_pRight);
        cout << root_node->m_nValue << " " << endl;
    }

    return 0;
}

/*!
 * \brief postorder_traversal_iterate
 *  采用双栈来实现后序遍历。第一个栈用于按照“中、右、左”的方式遍历二叉树，
 *  将第一个栈弹出的元素push进第二个栈，依次输出第二个栈即是后序遍历。按
 *  照“中、右、左”的顺序访问二叉树时，其方式类似前序遍历非递归算法的第二
 *  种方式。
 * \param root_node
 * \return
 */
int postorder_traversal_iterate(BinaryTreeNode *root_node)
{
    stack<BinaryTreeNode*> node_stack1, node_stack2;
    BinaryTreeNode* temp = root_node;

    if(temp == NULL)
    {
        return 0;
    }

    node_stack1.push(temp);
    while(!node_stack1.empty())
    {
        temp = node_stack1.top();
        node_stack2.push(temp);
        node_stack1.pop();
        if(temp->m_pLeft != NULL)
        {
            node_stack1.push(temp->m_pLeft);
        }
        if(temp->m_pRight != NULL)
        {
            node_stack1.push(temp->m_pRight);
        }
    }

    while(!node_stack2.empty())
    {
        cout << node_stack2.top()->m_nValue << endl;
        node_stack2.pop();
    }

    return 0;
}

int level_order_traversal(BinaryTreeNode *root_node)
{

    return 0;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    BinaryTreeNode btree[10];
    btree[0].m_nValue = 1;
    btree[0].m_pLeft = &btree[1];
    btree[0].m_pRight = &btree[2];
    btree[1].m_nValue = 2;
    btree[1].m_pLeft = &btree[3];
    btree[1].m_pRight = &btree[4];
    btree[2].m_nValue = 3;
    btree[2].m_pLeft = NULL;
    btree[2].m_pRight = &btree[5];

    btree[3].m_nValue = 4;
    btree[3].m_pLeft = &btree[6];
    btree[3].m_pRight = &btree[7];

    btree[4].m_nValue = 5;
    btree[4].m_pLeft = &btree[8];
    btree[4].m_pRight = NULL;
    btree[5].m_nValue = 6;
    btree[5].m_pLeft = NULL;
    btree[5].m_pRight = NULL;

    btree[6].m_nValue = 7;
    btree[6].m_pLeft = NULL;
    btree[6].m_pRight = &btree[9];
    btree[7].m_nValue = 8;
    btree[7].m_pLeft = NULL;
    btree[7].m_pRight = NULL;

    btree[8].m_nValue = 9;
    btree[8].m_pLeft = NULL;
    btree[8].m_pRight = NULL;
    btree[9].m_nValue = 10;
    btree[9].m_pLeft = NULL;
    btree[9].m_pRight = NULL;

    preorder_traversal_recursive(btree);
    cout << endl;
    preorder_traversal_iterate2(btree);
    inorder_traversal_recursive(btree);
    cout << endl;
    inorder_traversal_iterate(btree);
    postorder_traversal_recursive(btree);
    cout << endl;
    postorder_traversal_iterate(btree);

    return a.exec();
}
