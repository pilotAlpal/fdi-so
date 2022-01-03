#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



int main(int argc, char *argv[])
{
    int contador = 0, aux = 0,i;
    char * archivo = "/dev/leds";
   
    int df = open(archivo, O_WRONLY);

    if(df == -1)
        return 1;
    write (df, argv[1],3);
    close(df);
    return 0;
}		
