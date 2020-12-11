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

int getHuffmanTreeHeight(HuffmanTree tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        int left_depth = getHuffmanTreeHeight(tree->left);
        int right_depth = getHuffmanTreeHeight(tree->right);

        if (left_depth > right_depth) return left_depth + 1;
        else return right_depth + 1;
    }
}

int getHuffmanTreeLeafCount(HuffmanTree tree)
{
    if (tree != NULL)
    {
        if (tree->character != '\0')
        {
            return getHuffmanTreeLeafCount(tree->left) + getHuffmanTreeLeafCount(tree->right) + 1;
        }
        else
            return 0;
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

NodeStack* createNodeStack()
{
    NodeStack* new_stack = (NodeStack*)malloc(sizeof(NodeStack));
    new_stack->nodes = NULL;
    return new_stack;
}

void freeNodeStack(NodeStack* s)
{
    freeNodeLinkedList(s->nodes);
}

int isNodeStackEmpty(NodeStack* s)
{
    return (s->nodes == NULL);
}

void nodeStackPush(NodeStack* s, Node* node)
{
    NodeElement* e = (NodeElement*)malloc(sizeof(NodeElement));
    e->data = node;
    e->next = s->nodes;
    s->nodes = e;
}

Node* nodeStackPop(NodeStack* s)
{
    if (isNodeStackEmpty(s)) {
        return NULL;
    }
    else {
        NodeElement* old = s->nodes;
        s->nodes = s->nodes->next;
        Node* temp = old->data;
        free(old);
        return temp;
    }
}






