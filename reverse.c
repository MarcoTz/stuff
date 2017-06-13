#include <stdio.h>
#include "utils.h"

int main(int argc, char* argv[]){

	if(argc==1 || inArgs("-h",(const char** const)argv,argc) || inArgs("--help", (const char** const) argv, argc)){
		printf("Usage: reverse word1 ...\n");
		printf("reverses the arguments");
		return 0;
	}

	for(int i=1;i<argc;i++){
		int size = strLen(argv[i]);
		for(int j=size-1;j>=0;j--){
			printf("%c",argv[i][j]);
		}
	}
}
