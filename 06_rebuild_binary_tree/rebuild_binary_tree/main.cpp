#include <QCoreApplication>
#include <iostream>

using namespace std;

typedef struct BinaryTreeNode_
{
    int m_nValue;
    BinaryTreeNode_* m_pLeft;
    BinaryTreeNode_* m_pRight;
}BinaryTreeNode;

BinaryTreeNode* rebuild_binary_tree(int *preorder, int pre_len, int *inorder, int in_len)
{
    BinaryTreeNode* root_node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    root_node->m_nValue = preorder[0];

    int root_inorder_index = 0;
    while(inorder[root_inorder_index] != root_node->m_nValue && root_inorder_index < in_len)
    {
        root_inorder_index++;
    }
    if(root_inorder_index == in_len)
    {
        free(root_node);
        return NULL;
    }

    root_node->m_pLeft = rebuild_binary_tree(preorder+1, root_inorder_index, inorder, root_inorder_index);
    root_node->m_pRight = rebuild_binary_tree(preorder+root_inorder_index+1, pre_len-root_inorder_index-1, inorder+root_inorder_index+1, in_len-root_inorder_index-1);

    return root_node;


}

int postorder_traversal_recursive(BinaryTreeNode *root_node)
{
    if(root_node != NULL)
    {
        postorder_traversal_recursive(root_node->m_pLeft);
        postorder_traversal_recursive(root_node->m_pRight);
        cout << root_node->m_nValue << " " << endl;
        free(root_node);
    }

    return 0;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int preorder[] = {1,2,4,7,10,8,5,9,3,6};
    int inorder[]  = {7,10,4,8,2,9,5,1,3,6};

    BinaryTreeNode* tree_head = rebuild_binary_tree(preorder, 10, inorder, 10);
    postorder_traversal_recursive(tree_head);

    return a.exec();
}
