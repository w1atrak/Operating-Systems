#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/times.h>

#ifndef CHARS_NUMBER
#define CHARS_NUMBER 1
#endif

long fileSize(FILE* file){
    fseek(file,0,SEEK_END);
    long size = ftell(file);
    fseek(file,0,SEEK_SET);
    return size;
}
void reverse(char* tmp, long size){
    for(long i = 0; i < size/2; i++){
        char tmp2 = tmp[i];
        tmp[i] = tmp[size - i - 1];
        tmp[size - i - 1] = tmp2;
    }
}

int main(int argc, char** argv){
    if(argc != 3){
        fprintf(stderr, "Wrong number of arguments\n");
        return 1;
    }

    char* input = argv[1];
    char* output = argv[2];


    FILE* file_in = fopen(input, "r");
    FILE* file_out = fopen(output, "w");
    if(file_in == NULL){
        fprintf(stderr, "File doesn't exist\n");
        return 2;
    }

    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);



    long f_size = fileSize(file_in);
    char* tmp = (char*)calloc(f_size, sizeof(char));

    long index = 0;
    while(!feof(file_in)){
        index += fread(&tmp[index] , sizeof(char), CHARS_NUMBER, file_in);
    }
    reverse(tmp, f_size);


    fprintf(file_out, "%s", tmp);
    fclose(file_in);
    fclose(file_out);

    clock_gettime(CLOCK_REALTIME, &end);
    printf("Time: %ld\n", end.tv_nsec - start.tv_nsec);
}


