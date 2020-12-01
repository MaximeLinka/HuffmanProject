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

void freeLinkedList(LinkedList l)
{
	while (l != NULL)
	{
		LinkedList old = l;
		l = l->next;
		free(old);
	}
}

void printLinkedList(LinkedList l)
{
	LinkedList temp = l;
	while (temp != NULL)
	{
		printf("(\'%c\', %d) -> ", temp->character, temp->occurences);
		temp = temp->next;
	}
	puts("NULL");
}

int containsElement(LinkedList l, char c)
{
	LinkedList temp = l;

	while (temp != NULL)
	{
		if (temp->character == c) return 1;
		temp = temp->next;
	}
	return 0;
}

void appendLinkedList(LinkedList* l, char c)
{
	LinkedList temp = *l;
	while (temp != NULL)
	{
		temp = temp->next;
	}

	Element* new_e = createElement(c);
	temp->next = new_e;
}

void removeElement(LinkedList l, char c);

void sortLinkedListByOccurenceDescendent(LinkedList* l)
{
	Element* temp1 = *l;

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

Element* minLinkedList(LinkedList l)
{
	LinkedList min = l;
	LinkedList temp = l;

	while (temp != NULL)
	{
		if (temp->occurences < min->occurences)
			min = temp;
		temp = temp->next;
	}
	return min;
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

void remove_list(Element** l, Element * disposable)
{
	if ((*l)!= NULL)
	{
		Element* temp = (*l);
		Element* copy;
		if (temp == disposable)
		{
			(*l) = temp->next;
			free(temp);
		}
			
		else
		{
			while (temp->next != NULL && temp->next != disposable)
			{
				temp = temp->next;
			}
			if (temp->next == disposable)
			{
				copy = temp->next;
				temp->next = temp->next->next;
				free(copy);
			}
		}
	}
}




