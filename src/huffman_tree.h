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

typedef struct Stack
{
    List values_of_stack;
}Stack;

Node* create_node(int val, char letter);
Node* create_link(Node* current_node, Node* leaf);//creates parent to two leaves with sum of occurences as 'occurences' and '\0' as character
Node* convert_list_to_tree(Element* l, int occurences);
listNode* convert_list_to_listofnodes(Element* l);

void print_tree(Node* tree);

void free_list_node(listNode* node);
void free_tree(Node* tree);

Stack* create_stack();
int is_empty(Stack* s);
void push(Stack* s, int val);
int pop(Stack* s);

void list_read_backwards(Element* l, FILE* dico);
void read_tree_dico(Node* tree, char* name_file, Stack* s, int index);//function that create the dictionnary in .txt