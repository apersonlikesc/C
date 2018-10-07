#include <stdio.h>
#include <errno.h>
#include <string.h>

#define MYFILE "missing.txt"

int main(){
    FILE *fin;

    fin = fopen(MYFILE,"r");

    if(fin == (FILE*)NULL){

        printf("%s : %s\n",MYFILE,strerror(errno));
        exit(-1);
    }
    fclose(fin);
    return 0;
}

