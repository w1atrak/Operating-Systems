#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef struct {
    char** blocks;
    int size;
    int capacity;
} WordCounters;



WordCounters (*Lib1CreateStruct)(int);

void (*Lib1Count)(WordCounters* , char* );

char* (*Lib1GetBlock)(WordCounters* , int );

void (*Lib1RemoveBlock)(WordCounters* , int );

void (*Lib1DeleteBlocks)(WordCounters* );

  