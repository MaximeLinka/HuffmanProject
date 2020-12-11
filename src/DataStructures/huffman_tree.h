#include <stdlib.h>
#include "DataStructures/linkedlist.h"
#include "DataStructures/stack.h"

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

typedef struct Node 
{
    int occurences;
    char character;
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


Node* createNode(int value, char c);
Node* createLink(Node* current_node, Node* leaf);  //creates parent to two leaves with sum of occurences as 'occurences' and '\0' as character
NodeLinkedList occurenceListToNodeList(OccurenceList l);
HuffmanTree buildHuffmanTree(OccurenceList l);

void printHuffmanTreePreorder(HuffmanTree tree);
void printHuffmanTree(HuffmanTree tree);
void freeHuffmanTree(HuffmanTree tree);

void freeNodeLinkedList(NodeLinkedList list);

void list_read_backwards(Element* l, FILE* dico);
void read_tree_dico(Node* tree, char* name_file, Stack* s, int index, FILE* dico);




#endif
