#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{

	int id = fork();

    if(id == 0)
        printf("I am your Son, my ID is: %d , my father is: %d\n", getpid() ,getppid());
    else
        printf("I am your father, My Son is: %d\n", id);
	return 0;
}
