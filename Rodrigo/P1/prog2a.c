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

			if(M_2(argv[i])){
				printf("L2 - True\n");
			}else printf("L2 - False\n");
			if(M_3(argv[i])){
				printf("L3 - True\n");
			}else printf("L3 - False\n");
			if(M_4(argv[i])){
				printf("L4 - True\n");
			}else printf("L4 - False\n");
			if(M_5(argv[i])){
				printf("L5 - True\n");
			}else printf("L5 - False\n");
			
		}
	}

	exit(0);
}

bool M_2(char* u){
	int i, ab_cont = 0;
	int len = strlen(u);

	for(i = 0; i<len; i++){
		if(u[i] == 'a' && u[i+1] == 'b'){
			ab_cont++;
		}
	}
	if(ab_cont > 1) return true;

	return false;
}

bool M_3(char* u){
	int i, aba_cont = 0;
	int len = strlen(u);

	for(i = 0; i<len; i++){
		if(u[i] == 'a' && u[i+1] == 'b' && u[i+2] == 'a'){
			aba_cont++;
		}
	}
	if(aba_cont > 1) return true;

	return false;
}

bool M_4(char* u){
	int i, a_cont = 0, b_cont = 0;
	int len = strlen(u);

	for(i = 0; i<len; i++){
		if(u[i] == 'b') b_cont++;
		else if(u[i] == 'a') a_cont++;
	}

	if(b_cont == 0 || (a_cont%2) == 0) return true;

	return false;

}

bool M_5(char* u){
	int i, abc_cont = 0, ca_cont = 0, cb_cont = 0;
	int len = strlen(u);

	for(i = 0; i<len; i++){
		if(u[i] == 'a' && u[i+1] == 'b' && u[i+2] == 'c') abc_cont++;
		else if(u[i] == 'c' && u[i+1] == 'a') ca_cont++;
		else if(u[i] == 'c' && u[i+1] == 'b') cb_cont++;
	} 

	if(abc_cont >= (ca_cont + cb_cont)) return true;

	return false;

}