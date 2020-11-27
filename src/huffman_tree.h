#include <stdlib.h>
#include "linkedlist.h"


typedef struct Node {
    int occurence;
    char letter;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct listNode {
    Node *  node;
    struct listNode* next;
} listNode;

Node* create_node(int val, char letter);
Node* create_link(Node* current_node, Node* leaf);//creates parent to two leaves with sum of occurences as 'occurences' and '\0' as character
Node* convert_list_to_tree(Element* l, int occurences);
listNode* convert_list_to_listofnodes(Element* l);

void print_tree(Node* tree);

void free_list_node(listNode* node);
void free_tree(Node* tree);