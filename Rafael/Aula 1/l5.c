/* https://github.com/gipmon/lfa-aulas-praticas */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool M_5(char *u);
bool foundCA(char *u);
bool foundCB(char *u);

int main(int argc, char* argv[]){
	if(argc==1){
		printf("M5 :: Please as argument pass only A characters. A = {a, b, c}\n");
	}else{
		int i;
		for(i=1; i<argc; i++){
			if(strspn(argv[i], "abc") != strlen(argv[i])){
				printf("M5 :: Please as argument pass only A characters. A = {a, b, c}\n");
			}else{
				if(M_5(argv[i])){
				printf("M5 :: Result for \"%s\": correct!\n", argv[i]);
				}else{
					printf("M5 :: Result for \"%s\": not correct!\n", argv[i]);
				}
			}
		}
	}
	return 0;
}

bool M_5(char *u){
	int abc_found = 0; // number of "b" found
	int ca_cb_found = 0; // number of "a" found
	int length = strlen(u); // length da palavra passada como argumento

	for(; u[0]!='\0'; *u++){
		if(u[0]=='a' && u[1]!='\0' && u[1]=='b' && u[2]!='\0' && u[2]=='c'){
			abc_found++;
		}
		if(u[0]=='c' && u[1] != '\0' && u[1] == 'a'){
			ca_cb_found++;
		}
		if(u[0]=='c' && u[1] != '\0' && u[1] == 'b'){
			ca_cb_found++;
		}
	}

	return (abc_found >= ca_cb_found);
}
