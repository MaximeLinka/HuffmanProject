#include "stack.h"

Stack* createStack()
{
    Stack* new_stack = (Stack*)malloc(sizeof(Stack));
    new_stack->values = NULL;
    return new_stack;
}

int isStackEmpty(Stack* s)
{
    return (s->values == NULL);
}


void stackPush(Stack* s, int value)
{
    Element* e = (Element*)malloc(sizeof(Element));
    e->occurences = value;
    e->character = '\0';
    e->next = s->values;
    s->values = e;
}

int stackPop(Stack* s)
{
    if (isStackEmpty(s)) {
        return -1;
    }
    else {
        Element* old = s->values;
        s->values = s->values->next;
        int temp = old->occurences;
        free(old);
        return temp;
    }
}