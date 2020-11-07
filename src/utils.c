#include "utils.h"

#include <stdlib.h>
#include <string.h>

char* readFile(const char* filepath)
{
	FILE* file = fopen(filepath, "r");
	if (file == NULL)
	{
		printf("Could not open file : %s", filepath);
		fclose(file);
		return NULL;
	}

	fseek(file, 0, SEEK_END);
	long length = ftell(file);
	fseek(file, 0, SEEK_SET);

	char* result = (char*)malloc(length + 1);
	fread(result, 1, length, file);

	result[length] = '\0';

	fclose(file);

	return result;
}

int writeStringToFile(const char* filepath, char* string, size_t strlength)
{
	/* Notes :
	 * This function erases the content of the file and then writes the string in it.
	 * This function returns the number of bytes that were written.
	*/ 

	FILE* file = fopen(filepath, "w");
	if (file == NULL)
	{
		printf("Could not open file : %s", filepath);
		fclose(file);
		return 0;
	}

	size_t written = fwrite(string, 1, strlength, file);

	fclose(file);
	return written;
}

char* charToBinary(char c)
{
	char* buffer = (char*)malloc(sizeof(char) * 9);

	for (int i = 7; i >= 0; i--)
	{
		buffer[i] = ((c >> i) & 1) ? '1' : '0';
	}
	buffer[8] = '\0';
	return buffer;
}

char* stringToBinary(char* string)
{
	size_t length = strlen(string);
	char* buffer = (char*)malloc(sizeof(char) * length * 8 + 1);

	size_t c, cpt = 0;
	for (c = 0; c < length; c++)
	{
		int i;
		for (i = 7; i >= 0; i--)
		{
			buffer[cpt] = ((string[c] >> i) & 1) ? '1' : '0';
			cpt++;
		}
	}

	buffer[cpt] = '\0';
	return buffer;
}

void stringFileToBinary(const char* file_in, const char* file_out)
{
	/* Function to answer Part 1 - Question A
	*/

	char* buffer = readFile(file_in);
	char* binary = stringToBinary(buffer);

	writeStringToFile(file_out, binary, strlen(binary));

	free(buffer);
	free(binary);
}

int getFileLength(const char* filepath)
{
	/* Notes :
	 * This function returns -1 if there are any errors, the number of characters in the file otherwise.
	*/

	FILE* file = fopen(filepath, "r");

	if (file == NULL)
	{
		printf("Could not open file : %s", filepath);
		fclose(file);
		return -1;
	}

	fseek(file, 0, SEEK_END);
	int length = ftell(file);

	fclose(file);
	return length;
}
