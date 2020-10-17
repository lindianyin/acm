#include <sys/types.h>
#include <unistd.h>  
void main()
{
    pid_t pid; 
    pid=fork();
    if(pid<0) {
        printf("error occurred!\n");
    }else if(pid==0){
        exit(0);
    }else{ 
        sleep(60); 
        wait(NULL);
    }
}
