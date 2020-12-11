#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "DataStructures/linkedlist.h"
#include "DataStructures/huffman_tree.h"
#include "DataStructures/dictionary.h"
#include "DataStructures/avl.h"
#include "debug.h"

#include "coding.h"

#include "Tests/test.h"

#define INPUT_FILE "assets/input.txt"
#define OUTPUT_FILE "assets/output.txt"
#define DICO_FILE "assets/dico.txt"
#define TEST_FILE "assets/test.txt"

#define ENABLE_TESTING 1

int main()
{
	puts("Hello Huffman !");

#if ENABLE_TESTING

	testOccurenceListGeneration();
	testOccurenceListSorting();

#endif

	char* text = encodeText("test", TEST_FILE);
	printf("translated text : %s\n", text);

	free(text);

	compressFile(INPUT_FILE, OUTPUT_FILE, DICO_FILE);

	CONSOLE_RESET();
	return 0;
}