#include "test.h"
#include "debug.h"

#include "DataStructures/linkedlist.h"

void testOccurenceListGeneration()
{
	DEBUG_INFO("Starting Occurence list generation test...");

	char* test = "aaabbccccdeffgghijjj";
	OccurenceList l = createOccurenceList(test);

	int size = getOccurenceListSize(l);
	if (size != 10)
	{
		DEBUG_CRITICAL("Occurence list generation test failed ! list size was %d instead of 10.", size);
		return;
	}
	DEBUG_INFO("\t*Test case 1 passed.");

	int sum = getOccurenceListSum(l);
	if (sum != 20)
	{
		DEBUG_CRITICAL("Occurence list generation test failed ! list sum of occurences was %d instead of 20.", sum);
		return;
	}

	DEBUG_INFO("\t*Test case 2 passed.");

	freeOccurenceList(l);
	DEBUG_SUCCESS("Occurence list generation test was successful !");
	CONSOLE_RESET();
}

void testOccurenceListSorting()
{
	DEBUG_INFO("Starting Occurence list sorting test...");

	char* test = "aaabbccccdeffgghijjj";
	OccurenceList l = createOccurenceList(test);
	sortOccurenceListByOccurenceDescendent(&l);

	int sorted = isOccurenceListSorted(l);
	if (!sorted)
	{
		DEBUG_CRITICAL("Occurence list sorting test failed ! list is not sorted.");
		return;
	}

	DEBUG_INFO("\t*Test case 1 passed.");

	freeOccurenceList(l);
	DEBUG_SUCCESS("Occurence list sorting test was successful !");
	CONSOLE_RESET();
}
