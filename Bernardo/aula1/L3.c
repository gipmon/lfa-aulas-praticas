#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool M_3(char *u);

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
    		if(M_3(argv[i])){
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

bool M_3(char *u){
    
    int len = strlen(u);
    int i;
    for (i = 0; i < len; i++)
    {
        if(u[i] == 'a'){
            if (u[i+1] == 'b'){
                if(u[i+2] == 'a'){
                    return true;
                }
            }
        }
    }
    return false;
}