#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

int main(int argc, char* argv[]){
	if(argc==1 || inArgs("-h",(const char** const)argv,argc) || inArgs("--help", (const char** const) argv, argc)){
		printf("Usage: palindrome word1 ...\n");
		printf("Checks if the arguments are palindromes");
		return 0;
	}

	for(int i=1;i<argc;i++){

		int len = strLen(argv[i]);
		char *rev = reverseStr(argv[i],len);

		if(!rev){
			printf("Error allocating memory");
			return 1;
		}
		
		if(!strcmp(argv[i],rev)){
			printf("%s is a palindrome\n",argv[i]);
		}else{
			printf("%s is not a palindrome\n",argv[i]);
		}
	}
	return 0;
}
