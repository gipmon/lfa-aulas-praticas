#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool M_2(char* u);
bool M_3(char* u);
bool M_4(char* u);
bool M_5(char* u);

int main(int argc, char* argv[]){
	if(argc == 1){
		printf("Incorrect number of arguments!\n");
	}
	int i;
	for(i = 1; i<argc; i++){
		if(strspn(argv[i],"abc") != strlen(argv[i])){
			printf("Invalid alphabet\n");
		}else{
			printf("Resultados do %1dº argumento: \n", i);
			int j;
			for(j = 2; j <= 5; j++){
				if(M_i(argv[i])){
					printf("True\n");
				}else printf("False\n");
			}
		}
	}

	exit(0);
}

bool M_2(char* u){
	return true;
}

bool M_3(char* u){
	return false;
}