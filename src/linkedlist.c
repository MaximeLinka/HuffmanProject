#include <stdio.h>

#include "linkedlist.h"

Element* createElement(char c)
{
	Element* e = (Element*)malloc(sizeof(Element));
	e->character = c;
	e->occurences = 1;
	e->next = NULL;
	return e;
}

void freeElement(Element* e)
{
	while (e != NULL)
	{
		Element* old = e;
		e = e->next;
		free(old);
	}
}

void printElement(Element* e)
{
	Element* temp = e;
	while (temp != NULL)
	{
		printf("(\'%c\', %d) -> ", temp->character, temp->occurences);
		temp = temp->next;
	}
	puts("NULL");
}

int containsElement(Element* e, char c)
{
	Element* temp = e;

	while (temp != NULL)
	{
		if (temp->character == c) return 1;
		temp = temp->next;
	}
	return 0;
}

void appendElement(Element** e, char c)
{
	Element* temp = *e;
	while (temp != NULL)
	{
		temp = temp->next;
	}

	Element* new_e = createElement(c);
	temp->next = new_e;
}

void removeElement(char c);

void sortElementByOccurenceDescendent(Element** e)
{
	Element* temp1 = *e;

	while(temp1 != NULL)
	{
		Element* temp2 = temp1->next;
		while (temp2 != NULL)
		{
			if (temp1->occurences < temp2->occurences)
			{
				// swap
				char temp_char = temp1->character;
				size_t temp_occurences = temp1->occurences;
				temp1->character = temp2->character;
				temp1->occurences = temp2->occurences;
				temp2->character = temp_char;
				temp2->occurences = temp_occurences;
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}

// Specific functions
Element* createOccurenceList(char* string, size_t strlength) //TODO: remove strlength from api
{
	Element* map = createElement(string[0]);

	int c;
	for (c = 1; c < strlength; c++)
	{
		Element* temp = map;
		int found = 0;
		while (temp->next != NULL)
		{
			if (temp->character == string[c])
			{
				temp->occurences++;
				found = 1;
			}
			temp = temp->next;
		}

		if (!found)
		{
			Element* new_e = createElement(string[c]);
			temp->next = new_e;
		}
	}

	return map;
}
