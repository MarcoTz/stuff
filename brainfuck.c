#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const char *USAGE = "Usage: %s [OPTIONS] filename \nSee '%s --help' for more information\n";
const char *VERSION = "0.1alpha";

bool argsContain(const int argc, char * argv[const], const char *search){
	for(int i=0;i<argc;i++){
		if(strcmp(argv[i],search) == 0) return true;
	}
	return false;
}

char* handleArgs(const int argc, char *argv[const]){
	if(argc==1){
		printf(USAGE, argv[0], argv[0]);
		exit(0);
	}

	if(argsContain(argc, argv, "-h") || argsContain(argc, argv, "--help")){
		printf("%s, interprets a Brainfuck program.\n", argv[0]);
		printf(USAGE, argv[0], argv[0]);
		printf("\nOPTIONS: \n \t-h, --help Show this help and exit\n\t-v, --version show Version number and exit\n");
		exit(0);
	}

	if(argsContain(argc, argv, "-v") || argsContain(argc, argv, "--version")){
		printf("%s version %s\n", argv[0], VERSION);
		exit(0);
	}

	return argv[1];
}

char* readFile(FILE *file){
	fseek(file, 0, SEEK_END);
	long size = ftell(file);
	fseek(file, 0, SEEK_SET);
	
	char *contents = malloc(size+1);
	fread(contents,size,1,file);
	contents[size]=0;

	return contents;
}

char* stripCode(const char *code){
	char *stripped = malloc(strlen(code)+1);	
	int index = 0;

	while(*code!=0){
		if(*code=='>' || *code=='<' || *code=='+' || *code=='-' || *code=='.' || *code==',' || *code=='[' || *code==']'){	
			stripped[index]=*code;
			index++;
		}
		code++;
	}
	
	char* result = malloc(index+1);
	for(int i=0;i<=index;i++){
		result[i] = stripped[i];
	}
	result[index+1] = 0;

	return result;
}

void executeCode(const char* code){
	char *field = malloc(strlen(code));	

	for(int i=0;i<strlen(code);i++) field[i]= 0;

	while(*code!=0){
		if(*code=='>') field++;
		else if(*code=='<') field--;
		else if(*code=='+') (*field)++;
		else if(*code=='-') (*field)--;
		else if(*code=='.') printf("%c", *field);
		else if(*code==',') *field = getchar();
		else if(*code=='['&&(*field)==0) while(*code!=']') code++;
		else if(*code==']'&&(*field)!=0) while(*code!='[') code--;	
		code++;
	}
}

int main(int argc, char *argv[]){
	
	char *filename = handleArgs(argc, argv);
	FILE *sourcefile = fopen(filename,"r");
	char *code = readFile(sourcefile);
	fclose(sourcefile);
	code = stripCode(code);	
	executeCode(code);	
	return 0;
}
