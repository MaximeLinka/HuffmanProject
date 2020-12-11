#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "DataStructures/linkedlist.h"
#include "DataStructures/huffman_tree.h"
#include "DataStructures/dictionnary.h"
#include "DataStructures/avl.h"
#include "debug.h"


#include "Tests/test.h"

#define INPUT_FILE "assets/input.txt"
#define OUTPUT_FILE "assets/output.txt"
#define DICO_FILE "assets/dico.txt"
#define TEST_FILE "assets/test.txt"

/* TODO
 * - redo maxence's work
 * - fix problem of fopen in release mode
 * - refactor linkedlist files to occurence_list
*/

int main()
{
	puts("Hello Huffman !");

	// TESTING CHAR TO BINARY CONVERSION
	stringFileToBinary(INPUT_FILE, OUTPUT_FILE);
	puts("The transfer was successfull !");

	printf("The input file was %d characters large.\n", getFileLength(INPUT_FILE));
	printf("The output file was %d characters large.\n", getFileLength(OUTPUT_FILE));

	char* file_content = readFile(INPUT_FILE);
	Node* tree = CreateAvl("Hello");
	printHuffmanTreePreorder(tree);//had to modify it to understand our avl
	freeHuffmanTree(tree);

	/*
	OccurenceList occurence_list = createOccurenceList(file_content);

	// TESTS
	testOccurenceListGeneration();
	testOccurenceListSorting();
	
	sortOccurenceListByOccurenceDescendent(&occurence_list);
	//printOccurenceList(occurence_list);

	HuffmanTree tree = buildHuffmanTree(occurence_list);
	//printHuffmanTreePreorder(tree);

	Stack* s = createStack();
	FILE* dico = fopen(TEST_FILE, "w+");
	read_tree_dico(tree, TEST_FILE, s, 2, dico);
	fclose(dico);
	
	Dictionnary dictio = readDictionnary(DICO_FILE);
	printf("%c\n", dictio->next->binary[2]);
	//printDictionnary(dictio);

	char* encoded = textEncoding(dictio, file_content);
	printf("%s\n", encoded);

	freeHuffmanTree(tree);

	CONSOLE_RESET();*/
	return 0;
}