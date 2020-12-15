/*****************************************************************//**
* \file stack.h
* \brief Header of the library containing the stack.
*********************************************************************/


#include "linkedlist.h"

#ifndef STACK_H
#define STACK_H

/**
* \typedef struct Stack
* \brief a stack of int.
*/
typedef struct Stack
{
    OccurenceList values;
}Stack;

/**
 * \brief a function to create a Stack.
*/
Stack* createStack();

/**
 * \brief a function to destroy and free the memory of a stack.
 * \param s a stack.
*/
void freeStack(Stack* s);

/**
 * \brief a function that returs 1 if the stack is empty and 1 otherwise.
 * \param s a stack.
*/
int isStackEmpty(Stack* s);

/**
 * \brief a function that pushes an int into a stack.
 * \param s a stack.
 * \param value an int.
*/
void stackPush(Stack* s, int value);

/**
 * \brief a function that pops a stack, it returns an int.
 * \param s a stack.
*/
int stackPop(Stack* s);


#endif
