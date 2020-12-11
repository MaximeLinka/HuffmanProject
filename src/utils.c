#include "utils.h"

#include <stdlib.h>
#include <string.h>

char* readFile(const char* filepath)
{
	FILE* file = fopen(filepath, "rb");
	if (file == NULL)
	{
		printf("Could not open file : %s", filepath);
		fclose(file);
		return NULL;
	}

	fseek(file, 0, SEEK_END);
	long length = ftell(file);
	fseek(file, 0, SEEK_SET);

	char* result = (char*)malloc(sizeof(char) * (length + 1));
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
	printf("%p", file);
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

int getFileLineCount(const char* filepath)
{
	/* Notes :
	 * This function returns the number of lines.
	 * If file is empty, the function returns 0.
	*/

	FILE* file = fopen(filepath, "r");
	if (file == NULL)
	{
		printf("Could not open file : %s", filepath);
		fclose(file);
		return -1;
	}

	int lines = 0;
	int ch;

	while (!feof(file))
	{
		ch = fgetc(file);
		if (ch == '\n')
		{
			lines++;
		}
	}

	fclose(file);
	return lines;
}

char* findBinary(Dictionnary dict, char c)
{
	DicoElement* temp = dict;
	while (temp != NULL && temp->character != c)
	{
		temp = temp->next;
	}
	if (temp == NULL) return NULL;
	else return temp->binary;
}

size_t findLengthEncoding(Dictionnary dictionnary, char* string)
{
	size_t length = 0;
	char* character_bits;
	int i = 0;

	while (string[i] != '\0')
	{
		character_bits = findBinary(dictionnary, string[i]);
		length = length + strlen(character_bits);
		i++;
	}

	//free(character_bits);
	return length;
}

char* encodeTextWithDictionary(Dictionnary dictionnary, char* string)
{
	/* Notes :
	 * This function translates a text into a binary sequence based on the Huffman dictionary.
	*/

	size_t encoded_size = findLengthEncoding(dictionnary, string);
	char* encoded_text = (char*)malloc(sizeof(char) * encoded_size); 
	char* character_bits;
	int string_index = 0;
	int encoding_index = 0;
 
	while (string[string_index] != '\0')
	{
		character_bits = findBinary(dictionnary, string[string_index]);
		int k = 0;
		while (character_bits[k] != '\0')
		{
			encoded_text[encoding_index] = character_bits[k];
			encoding_index++;
			k++;
		}
		string_index++;
	}

	encoded_text[encoding_index] = '\0';

	//free(character_bits);
	return encoded_text;
}

char* encodeText(char* string)
{
	// - build occurence list
	// - build huffman tree
	// - create Dictionary
	// 
}

int compressFile(const char* input, const char* output)
{
	char* file_content = readFile(input);

	// encode text
	// write encode text to file
}