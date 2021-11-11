#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>


int main(int argc, char **argv){
    char *arguments[argc];
    for(int i = 0; i < argc; i++){
        if (i > 0){
            // printf("%d ", i-1);
            arguments[i-1] = argv[i];
        }
    }
    
    arguments[argc-1] = NULL;

    printf("%d", execvp(argv[1],arguments));
    
}