#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionnary.h"
#include "huffman_tree.h"
#include "stack.h"
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

void storeDictionnary(HuffmanTree tree, const char* filepath)
{
	FILE* file = fopen(filepath, "w");
	if (file == NULL)
	{
		printf("Could not open file : %s", filepath);
		fclose(file);
		return;
	}

	Dictionnary dico = createDicoElement('\0', "\0");
	Dictionnary temp = dico;

	int length = getHuffmanTreeLeafCount(tree);
	char* array = (char*)malloc(sizeof(char) * 200);
	int index = 0;

	if (tree != NULL)
	{
		NodeStack* stack = createNodeStack();
		Stack* binary_stack = createStack();
		nodeStackPush(stack, tree);
		stackPush(binary_stack, 1);

		while (!isNodeStackEmpty(stack))
		{
			Node* node = nodeStackPop(stack);
			int left = stackPop(binary_stack);

			if (node->right != NULL)
			{
				nodeStackPush(stack, node->right);
				stackPush(binary_stack, 0);
			}

			if (node->left != NULL)
			{
				nodeStackPush(stack, node->left);
				stackPush(binary_stack, 1);
			}
			
			if (node->character == '\0')
			{
				if (left == 1) // means we're on a left node
				{
					array[index] = '0';
					index++;
				}
				else if (left == 0) // means we're on a right node
				{
					array[index] = '1';
					index++;
				}
				array[index] = '\0';
			}
			else
			{
				char* copy = (char*)malloc(sizeof(char) * strlen(array));
				strcpy(copy, array);
				temp->next = createDicoElement(node->character, _strrev(copy));
				temp = temp->next;

				fprintf(file, "%c:%s\n", node->character, _strrev(array));
				_strrev(array);
			}
		}

		freeNodeStack(stack);
		freeStack(binary_stack);
		free(array);
	}

	int l = strlen(temp->binary);
	temp->binary[l-1] = '1';
	printDictionnary(dico->next);

	fclose(file);
}

Dictionnary readDictionnary(const char* filepath)
{
	char* file_content = readFile(filepath);

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
		binary[file_index - binary_index - 1] = '\0';
		
		DicoElement* new_e = createDicoElement(c, binary);
		temp->next = new_e;
		temp = temp->next;

		file_index += 1; // jump to the next character (next line)
	}

	return dictionnary;
}