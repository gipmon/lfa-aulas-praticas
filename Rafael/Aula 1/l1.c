/* https://github.com/gipmon/lfa-aulas-praticas */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool M_1(char *u);

int main(int argc, char* argv[]){
	if(argc==1){
		printf("Please as argument pass only A characters. A = {a, b, c}\n");
	}else{
		int i;
		for(i=1; i<argc; i++){
			if(strspn(argv[i], "abc") != strlen(argv[i])){
				printf("Please as argument pass only A characters. A = {a, b, c}\n");
			}else{
				if(M_1(argv[i])){
				printf("Result for \"%s\": correct!\n", argv[i]);
				}else{
					printf("Result for \"%s\": not correct!\n", argv[i]);
				}
			}
		}
	}
	return 0;
}

bool M_1(char *u){
	char equal = ' '; // character inicial para comparar
	int equal_characters=3; // j => equal characters
	int length = strlen(u); // length para comparação
	int i; // i tem de ser inicializado fora do for

	for(i=0; i<length; i++){
		if(equal==u[i]){ // se o caracter (anterior) for igual ao atual
			equal_characters--; // decrementa
			if(equal_characters==1){ // já encontrou 3 caracteres
				return true; // retorna verdadeiro
			}
		}else{ // não é igual
			equal_characters = 3; // vamos por a 3
			equal = u[i]; // voltamos a por equal = u[i]
		}
	}

	return false;
}
