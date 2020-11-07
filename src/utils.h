#include <stdio.h>

#ifndef UTILS_H
#define UTILS_H


char* readFile(const char* filepath);
int writeStringToFile(const char* filepath, char* string, size_t strlength);


char* charToBinary(char c);
char* stringToBinary(char* string);

void stringFileToBinary(const char* file_in, const char* file_out);

int getFileLength(const char* filepath);

#endif

