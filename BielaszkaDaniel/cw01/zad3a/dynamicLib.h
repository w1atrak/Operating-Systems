#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef DYNAMIC_LIB

void load_functions(char* path){
    void *handle = dlopen(path, RTLD_LAZY);
    if(handle==NULL) {
        fprintf(stderr,"cant execute dlopen");
        puts(dlerror());
        return;
    }
    *(void**)(&Lib1CreateStruct) = dlsym(handle,"Lib1CreateStruct");
    *(void**)(&Lib1Count) = dlsym(handle,"Lib1Count");
    *(void**)(&Lib1GetBlock) = dlsym(handle,"Lib1GetBlock");
    *(void**)(&Lib1RemoveBlock) = dlsym(handle,"Lib1RemoveBlock");
    *(void**)(&Lib1DeleteBlocks) = dlsym(handle,"Lib1DeleteBlocks");
}




#else
void load_functions(char* path){}
#endif