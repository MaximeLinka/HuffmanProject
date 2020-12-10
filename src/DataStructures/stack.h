#include "linkedlist.h"

#ifndef STACK_H
#define STACK_H

typedef struct Stack
{
    OccurenceList values;
}Stack;


Stack* createStack();
int isStackEmpty(Stack* s);
void stackPush(Stack* s, int value);
int stackPop(Stack* s);

#endif
