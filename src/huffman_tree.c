#include "huffman_tree.h"




Node* create_node(int val, char letter) {
    Node* tree = (Node*)malloc(sizeof(Node));
    tree->occurence = val;
    tree->left = NULL;
    tree->right = NULL;
    tree->letter = letter;
    return tree;
}

Node* create_link(Node* current_node, Node * leaf)//right - left
{
    Node* temp = create_node(current_node->occurence + leaf->occurence, '\0');
    temp->left = leaf;
    temp->right = current_node;
    return temp;
}

void print_tree(Node * tree) {
    if (tree != NULL) {
        printf("%d : %c \n", tree->occurence, tree->letter);
        print_tree(tree->left);
        print_tree(tree->right);
    }
}

void free_tree(Node* tree) {
    if (tree != NULL)
    {
        free_tree(tree->left);
        free_tree(tree->right);
        free(tree);
    }


}


listNode* convert_list_to_listofnodes(Element* l)
{
    Element* temp = minElement(l);
    listNode* tree = (listNode*)malloc(sizeof(listNode));
    tree->node = create_node(temp->occurences, temp->character);
    listNode* temp_node = tree;
    remove_list(&l, temp);
    temp = minElement(l);
    while (temp)
    {
        temp_node->next = (listNode*)malloc(sizeof(listNode));
        temp_node->next->node = create_node(temp->occurences, temp->character);
        remove_list(&l, temp);
        temp = minElement(l);
        temp_node = temp_node->next;
    }
    temp_node->next = NULL;
    return tree;
}
void free_list_node(listNode * node)
{
    listNode* old = node;
    while (node != NULL)
    {
        old = node;
        node = node->next;
        free(old);
    }
}

Node* convert_list_to_tree(Element* l, int occurences)
{
    
    Node* tree = NULL;
    Node* current_node = NULL;
    listNode* temp = convert_list_to_listofnodes(l);//organizes list into list of nodes
    if (temp != NULL)
    {
        if (temp->next == NULL)//case where we have one node
        {
            tree = create_node(temp->node->occurence, '\0');
            tree->left = temp->node;

        }
        else
        {
            current_node = create_link(temp->node, temp->next->node);
            temp = temp->next->next;
        }

    }
    while (temp != NULL)
    {
        current_node = create_link(current_node, temp->node);
        temp = temp->next;
    }
    tree = current_node;
    free_list_node(temp);
    return tree;
}

Stack* create_stack() {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->values_of_stack = NULL;
    return newStack;
}

int is_empty(Stack* s)
{
    if (s->values_of_stack == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

void push(Stack* s, int val) {
    List element = (List)malloc(sizeof(Element));
    element->occurences = val;
    element->character = '\0';
    element->next = s->values_of_stack;
    s->values_of_stack = element;
}

int pop(Stack* s) {
    if (is_empty(s) == 1) {
        return -1;
    }
    else {
        Element* old = s->values_of_stack;
        s->values_of_stack = s->values_of_stack->next;
        int temp = old->occurences;
        free(old);
        return temp;
    }
}


void list_read_backwards(Element* l, FILE* dico) {
    if (l != NULL) {
        list_read_backwards(l->next, dico);
        fprintf(dico, "%d", l->occurences);
    }
}

void read_tree_dico(Node* tree, char* name_file, Stack* s, int index)
{
    if (index == 0 || index == 1)//the way to access info gives the bits associated
    {
        push(s, index);
    }
    if (tree->left == NULL && tree->right == NULL)//if we have a leaf
    {
        if (tree->letter != '\0')//the leaf must have a letter
        {
            FILE* dico = fopen(name_file, "a+");
            Element* temp = s->values_of_stack;
            int delete = pop(s);
            fprintf(dico, "%c : ", tree->letter);
            list_read_backwards(temp, dico);
            fprintf(dico, "\n");
        }
    }
    else {
        read_tree_dico(tree->left, name_file, s, 0);
        read_tree_dico(tree->right, name_file, s, 1);
    }
}