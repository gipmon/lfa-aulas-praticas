#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool M_4(char *u);

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
    		if(M_4(argv[i])){
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

bool M_4(char *u){
    int b = 0;
    int a = 0;
    int len = strlen(u);
    int i;
    for (i = 0; i < len; i++)
    {
        if(u[i] == 'b'){
            b++;
        }
        if(u[i] == 'a'){
            a++;
        }
    }
    if(b==0){
        return true;
    }
    if(a%2==0){
        return true;
    }
    return false;
}