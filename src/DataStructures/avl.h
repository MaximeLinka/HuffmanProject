/*****************************************************************//**
* \file avl.h
* \brief Header of the library containing the avl tree.
*********************************************************************/


#include "huffman_tree.h"

#ifndef AVL_H
#define AVL_H

/**
 * \brief a function to perform a right rotation on an avl tree.
 * \param tree the adress of a pointer to an avl tree.
*/
void right_rotation(Node** tree);

/**
 * \brief a function to perform a left rotation on an avl tree.
 * \param tree the adress of a pointer to an avl tree.
*/
void left_rotation(Node** tree);

/**
 * \brief a function that returns the depth of a tree.
 * \param tree a pointer to an avl tree.
*/
int tree_depth(Node* tree);

/**
 * \brief a function to create an avl tree from a string.
 * \param string a c string.
*/
Node* CreateAvl(char* string);

/**
 * \brief a function that returns the balance factor of a tree.
 * \param tree a pointer to an avl tree.
*/
int bf(Node* tree);

/**
 * \brief a function that balances an binary search tree.
 * \param tree the adress of a pointer to an avl tree.
*/
void balance(Node** tree);

/**
 * \brief a function to add a a character to an avl.
 * \param tree the adress of a pointer to an avl tree.
 * \param val the character to add.
*/
void add_node_AVL(Node** tree, char val);

/**
 * \brief a function to transform an avl to an array.
 * \param my_array the array of nodes in which the tree is going to be converted.
 * \param tree a pointer to an avl tree.
*/
void AvlToArray(Node* my_array, Node* tree, int * meter);

/**
 * \brief a function that returns the number of nodes in a tree.
 * \param tree a pointer to an avl tree.
*/
int TreesCountNodes(Node* tree);

/**
 * \brief a function that adds a character to a Binary search tree.
 * \param tree the adress of a pointer to an avl tree.
 * \param val the character to add.
*/
void add_BST(Node** tree, char val);


#endif