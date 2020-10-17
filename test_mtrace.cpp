#include <mcheck.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
        setenv("MALLOC_TRACE", "taoge.log", 1);
        mtrace();

        int *p = (int *)malloc(2 * sizeof(int));
        //int *p = new int[4];
		int c = getchar();
	
        return 0;
}
