#include "huffman_tree.h"

#ifndef AVL_H
#define AVL_H

void right_rotation(Node** tree);
void left_rotation(Node** tree);
int tree_depth(Node* tree);
Node* CreateAvl(char* string);
int bf(Node* tree);
void balance(Node** tree);
void add_node_AVL(Node** tree, char val);
void AvlToArray(Node* my_array, Node* tree, int * meter);
int TreesCountNodes(Node* tree);
void add_BST(Node** tree, char val);

#endif