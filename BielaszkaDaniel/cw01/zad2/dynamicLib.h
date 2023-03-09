#ifdef DYNAMIC_LIBRARY
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>


void load_functions(const char* path){
    void *handle = dlopen(path, RTLD_LAZY);
    if(handle==NULL) {
        fprintf(stderr,"cant execute dlopen");
        return;
    }
    *(void**)(&Lib1CreateStruct) = dlsym(handle,"Lib1CreateStruct");
    *(void**)(&Lib1Count) = dlsym(handle,"Lib1Count");
    *(void**)(&Lib1RemoveBlock) = dlsym(handle,"Lib1RemoveBlock");
    *(void**)(&Lib1DeleteBlocks) = dlsym(handle,"Lib1DeleteBlocks");
}




#else
void load_functions(const char* path){}
#endif