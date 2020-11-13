#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int occurence;
    char letter;
    struct Node* left;
    struct Node* right;
} Node;