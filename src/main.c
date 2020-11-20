#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "linkedlist.h"
#include "huffman_tree.h"

#define INPUT_FILE "assets/input.txt"
#define OUTPUT_FILE "assets/output.txt"

int main()
{
	puts("Hello Huffman !");

	stringFileToBinary(INPUT_FILE, OUTPUT_FILE);
	puts("The transfer was successfull !");

	printf("The input file was %d characters large.\n", getFileLength(INPUT_FILE));
	printf("The output file was %d characters large.\n", getFileLength(OUTPUT_FILE));

	Element* list = createOccurenceList("bonsoir mdrr", 12);
	printElement(list);

	puts("After sorting !");

	sortElementByOccurenceDescendent(&list);
	printElement(list);

	freeElement(list);

	return 0;
}