#include <stdlib.h>
#include <string.h>
#include "utils.h"

#define INPUT_FILE "assets/input.txt"
#define OUTPUT_FILE "assets/output.txt"

int main()
{
	puts("Hello Huffman !");

	stringFileToBinary(INPUT_FILE, OUTPUT_FILE);

	puts("The transfer was successfull !");

	printf("The input file was %d characters large.\n", getFileLength(INPUT_FILE));
	printf("The output file was %d characters large.\n", getFileLength(OUTPUT_FILE));


	return 0;
}