#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>


int main(){

    while(1){
        
        int id = fork();
        int stat;
        if( id == 0){
            printf("$ ");
            char command[2048];
            char temp;
            int number = 0;
            int index = 0;
            do{

                scanf("%c", &temp);
                if(temp != '\0' && temp != '\n')
                    command[index] = temp;
                if(temp == ' ' && command[index-1] != '\\')
                    number++;
                index++;
            }while(temp != '\n' && temp != '\0');
            
            char *arguments[number+1];
            char *commands = strtok(command, " ");

            int i =0;
            while( commands != NULL ) {
                arguments[i] = commands;
                i++;
    
                commands = strtok(NULL, " ");
            }
            arguments[number+1] = NULL;
            execvp(arguments[0],arguments);
            break;
        }
        waitpid(id,&stat, 0);
    }

}