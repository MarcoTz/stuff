#include "utils.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int strLen(const char str[]){
	int len = 0;

	while(*str != '\0'){
		len++;
		str++;
	}

	return len;
}

char* reverseStr(const char str[], const int strl){
	char *rev = malloc(strl+1);
	
	if(!rev){
		return NULL;
	}

	for(int i=strl-1;i>=0;i--){
		rev[strl-1-i] = str[i];
	}

	rev[strl] = '\0';
	return rev;
}

bool inArgs(const char *search, const  char *args[], const int argc){
	for(int i=1;i<argc;i++){
		if(!strcmp(args[i],search)){
			return true;
		}
	}
	return false;
}

bool inStr(const char search, const char str[], const int strl){
	for(int i=0; i<strl;i++){
		if(str[i] == search){
			return true;
		}
	}
	return false;
}

int loadContents(const char *filename, char **buffer){
	FILE *f = fopen(filename, "rb");
	long len = -1;
	*buffer = NULL;
	if(f){
		fseek(f,0,SEEK_END);
		len = ftell(f);
		fseek(f,0,SEEK_SET);
		*buffer = (char *)malloc(len+1);

		if(*buffer){
			fread(*buffer,sizeof(char),len,f);
			(*buffer)[len] = '\0';
			printf("%s",*buffer);
		}
		fclose(f);
	}

	return len;
}
