/*****************************************************************//**
* \file coding.h
* \brief Header of the library containing some huffman coding functions.
*********************************************************************/

#include "DataStructures/dictionary.h"

#ifndef CODING_H
#define CODING_H

/**
 * \brief a function that converts a string into its huffman code and writes the dictionary to the given filepath.
 * \param string an array of characters.
 * \param dicopath a string representing the path for the dicionary to be written.
*/
char* encodeText(char* string, const char* dicopath);

/**
 * \brief a function that compresses a file using the huffman coding technique.
 * \param input the path to the input file.
 * \param output the path to the output file.
 * \param dico the path to the dictionary file.
*/
void compressFile(const char* input, const char* output, const char* dico);

#endif
