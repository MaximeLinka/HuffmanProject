#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "linkedlist.h"
#include "huffman_tree.h"

#define INPUT_FILE "assets/input.txt"
#define OUTPUT_FILE "assets/output.txt"
#define DICO "assets/dico.txt"

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

	Node* tree = convert_list_to_tree(list, 4);
	print_tree(tree);
	free_tree(tree);

	char* name_file = DICO;
	Stack* s = create_stack();
	FILE* dico = fopen(DICO, "w+");
	read_tree_dico(tree, name_file, s, 2);
	fclose(dico);


	return 0;
}