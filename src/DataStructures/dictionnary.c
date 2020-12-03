#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionnary.h"
#include "utils.h"

DicoElement* createDicoElement(char character, char* binary)
{
	DicoElement* new_e = (DicoElement*)malloc(sizeof(DicoElement));
	new_e->character = character;
	new_e->binary = binary;
	new_e->next = NULL;
	return new_e;
}

void freeDictionnary(Dictionnary dictionnary)
{
	while (dictionnary != NULL)
	{
		DicoElement* old = dictionnary;
		dictionnary = dictionnary->next;
		free(old);
	}
}

void printDictionnary(Dictionnary dictionnary)
{
	DicoElement* temp = dictionnary;
	while (temp != NULL)
	{
		printf("\'%c\' : %s\n", temp->character, temp->binary); 
		temp = temp->next;
	}
}

Dictionnary buildDictionnary(HuffmanTree tree)
{
	//MAXENCE TU DOIS FAIRE CETTE FONCTION
}

Dictionnary readDictionnary(const char* filepath)
{
	char* file_content = readFile(filepath);
	//char test[2] = "0\0";
	Dictionnary dictionnary = (Dictionnary)createDicoElement(file_content[0], "0\0");
	Dictionnary temp = dictionnary;

	size_t file_index = 7;
	while (file_content[file_index] != '\0')
	{
		
		char c = file_content[file_index];
		file_index += 4; // jump to the first bit of binary translation of the character

		size_t binary_index = file_index; // record the index of the first bit of binary sequence
		
		while (file_content[file_index] != '\n') // search for end of binary sequence ('\n')
			file_index++;

		char* binary = malloc(sizeof(char) * (file_index - binary_index + 1));
		strncpy(binary, &file_content[binary_index], file_index - binary_index);
		binary[file_index - binary_index] = '\0';
		
		DicoElement* new_e = createDicoElement(c, binary);
		temp->next = new_e;
		temp = temp->next;

		file_index += 1; // jump to the next character (next line)
	}

	return dictionnary;
}