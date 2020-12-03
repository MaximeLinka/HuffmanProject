#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "DataStructures/linkedlist.h"
#include "huffman_tree.h"
#include "DataStructures/dictionnary.h"

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

	char* file_content = readFile(INPUT_FILE);
	LinkedList occurence_list = createOccurenceList(file_content);
	printLinkedList(occurence_list);

	//puts("After sorting !");

	sortLinkedListByOccurenceDescendent(&occurence_list);
	printLinkedList(occurence_list);

	HuffmanTree tree = buildHuffmanTree(occurence_list, 4);
	printHuffmanTree(tree);

	/*Stack* s = createStack();
	FILE* dico = fopen(DICO_FILE, "w+");
	read_tree_dico(tree, DICO_FILE, s, 2, dico);
	
	fclose(dico);*/
	
	Dictionnary dictio = readDictionnary(DICO_FILE);
	printDictionnary(dictio);

	char* encoded = textEncoding(dictio, file_content); //TODO: FIX PROBLEM \r
	printf("%s", encoded);

	freeHuffmanTree(tree);
	

	return 0;
}