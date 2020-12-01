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

typedef Element* LinkedList;


// Basic functions
Element* createElement(char c);
void freeLinkedList(LinkedList l);
void printLinkedList(LinkedList l);

int containsElement(LinkedList l, char c);

void appendLinkedList(LinkedList* l, char c);
void removeElement(LinkedList l, char c);

void sortLinkedListByOccurenceDescendent(LinkedList* e);

Element* minLinkedList(LinkedList l);

// Specific functions
LinkedList createOccurenceList(char* string, size_t strlength); // Answers Part 2 - Question C
void remove_list(Element** l, Element* disposable);

#endif