/*****************************************************************//**
* \file linkedlist.h
* \brief Header of the library containing the Occurence List.
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/**
* \typedef struct Element
* \brief a linked list element.
*/
typedef struct Element
{
	char character;
	size_t occurences;
	struct Element* next;
} Element;

/**
* \typedef OccurenceList
* \brief a nickname for Element*.
*/
typedef Element* OccurenceList;

/**
 * \brief a function to create an element.
 * \param c a character.
*/
Element* createElement(char c);

/**
 * \brief a function to destroy and free the memory of an occurence list.
 * \param l an occurence list.
*/
void freeOccurenceList(OccurenceList l);

/**
 * \brief a function to print the content of an occurence list.
 * \param l an occurence list.
*/
void printOccurenceList(OccurenceList l);

/**
 * \brief a function that returns 0 if the character is not in the occurence list, 1 if it is.
 * \param l an occurence list.
 * \param c a character.
*/
int containsElement(OccurenceList l, char c);

/**
 * \brief a function that returns the size of an occurence list.
 * \param l an occurence list.
*/
int getOccurenceListSize(OccurenceList l);

/**
 * \brief a function that returns the sum of all occurences in an occurence list.
 * \param l an occurence list.
*/
int getOccurenceListSum(OccurenceList l);

/**
 * \brief a function that adds a character in an occurence list, the occurence of that character is set to 1.
 * \param l an occurence list.
 * \param c a character.
*/
void appendOccurenceList(OccurenceList* l, char c);

/**
 * \brief a function that removes a character from an occurence list.
 * \param l an occurence list.
 * \param c a character.
*/
void removeElement(OccurenceList l, char c);
/**
 * \brief a function that sorts an occurence list by occurence and in a descendant manner.
 * \param l an occurence list.
*/
void sortOccurenceListByOccurenceDescendent(OccurenceList* l);

/**
 * \brief a function that checks if an occurence list is sorted.
 * \param l an occurence list.
*/
int isOccurenceListSorted(OccurenceList l);

/**
 * \brief a function that returns the minimum of an occurence list.
 * \param l an occurence list.
*/
Element* minOccurenceList(OccurenceList l);

/**
 * \brief a function that creates an occurence list from a string.
 * \param string an array of characters (string).
*/
OccurenceList createOccurenceList(char* string); // Answers Part 2 - Question C

void remove_list(Element** l, Element* disposable);

#endif