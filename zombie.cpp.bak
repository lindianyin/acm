#include <sys/types.h>
#include <unistd.h>  
#include <cstdlib>
#include <cstdio>
using namespace std;
int main()
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
