#include <stdio.h>
#include "utils.h"

int main(int argc, char* argv[]){
	if(argc==1 || inArgs("-h",(const char** const)argv,argc) || inArgs("--help", (const char** const) argv, argc)){
		printf("Usage: wordc file1 ...\n");
		printf("Counts the words in each of the files");
		return 0;
	}

	for(int i=1;i<argc;i++){
		FILE *f = fopen(argv[i], "r");
		 
		if(f){
			int count = 0;
			int next;
			while(next != EOF){
				next = getc(f);	
				if(next == ' ' || next == '\n') count++;
			}
			printf("%s has %i words\n",argv[i],count);
		}else{
			printf("%s: File not found", argv[i]);
		}
	}
	return 0;
}
