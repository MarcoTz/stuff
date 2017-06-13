#include <stdio.h>
#include "utils.h"

const char VOWELS[] = {'a','e','i','o','u'};

int main(int argc, char* argv[]){
	
	if(argc==1 || inArgs("-h",(const char** const)argv,argc) || inArgs("--help", (const char** const) argv, argc)){
		printf("Usage: vowels word1 ...\n");
		printf("Prints the number of occurances of each vowel in each word");
		return 0;
	}

	for(int i=1;i<argc;i++){
		int vowelC[] = {0,0,0,0,0};

		while(*argv[i] != '\0'){
			if(*argv[i] == 'a') vowelC[0]++;
			else if(*argv[i] == 'e') vowelC[1]++;
			else if(*argv[i] == 'i') vowelC[2]++;
			else if(*argv[i] == 'o') vowelC[3]++;
			else if(*argv[i] == 'u') vowelC[4]++;
			
			argv[i]++;
		}
	
		printf("A: %i, E: %i, I: %i, O: %i, U: %i\n", vowelC[0], vowelC[1], vowelC[2], vowelC[3], vowelC[4]);
	}
	return 0;
}
