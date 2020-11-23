#include <stdio.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

// command 창에서 현재 위치 파일 open 하기 - xdg-open ./ | 아니면 xdg-open 파일 이렇게 열 수 있음
int main()
{
    pid_t pid;
    if((pid == fork()) == -1)
      
        printf("PID is %d , child process pid is %d\n",getpid(),pid); 
    else
    {
        printf("PID is %d , parent process pid is %d\n",getppid(),pid);
    }
    
}