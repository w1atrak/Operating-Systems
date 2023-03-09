#include "lib1.h"
#include <stdlib.h>
#include <string.h>
WordCounters Lib1CreateStruct(int size){
    WordCounters tmp;
    tmp.capacity = size;
    tmp.size = 0;
    tmp.blocks = calloc(size, sizeof(char*));

    return tmp;
}
long tmpfile_size(FILE* file){
    fseek(file, 0,SEEK_END);
    long size = ftell(file);
    fseek(file,0,SEEK_SET);

    return size;
}

char* readFile(char* filename){
    FILE* file = fopen(filename,"r");
    long size = tmpfile_size(file);
    char* result = calloc(size, sizeof(char));
    fread(result, sizeof(char), size, file);
    fclose(file);
    return result;
}

void Lib1Count(WordCounters* strct, char* fileName){
    char tmpFile[] = "/tmp/fileXXXXXX";
    int returnCode = mkstemp(tmpFile);

    if(returnCode==0){
        fprintf(stderr,"cant create a file in /tmp");
    }
    fileName[strcspn(fileName,"\n")] = 0;
    char command[50] = "wc ";
    char* b = " 1> ";
    strcat(command, fileName);
    strcat(command, b);
    strcat(command, tmpFile);

    int negate = system(command);
    
    char* result = readFile(tmpFile);

    if(strct->size < strct->capacity){
        strct->blocks[strct->size] = result;
        strct->size = strct->size + 1;
    }
    else{
        fprintf(stderr, "not enough space for new block");
    }

    char cmmd[50] = "rm -f ";
    strcat(cmmd,tmpFile);
    system(cmmd);

}

char* Lib1GetBlock(WordCounters* strct, int index){
    if(index < strct->size){
        return strct->blocks[index];
    }
    else{
        fprintf(stderr,"index out of range");
        return "";
    }
}

void Lib1RemoveBlock(WordCounters* strct, int index){
    if(strct->size==0) {
        fprintf(stderr,"no data saved");
        return;
    }
    if(index>=strct->size) fprintf(stderr,"index out of range");

    free(strct->blocks[index]);

    if(strct->size>1){
        strct->blocks[index] = strct->blocks[strct->size-1];
    }

    strct->size = strct->size-1;
}


void Lib1DeleteBlocks(WordCounters* blocks){
    for(int i = 0; i < blocks->size; i++){
        free(blocks->blocks[i]);
    }
    free(blocks->blocks);
    blocks->size = 0;
}