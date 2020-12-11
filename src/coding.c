#include "coding.h"

#include "DataStructures/linkedlist.h"
#include "DataStructures/huffman_tree.h"
#include "utils.h"

#include <string.h>

char* encodeText(char* string, const char* dicopath)
{
	OccurenceList occurence_list = createOccurenceList(string);

	sortOccurenceListByOccurenceDescendent(&occurence_list);

	HuffmanTree tree = buildHuffmanTree(occurence_list);

	Dictionary dico = buildDictionary(tree);
	serializeDictionary(dico, dicopath);

	char* code = encodeTextWithDictionary(dico, string);

	freeHuffmanTree(tree);

	return code;
}

void compressFile(const char* input, const char* output, const char* dico)
{
	char* file_content = readFile(input);

	char* code = encodeText(file_content, dico);

	writeStringToFile(output, code, strlen(code));

	free(file_content);
	free(code);
}