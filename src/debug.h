/*****************************************************************//**
* \file debug.h
* \brief Header of the library containing some debug macros.
*********************************************************************/

#include <stdio.h>
#include <string.h>

#ifndef DEBUG_H
#define DEBUG_H

#ifdef _DEBUG

	/**
	* \def DEBUG_INFO
	* \brief a debug macro to print an information to the console.
	*/
	#define DEBUG_INFO(...) printf("\033[0;37m[DEBUG] "); printf(__VA_ARGS__); puts("")

	/**
	* \def DEBUG_SUCCESS
	* \brief a debug macro to print a success to the console.
	*/
	#define DEBUG_SUCCESS(...) printf("\033[0;32m[DEBUG] "); printf(__VA_ARGS__); puts("")

	/**
	* \def DEBUG_CRITICAL
	* \brief a debug macro to print a critical message or an error to the console.
	*/
	#define DEBUG_CRITICAL(...) printf("\033[0;31m[DEBUG] "); printf(__VA_ARGS__); puts("")

	/**
		* \def CONSOLE_RESET
		* \brief a debug macro to reset the color of the text in the console.
		*/
	#define CONSOLE_RESET() puts("\033[0;37m")

	/**
	* \def ASSERT
	* \brief a debug macro assert something.
	*/
	#define ASSERT(x, error_msg) { if(!(x)) { DEBUG_CRITICAL("Assertion failed ! : %s", error_msg); __debugbreak();}}

#else

	#define DEBUG_INFO(...)
	#define DEBUG_SUCCESS(...)
	#define DEBUG_CRITICAL(...)
	#define CONSOLE_RESET()

	#define ASSERT(x, error_msg)

#endif

#endif
