#include <stdio.h>
#include "DataStructures/dictionnary.h"

#ifndef UTILS_H
#define UTILS_H


char* readFile(const char* filepath);
int writeStringToFile(const char* filepath, char* string, size_t strlength);


char* charToBinary(char c);
char* stringToBinary(char* string);

void stringFileToBinary(const char* file_in, const char* file_out);

int getFileLength(const char* filepath);
int getFileLineCount(const char* filepath);

char* findBinary(Dictionnary dict, char c);
size_t findLengthEncoding(Dictionnary dictionnary, char* string);
char* textEncoding(Dictionnary dictionnary, char* string);

char* encodeText(char* string);
int compressFile(const char* input, const char* output);

#endif

