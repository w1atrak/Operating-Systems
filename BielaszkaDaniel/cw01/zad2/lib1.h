#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char** blocks;
    int size;
    int capacity;
} WordCounters;



WordCounters Lib1CreateStruct(int size);

void Lib1Count(WordCounters* strct, char* fileName);

char* Lib1GetBlock(WordCounters* strct, int index);

void Lib1RemoveBlock(WordCounters* strct, int index);

void Lib1DeleteBlocks(WordCounters* blocks);

  