/*****************************************************************//**
* \file utils.h
* \brief Header of the library containing some useful functions throughout the whole project.
*********************************************************************/

#include <stdio.h>
#include "DataStructures/dictionary.h"

#ifndef UTILS_H
#define UTILS_H

/**
 * \brief a function to read the content of a file and return it as a string.
 * \param filepath the path to the file.
*/
char* readFile(const char* filepath);

/**
 * \brief a function to write a string to a file.
 * \param filepath the path to the file.
 * \param string the string to write.
 * \param strlength the length of the string.
*/
int writeStringToFile(const char* filepath, char* string, size_t strlength);

/**
 * \brief a function convert a character to its binary representation.
 * \param c the character.
*/
char* charToBinary(char c);

/**
 * \brief a function convert a whole string into its binary representation.
 * \param string the array of characters.
*/
char* stringToBinary(char* string);

/**
 * \brief a function that converts a file into its binary representation.
 * \param file_in the path to the input file.
 * \param file_out the path to the output file.
*/
void stringFileToBinary(const char* file_in, const char* file_out);

/**
 * \brief a function that returns the lenght of a file.
 * \param filepath the path to the file.
*/
int getFileLength(const char* filepath);

/**
 * \brief a function that returns the number of lines in a file.
 * \param filepath the path to the file.
*/
int getFileLineCount(const char* filepath);

/**
 * \brief a function that searches the binary representation of a character in a dictionary.
 * \param dict a dictionary.
 * \param c a character.
*/
char* findBinary(Dictionary dict, char c);


size_t findLengthEncoding(Dictionary Dictionary, char* string);

/**
 * \brief a function that encodes a string using a dictionary.
 * \param string an array of characters.
*/
char* encodeTextWithDictionary(Dictionary Dictionary, char* string);


#endif

