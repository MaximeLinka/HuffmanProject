#include <stdlib.h>
#include "DataStructures/linkedlist.h"
#include "DataStructures/stack.h"

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

typedef struct Node 
{
    int occurence;
    char letter;
    struct Node* left;
    struct Node* right;
} Node;

typedef Node* HuffmanTree;


typedef struct NodeElement
{
    Node* data;
    struct NodeElement* next;
} NodeElement;

typedef NodeElement* NodeLinkedList;


Node* createNode(int value, char letter);
Node* createLink(Node* current_node, Node* leaf);  //creates parent to two leaves with sum of occurences as 'occurences' and '\0' as character
NodeLinkedList occurenceListToNodeList(LinkedList l);
HuffmanTree buildHuffmanTree(LinkedList l, int occurences);

void printHuffmanTree(Node* tree);
void freeHuffmanTree(Node* tree);

void freeNodeLinkedList(NodeLinkedList list);

void list_read_backwards(Element* l, FILE* dico);
void read_tree_dico(Node* tree, char* name_file, Stack* s, int index, FILE* dico);

#endif
