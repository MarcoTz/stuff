#ifndef HEADER_FILE
#define HEADER_FILE

typedef int bool;
#define true 1 
#define false 0

//! returns the length of a string
/*!
	\param str the string to find the length of 
	\return the length of the string
*/
int strLen(const char str[]);

//! returns the reverse of a string
/*!
	\param str the string to be reversed
	\param strl the length of the string
	\return the reverse of the string, returns NULL if there was an error
*/
char* reverseStr(const char str[], const int strl);

//! searches for a string in the command line args
/*! 
	\param search the string to search
	\param argv an array containing command line arguments(it is assumed that argv[0] is the name of the executable
	\param argc the number of arguments(it is assumed that the name is counted)
	\return true if one of the arguments is the same as search, false otherwise
*/
bool inArgs(const char search[], const char *argv[], const int argc);

//! searches for a char in a string
/*!
	\param search character to search 
	\param str string to search in 
	\param strl length of the string
	\return true if char has been found in string
*/
bool inStr(const char search, const char str[], const int strl);

//! loads filename into buffer and returns length
/*! 
	\param filname the filename to load contents from 
	\param buffer the string to load contents into
	\return the length of the string, -1 if there was an error
*/
int loadContents(const char *filename, char **buffer);

#endif
