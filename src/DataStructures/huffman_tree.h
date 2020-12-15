/*****************************************************************//**
* \file huffman_tree.h
* \brief Header of the library containing the huffman tree.
*********************************************************************/

#include <stdlib.h>
#include "DataStructures/linkedlist.h"
#include "DataStructures/stack.h"

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

/**
* \typedef struct Node
* \brief a tree node.
*/
typedef struct Node 
{
    int occurences;
    char character;
    struct Node* left;
    struct Node* right;
} Node;

/**
* \typedef HuffmanTree
* \brief a nickname for Node*.
*/
typedef Node* HuffmanTree;

/**
* \typedef struct NodeElement
* \brief an element of a LinkedList of Nodes.
*/
typedef struct NodeElement
{
    Node* data;
    struct NodeElement* next;
} NodeElement;

/**
* \typedef struct NodeElement
* \brief an element of a LinkedList of Nodes.
*/
typedef NodeElement* NodeLinkedList;

/**
 * \brief a function to create a Node.
 * \param c a character.
 * \param value an int .
*/
Node* createNode(int value, char c);

/**
 * \brief a function to create a huffman tree link.
 * \param current_node a Node.
 * \param left another node.
*/
Node* createLink(Node* current_node, Node* leaf);  //creates parent to two leaves with sum of occurences as 'occurences' and '\0' as character

/**
 * \brief a function to create list of nodes.
 * \param l an occurence list.
*/
NodeLinkedList occurenceListToNodeList(OccurenceList l);

/**
 * \brief a function to create the huffman tree.
 * \param l an occurence list.
*/
HuffmanTree buildHuffmanTree(OccurenceList l);

/**
 * \brief a function to print a huffman tree to the console in a preorder way.
 * \param tree a huffman tree.
*/
void printHuffmanTreePreorder(HuffmanTree tree);

/**
 * \brief a function to print a huffman tree.
 * \param tree a huffman tree.
*/
void printHuffmanTree(HuffmanTree tree);

/**
 * \brief a function to destroy and free the memory of a huffman tree.
 * \param tree a huffman tree.
*/
void freeHuffmanTree(HuffmanTree tree);

/**
 * \brief a function that returns the height of a huffman tree.
 * \param tree a huffman tree.
*/
int getHuffmanTreeHeight(HuffmanTree tree);

/**
 * \brief a function that returns the number of leafs in a huffman tree.
 * \param tree a huffman tree.
*/
int getHuffmanTreeLeafCount(HuffmanTree tree);

/**
 * \brief a function to destroy and free the memory of a list of nodes.
 * \param list a list of nodes.
*/
void freeNodeLinkedList(NodeLinkedList list);

/**
* \typedef struct NodeStack
* \brief a Stack of nodes.
*/
typedef struct NodeStack
{
    NodeLinkedList nodes;
} NodeStack;

/**
 * \brief a function to create a node stack.
*/
NodeStack* createNodeStack();

/**
 * \brief a function to destroy and free the memory of a node stack.
 * \param s a node stack.
*/
void freeNodeStack(NodeStack* s);

/**
 * \brief a function that returns 1 if the stack is empty, 0 otherwise.
 * \param s a stack of nodes.
*/
int isNodeStackEmpty(NodeStack* s);

/**
 * \brief a function to push a node in a node stack.
 * \param s a node stack.
 * \param node a node.
*/
void nodeStackPush(NodeStack* s, Node* node);

/**
 * \brief a function to a node stack, returns a node.
 * \param s a node stack.
*/
Node* nodeStackPop(NodeStack* s);




#endif
