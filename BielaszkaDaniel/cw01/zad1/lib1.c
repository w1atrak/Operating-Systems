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
// https://stackoverflow.com/questions/238603/how-can-i-get-a-files-size-in-c
int tmpfile_size(char* filename){
    FILE* file = fopen(filename,"r");
    fseek(file, 0,SEEK_END);
    int size = ftell(file);
    fseek(file,0,SEEK_SET);
    fclose(file);

    return size;
}

void Lib1Count(WordCounters* strct, char* fileName){
    //https://pubs.opengroup.org/onlinepubs/009695399/functions/mkstemp.html
    char tmpFile[] = "/tmp/fileXXXXXX";
    int returnCode = mkstemp(tmpFile);

    if(returnCode==0){
        fprintf(stderr,"cant create a file in /tmp");
    }

    char command[50] = "wc ";
    char* b = " > ";
    strcat(command, fileName);
    strcat(command, b);
    strcat(command, tmpFile);

    system(command);

    int size = tmpfile_size(tmpFile);
    char* newBlock = calloc(size+1,sizeof(char));
    FILE* file = fopen(tmpFile,"r");
    fread(newBlock,sizeof(char),size,file);
    fclose(file);

    if(strct->size < strct->capacity){
        (strct->blocks)[strct->size] = newBlock;
        strct->size = strct->size + 1;
    }
    else{
        fprintf(stderr, "not enough space for new block");
    }

    char cmmd[50] = "rm -f ";
    strcat(cmmd,tmpFile);
    system(cmmd);

}

char* Lib1GetBlock(WordCounters strct, int index){
    if(index < strct.size){
        return (strct.blocks)[index];
    }
    else{
        fprintf(stderr,"index out of range");
        return "";
    }
}

void Lib1RemoveBlock(WordCounters* strct, int index){
    if(strct->size==0) return;
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