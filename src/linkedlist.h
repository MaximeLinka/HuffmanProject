#include <stdio.h>
#include <stdlib.h>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Element
{
	char character;
	size_t occurences;
	struct Element* next;
} Element;

typedef Element* List;


// Basic functions
Element* createElement(char c);
void freeElement(Element* e);
void printElement(Element* e);

int containsElement(Element* e, char c);

void appendElement(Element** e, char c);
void removeElement(char c);

void sortElementByOccurenceDescendent(Element** e);

Element* minElement(Element* e);

// Specific functions
Element* createOccurenceList(char* string, size_t strlength); // Answers Part 2 - Question C
void remove_list(Element** l, Element* disposable);

#endif