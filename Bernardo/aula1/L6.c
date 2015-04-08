/* https://github.com/gipmon/lfa-aulas-praticas */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool M_6(char *u);

int main(int argc, char* argv[])
{
    /* check commmand line */
    if (argc < 2)
    {
        fprintf(stderr, "Wrong number of arguments\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 1; i < argc; i++)
    {
    	if(strlen(argv[i]) == strspn(argv[i],"abc")){
    		if(M_6(argv[i])){
    			printf("A %dº palavra pertence à linguagem!!\n",i);
    		}
    		else{
    			printf("A %dº palavra nao pertence à linguagem!!\n",i);
    		}
    	}
    	else{
    		printf("A %dº palavra contém caracteres invalidos!!\n",i);
    	}
    }

}

bool M_6(char *u){

    int len = strlen(u);
    int i,j,numA,numC;
    for (i = 0; i < len; i++)
    {
        if(u[i] == 'b'){
            numA=0;
            numC=0;
            for(j = i+1 ;j < len; j++ ){
                if(u[j]=='b'){ //Se encontrar o segundo b confere se entre os dois há so a's ou so c's(ou nunhum dos dois)
                    if(numA == 0 || numC == 0){
                        break;
                    }
                    else return false;
                }
                else if(u[j] == 'a'){
                    numA++;
                }
                else if(u[j] == 'c'){
                    numC++;
                }

            }
        }
    }
    return true;
}
