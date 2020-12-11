#include "huffman_tree.h"

#ifndef DICTIONNARY_H
#define DICTIONNARY_H


typedef struct DicoElement
{
	char character;
	char* binary;
	struct DicoElement* next;
} DicoElement;

typedef DicoElement* Dictionary;

DicoElement* createDicoElement(char character, char* binary);
void freeDictionary(Dictionary dictionnary);
void printDictionary(Dictionary dictionnary);

Dictionary buildDictionary(HuffmanTree tree);
void serializeDictionary(Dictionary dico, const char* filepath);

void storeDictionary(HuffmanTree tree, const char* filepath);

Dictionary readDictionary(const char* filepath);

#endif