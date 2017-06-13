#include <stdio.h>
#include "utils.h"

const char VOWELS[] = {'a', 'e', 'i', 'o', 'u'};
const int VOWELC = 5;

int main(int argc, char* argv[]){
	
	if(argc==1 || inArgs("-h",(const char** const)argv,argc) || inArgs("--help", (const char** const) argv, argc)){
		printf("Usage: piglatin word1 ...\n");
		printf("Prints the words in piglatin");
		return 0;
	}

	for(int i=1;i<argc;i++){
		if(inStr(argv[i][0],VOWELS,VOWELC)){
			printf("%say\n",argv[i]);
		}else{
			int j=0;
			while(!inStr(argv[i][j],VOWELS,VOWELC)){
				j++;
			}
			
			argv[i] += j;
			printf("%s",argv[i]);
			argv[i][0] = '\0';
			argv[i] -= j;
			printf("%say\n", argv[i]);
		}
	}

	return 0;
}
