#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool M_1(char* u);

int main(int argc, char* argv[]){
	if(argc == 1){
		printf("Incorrect number of arguments!\n");
	}
	int i;
	for(i = 1; i<argc; i++){
		if(strspn(argv[i], "abc") != strlen(argv[i])){
			printf("Incorrect group\n");
		}else{
			if(M_1(argv[i])){
				printf("True\n");
			}else
				printf("False\n");
		}
	}

	exit(0);
}

bool M_1(char* u){
	char act = u[0];
	unsigned long length = strlen(u);
	unsigned int i, j = 0;

	for(i = 1; i<length; i++){
		if(u[i] == act){
			j++;
			if(j == 2){
				return true;
			}
		}else{
			act = u[i];
			j = 0;
		}
		
	}
	return false;

	
}