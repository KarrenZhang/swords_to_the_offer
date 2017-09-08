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

int preorder_traversal_iterate(BinaryTreeNode *root_node)
{
    stack<BinaryTreeNode*> node_stack;
    BinaryTreeNode* temp = root_node;
    //int visited[] = new int[len];

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
        if(temp != NULL)
        {
            node_stack.push(temp->m_pRight);
            node_stack.push(temp->m_pLeft);
        }
//        if(temp->m_pLeft != NULL)
//        {
//            node_stack.push(temp->m_pLeft);
//            continue;
//        }
//        if(temp->m_pRight != NULL)
//        {
//            node_stack.pop();
//            node_stack.push(temp->m_pRight);
//            continue;
//        }


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

int inorder_traversal_iterate(BinaryTreeNode *root_node)
{

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

int postorder_traversal_iterate(BinaryTreeNode *root_node)
{

}

int level_order_traversal(BinaryTreeNode *root_node)
{

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    BinaryTreeNode btree[9];
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
    btree[6].m_pRight = NULL;
    btree[7].m_nValue = 8;
    btree[7].m_pLeft = NULL;
    btree[7].m_pRight = NULL;

    btree[8].m_nValue = 9;
    btree[8].m_pLeft = NULL;
    btree[8].m_pRight = NULL;

    preorder_traversal_recursive(btree);
    cout << endl;
    preorder_traversal_iterate(btree);

    return a.exec();
}
