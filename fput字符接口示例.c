#include<stdio.h>

int main(){
    int i;
    FILE* fout;
    const char string[] ={"this\nis a test\r\nfile.\r\n\0"};

    fout = fopen("inpfile","w");

    if(fout == (FILE*)NULL){
        exit(-1);
    }
    i=0;
    while(string[i] !=NULL){
        fputc((int)string[i],fout);//fout 文件
        i++;
    }

    fclose(fout);

    return 0;
}
