#include <stdio.h>
#include <string.h>

#ifndef DEBUG_H
#define DEBUG_H

#ifdef _DEBUG

	#define DEBUG_INFO(...) printf("\033[0;37m[DEBUG] "); printf(__VA_ARGS__); puts("")
	#define DEBUG_SUCCESS(...) printf("\033[0;32m[DEBUG] "); printf(__VA_ARGS__); puts("")
	#define DEBUG_CRITICAL(...) printf("\033[0;31m[DEBUG] "); printf(__VA_ARGS__); puts("")
	#define CONSOLE_RESET() puts("\033[0;37m")

	#define ASSERT(x, error_msg) { if(!(x)) { DEBUG_CRITICAL("Assertion failed ! : %s", error_msg); __debugbreak();}}

#else

	#define DEBUG_INFO(...)
	#define DEBUG_SUCCESS(...)
	#define DEBUG_CRITICAL(...)
	#define CONSOLE_RESET()

	#define ASSERT(x, error_msg)

#endif

#endif