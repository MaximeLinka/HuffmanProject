#include "huffman_tree.h"


Node* createNode(int value, char c) 
{
    Node* tree = (Node*)malloc(sizeof(Node));
    tree->occurences = value;
    tree->character = c;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

Node* createLink(Node* current_node, Node* leaf)   //right - left
{
    Node* temp = createNode(current_node->occurences + leaf->occurences, '\0');
    temp->left = leaf;
    temp->right = current_node;
    return temp;
}

void printHuffmanTreePreorder(HuffmanTree tree) 
{
    if (tree != NULL) 
    {
        printf("%d : \'%c\'\n", tree->occurences, tree->character);
        printHuffmanTreePreorder(tree->left);
        printHuffmanTreePreorder(tree->right);
    }
}

void freeHuffmanTree(HuffmanTree tree) 
{
    if (tree != NULL)
    {
        freeHuffmanTree(tree->left);
        freeHuffmanTree(tree->right);
        free(tree);
    }
}

NodeLinkedList occurenceListToNodeList(OccurenceList l)
{
    Element* temp = minOccurenceList(l);

    NodeLinkedList tree = (NodeLinkedList)malloc(sizeof(NodeElement));
    tree->data = createNode(temp->occurences, temp->character);

    NodeLinkedList temp_node = tree;
    remove_list(&l, temp);
    temp = minOccurenceList(l);
    
    while (temp)
    {
        temp_node->next = (NodeLinkedList)malloc(sizeof(NodeElement));
        temp_node->next->data = createNode(temp->occurences, temp->character);
        remove_list(&l, temp);
        temp = minOccurenceList(l);
        temp_node = temp_node->next;
    }

    temp_node->next = NULL;
    return tree;
}

void freeNodeLinkedList(NodeLinkedList list)
{
    NodeLinkedList old = list;
    while (list != NULL)
    {
        old = list;
        list = list->next;
        free(old);
    }
}

HuffmanTree buildHuffmanTree(OccurenceList l)
{
    HuffmanTree tree = NULL;
    Node* current_node = NULL;
    NodeLinkedList temp = occurenceListToNodeList(l); //organizes list into list of nodes

    if (temp != NULL)
    {
        if (temp->next == NULL)//case where we have one node
        {
            tree = createNode(temp->data->occurences, '\0');
            tree->left = temp->data;
        }
        else
        {
            current_node = createLink(temp->data, temp->next->data);
            temp = temp->next->next;
        }

    }

    while (temp != NULL)
    {
        current_node = createLink(current_node, temp->data);
        temp = temp->next;
    }

    tree = current_node;
    freeNodeLinkedList(temp);
    return tree;
}

void list_read_backwards(Element* l, FILE* dico) {
    if (l != NULL) {
        list_read_backwards(l->next, dico);
        fprintf(dico, "%d", l->occurences);
    }
}

void read_tree_dico(Node* tree, char* name_file, Stack* s, int index, FILE* dico)
{
    if (index == 0 || index == 1) //the way to access info gives the bits associated
    {
        stackPush(s, index);
    }
    if (tree->left == NULL && tree->right == NULL) //if we have a leaf
    {
        if (tree->character != '\0') //the leaf must have a letter
        {
            Element* temp = s->values;
            fprintf(dico, "%c : ", tree->character);
            list_read_backwards(temp, dico);
            fprintf(dico, "\n");
        }
        int delete = stackPop(s);
    }
    else {
        read_tree_dico(tree->left, name_file, s, 0,dico);
        read_tree_dico(tree->right, name_file, s, 1,dico);
    }
}