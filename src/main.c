#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "DataStructures/linkedlist.h"
#include "huffman_tree.h"

#define INPUT_FILE "assets/input.txt"
#define OUTPUT_FILE "assets/output.txt"
#define DICO_FILE "assets/dico.txt"

int main()
{
	puts("Hello Huffman !");

	stringFileToBinary(INPUT_FILE, OUTPUT_FILE);
	puts("The transfer was successfull !");

	printf("The input file was %d characters large.\n", getFileLength(INPUT_FILE));
	printf("The output file was %d characters large.\n", getFileLength(OUTPUT_FILE));

	LinkedList list = createOccurenceList("bonsoir mdrr", 12);
	printLinkedList(list);

	puts("After sorting !");

	sortLinkedListByOccurenceDescendent(&list);
	printLinkedList(list);

	HuffmanTree tree = buildHuffmanTree(list, 4);
	printHuffmanTree(tree);

	Stack* s = createStack();
	FILE* dico = fopen(DICO_FILE, "w+");
	read_tree_dico(tree, DICO_FILE, s, 2, dico);
	fclose(dico);

	freeHuffmanTree(tree);


	return 0;
}