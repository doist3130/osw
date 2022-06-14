#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(void)
{
	int pid;
	int status;
	int i;
	pid_t pid1;

	if((pid = fork()) == 0)
	{
		printf("I'm child : %d\n", getpid());
		for(i = 0; i < 4; i++)
		{
			printf("child cnt : %d\n", i);
			sleep(1);
		}
	}
	else if(pid > 0)
	{
        printf("I'm parent : %d\n wait for child\n", getpid());
		pid1 = wait(&status);
		for(i = 0; i < 4; i++)
		{
			printf("parent cnt : %d\n", i);
			sleep(1);
		}
	} else {
        perror("fork()");
    }
	return 0;
}