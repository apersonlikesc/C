#include<stdio.h>

int main(){
    int c;
    FILE *fin;

    fin = fopen("inpfile","r");
    if(fin == (FILE*)NULL){
        exit(-1);
    }
    do{
            c = fgetc(fin);
            if(c!=EOF){
            printf("%c",(char)c);
            }
        }while(c!=EOF);
    fclose(fin);
    return 0;
}
