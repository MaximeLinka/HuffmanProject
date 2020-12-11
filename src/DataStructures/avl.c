#include "avl.h"

void add_BST(Node** tree, char val) {//remade for an avl based on letters
    if (*tree == NULL) {
        *tree = createNode(1, val);
    }
    else if (val == (*tree)->character)
    {
        (*tree)->occurences += 1;
    }
    if (val < (*tree)->character) {
        add_BST(&((*tree)->left), val);
    }
    else if (val > (*tree)->character) {
        add_BST(&((*tree)->right), val);
    }
}

void add_node_AVL(Node** tree, char val) {

    add_BST(tree, val);
    balance(tree);
}


void balance(Node** tree) {
    if (*tree != NULL) {
        balance(&((*tree)->left));
        balance(&((*tree)->right));

        int balance_factor = bf(*tree);
        if (balance_factor <= -2) {//Left - ????
            if (bf((*tree)->left) > 0) {// Left - Right
                left_rotation(&((*tree)->left));
            }
            right_rotation(tree);// Left-Left
        }
        else if (balance_factor >= 2) {//Right - ????
            if (bf((*tree)->right) < 0) {// Right - Left
                right_rotation(&((*tree)->right));
            }
            left_rotation(tree);// Right-Right
        }
    }
}

int bf(Node* tree) {
    if (tree == NULL) {
        return 0;
    }
    else {
        return tree_depth(tree->right) - tree_depth(tree->left);
    }
}

//ROTATIONS
void right_rotation(Node** tree) {
    if (*tree != NULL) {
        Node* temp = (*tree)->left;
        (*tree)->left = temp->right;
        temp->right = *tree;
        *tree = temp;
    }
}

void left_rotation(Node** tree) {
    if (*tree != NULL) {
        Node* temp = (*tree)->right;
        (*tree)->right = temp->left;
        temp->left = *tree;
        *tree = temp;
    }
}

int tree_depth(Node* tree) {
    if (tree == NULL) {
        return 0;
    }
    else {
        int dl = tree_depth(tree->left);
        int dr = tree_depth(tree->right);

        if (dl > dr) {
            return dl + 1;
        }
        else {
            return dr + 1;
        }
    }
}

Node* CreateAvl(char* string)//creates AVL in terms  of letters
{
    int i = 0;
    Node* tree = (Node*)malloc(sizeof(Node));
    tree = NULL;

    while (string[i] != '\0')
    {
        add_node_AVL(&tree, string[i]);
        i++;
    }
    return tree;
}


void AvlToArray(Node * my_array, Node* tree, int * meter)// encountered some bugs with meter nullptr
{
    if (tree != NULL) {
        printf("%d", *meter);
        AvlToArray(my_array,tree->left, meter);
        AvlToArray(my_array, tree->right, meter);
        my_array[*meter] = *createNode(tree->occurences, tree->character);
        *meter += 1;
        
    }
    
}




int TreesCountNodes(Node* tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    return TreesCountNodes(tree->left) + TreesCountNodes(tree->right) + 1;
}