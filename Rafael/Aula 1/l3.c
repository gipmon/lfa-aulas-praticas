/* https://github.com/gipmon/lfa-aulas-praticas */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool M_3(char *u);

int main(int argc, char* argv[]){
	if(argc==1){
		printf("M3 :: Please as argument pass only A characters. A = {a, b, c}\n");
	}else{
		int i;
		for(i=1; i<argc; i++){
			if(strspn(argv[i], "abc") != strlen(argv[i])){
				printf("M3 :: Please as argument pass only A characters. A = {a, b, c}\n");
			}else{
				if(M_3(argv[i])){
				printf("M3 :: Result for \"%s\": correct!\n", argv[i]);
				}else{
					printf("M3 :: Result for \"%s\": not correct!\n", argv[i]);
				}
			}
		}
	}
	return 0;
}

bool M_3(char *u){
	int found = 0; // number of "aba" found
	int length = strlen(u); // length da palavra passada como argumento
	int i; // i tem de ser inicializado fora do for em C

	for(i=0; i<length-2; i++){ //o ultimo caracter não interessa
		if(u[i]=='a'){
			if(u[i+1]=='b'){
				if(u[i+2]=='a'){
					found++;
					i++;
				}
			}
		}
	}

	return (found>1);
}
