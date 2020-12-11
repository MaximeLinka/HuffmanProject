#include "huffman_tree.h"

#ifndef DICTIONNARY_H
#define DICTIONNARY_H


typedef struct DicoElement
{
	char character;
	char* binary;
	struct DicoElement* next;
} DicoElement;

typedef DicoElement* Dictionnary;

DicoElement* createDicoElement(char character, char* binary);
void freeDictionnary(Dictionnary dictionnary);
void printDictionnary(Dictionnary dictionnary);

void storeDictionnary(HuffmanTree tree, const char* filepath);

Dictionnary readDictionnary(const char* filepath);

#endif