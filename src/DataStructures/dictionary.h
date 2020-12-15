/*****************************************************************//**
* \file dictionary.h
* \brief Header of the library containing the huffman dictionary.
*********************************************************************/


#include "huffman_tree.h"

#ifndef DICTIONNARY_H
#define DICTIONNARY_H

/**
* \typedef struct DicoElement
* \brief a LinkedList that represent the Huffman dictionary.
*/
typedef struct DicoElement
{
	char character;
	char* binary;
	struct DicoElement* next;
} DicoElement;

/**
* \typedef Dictionary
* \brief a nickname for DicoElement*.
*/
typedef DicoElement* Dictionary;

/**
 * \brief a function to create a dictionary.
 * \param character a character.
 * \param binary a string representing the binary of a character.
*/
DicoElement* createDicoElement(char character, char* binary);

/**
 * \brief a function to drestroy and free the memory of a Dictionary.
 * \param dictionary the dictionary to destroy.
*/
void freeDictionary(Dictionary dictionnary);

/**
 * \brief a function to print the content of a dictionary.
 * \param dictionary a dictionary.
*/
void printDictionary(Dictionary dictionnary);

/**
 * \brief a function to create a huffman dictionary from the huffman tree.
 * \param tree a huffman tree.
*/
Dictionary buildDictionary(HuffmanTree tree);

/**
 * \brief a function to store a dictionary in a txt file.
 * \param dictionary a dictionary.
 * \param filepath a string representing the file path.
*/
void serializeDictionary(Dictionary dico, const char* filepath);

/**
 * \brief a function to store a dictionary in a txt file.
 * \param dictionary a dictionary.
 * \param filepath a string representing the file path.
*/
void storeDictionary(HuffmanTree tree, const char* filepath);

/**
 * \brief a function to read a dictionary from a txt file.
 * \param filepath a string representing the file path.
*/
Dictionary readDictionary(const char* filepath);

#endif