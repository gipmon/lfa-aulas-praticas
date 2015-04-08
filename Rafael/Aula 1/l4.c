/* https://github.com/gipmon/lfa-aulas-praticas */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool M_4(char *u);

int main(int argc, char* argv[]){
	if(argc==1){
		printf("M4 :: Please as argument pass only A characters. A = {a, b, c}\n");
	}else{
		int i;
		for(i=1; i<argc; i++){
			if(strspn(argv[i], "abc") != strlen(argv[i])){
				printf("M4 :: Please as argument pass only A characters. A = {a, b, c}\n");
			}else{
				if(M_4(argv[i])){
				printf("M4 :: Result for \"%s\": correct!\n", argv[i]);
				}else{
					printf("M4 :: Result for \"%s\": not correct!\n", argv[i]);
				}
			}
		}
	}
	return 0;
}

bool M_4(char *u){
	int b_found = 0; // number of "b" found
	int a_found = 0; // number of "a" found
	int length = strlen(u); // length da palavra passada como argumento
	int i; // i tem de ser inicializado fora do for em C

	for(i=0; i<length; i++){ //o ultimo caracter não interessa
		if(u[i]=='a'){
			a_found++;
		}else if(u[i]=='b'){
			b_found++;
		}
	}

	return (b_found==0 || a_found%2==0);
}
