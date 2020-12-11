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

typedef Element* OccurenceList;


// Basic functions
Element* createElement(char c);
void freeOccurenceList(OccurenceList l);
void printOccurenceList(OccurenceList l);

int containsElement(OccurenceList l, char c);

int getOccurenceListSize(OccurenceList l);
int getOccurenceListSum(OccurenceList l);

void appendOccurenceList(OccurenceList* l, char c);
void removeElement(OccurenceList l, char c);

void sortOccurenceListByOccurenceDescendent(OccurenceList* l);
int isOccurenceListSorted(OccurenceList l);

Element* minOccurenceList(OccurenceList l);

// Specific functions
OccurenceList createOccurenceList(char* string); // Answers Part 2 - Question C
void remove_list(Element** l, Element* disposable);
//create a list of occurence
//an array of nodes vs linked list of nodes 
#endif