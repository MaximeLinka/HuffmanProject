#include <stdio.h>
#include <string.h>

#include "linkedlist.h"

Element* createElement(char c)
{
	Element* e = (Element*)malloc(sizeof(Element));
	e->character = c;
	e->occurences = 1;
	e->next = NULL;
	return e;
}

void freeOccurenceList(OccurenceList l)
{
	while (l != NULL)
	{
		OccurenceList old = l;
		l = l->next;
		free(old);
	}
}

void printOccurenceList(OccurenceList l)
{
	OccurenceList temp = l;
	while (temp != NULL)
	{
		printf("(\'%c\', %d) -> ", temp->character, temp->occurences);
		temp = temp->next;
	}
	puts("NULL");
}

int containsElement(OccurenceList l, char c)
{
	OccurenceList temp = l;

	while (temp != NULL)
	{
		if (temp->character == c) return 1;
		temp = temp->next;
	}
	return 0;
}

int getOccurenceListSize(OccurenceList l)
{
	Element* temp = l;
	int length = 0;
	while (temp != NULL)
	{
		length++;
		temp = temp->next;
	}

	return length;
}

int getOccurenceListSum(OccurenceList l)
{
	Element* temp = l;
	int sum = 0;
	while (temp != NULL)
	{
		sum += temp->occurences;
		temp = temp->next;
	}

	return sum;
}

void appendOccurenceList(OccurenceList* l, char c)
{
	if (*l != NULL)
	{
		OccurenceList temp = *l;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		//Element* new_e = createElement(c);
		temp->next = createElement(c);
	}
}

void removeElement(OccurenceList l, char c);

void sortOccurenceListByOccurenceDescendent(OccurenceList* l)
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

int isOccurenceListSorted(OccurenceList l)
{
	if (l == NULL) return 1;

	Element* temp = l;
	while (temp->next != NULL)
	{
		if (temp->occurences < temp->next->occurences)
			return 0;
		temp = temp->next;
	}
	return 1;
}

Element* minOccurenceList(OccurenceList l)
{
	OccurenceList min = l;
	OccurenceList temp = l;

	while (temp != NULL)
	{
		if (temp->occurences < min->occurences)
			min = temp;
		temp = temp->next;
	}
	return min;
}


// Specific functions
Element* createOccurenceList(char* string)
{
	Element* map = createElement(string[0]);
	size_t strlength = strlen(string);

	int c;
	for (c = 1; c < strlength; c++)
	{
		Element* temp = map;
		int found = 0;

		while (temp != NULL)
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
			appendOccurenceList(&map, string[c]);
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






