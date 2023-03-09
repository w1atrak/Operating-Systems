#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    fputs("podaj parametry: ",stdout);
    char find;
    char replace;
    char source_file[60];
    char output_file[60];
    char* line = NULL;
    size_t lineSize;
    int code = getline(&line,&lineSize,stdin);
    sscanf(line,"%c %c %s %s", &find,&replace,source_file,output_file);

    FILE* old_file = fopen(source_file,"rt");
    if(!old_file) fprintf(stderr,"cant find file to read from");

    const int SIZE = 1000;
    char bufor[SIZE];

    size_t read_size = fread(bufor, sizeof(char),SIZE, old_file);
    printf("%zu",read_size);

}