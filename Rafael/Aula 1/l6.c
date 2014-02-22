#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool M_6(char *u);
bool foundCA(char *u);
bool foundCB(char *u);

int main(int argc, char* argv[]){
	if(argc==1){
		printf("M6 :: Please as argument pass only A characters. A = {a, b, c}\n");
	}else{
		int i;
		for(i=1; i<argc; i++){
			if(strspn(argv[i], "abc") != strlen(argv[i])){
				printf("M6 :: Please as argument pass only A characters. A = {a, b, c}\n");
			}else{
				if(M_6(argv[i])){
					printf("M6 :: Result for \"%s\": belongs to L6!\n", argv[i]);
				}else{
					printf("M6 :: Result for \"%s\": doesn't belong to L6!\n", argv[i]);
				}	
			} 
		}
	}
	return 0;
}

bool M_6(char *u){
	int c_found = 0; // number of "c" found
	int a_found = 0; // number of "a" found
	int i, j, length = strlen(u); // length da palavra passada como argumento
	
	for(i = 0; i<length; i++){
		if(u[i]=='b'){
			c_found = 0;
			a_found = 0;
			for(j=i+1; j<length; j++){
				if(u[j]=='b' && !((c_found>=0 && a_found==0) || (a_found>=0 && c_found==0))){
					return false;
				}else if(u[j]=='c'){
					c_found++;
				}else if(u[j]=='a'){
					a_found++;
				}
			}
		}
	}

	return true;
}