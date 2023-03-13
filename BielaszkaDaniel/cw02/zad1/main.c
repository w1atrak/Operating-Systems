#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


int sys_file;
FILE* lib_file;
int returns;

void openingRead(char* source){ 
#ifdef USE_SYS
    sys_file = open(source,  O_RDONLY  );
#else
    lib_file = fopen(source, "r");
#endif
}
void openingWrite(char* source){ 
#ifdef USE_SYS
    sys_file = open(source,  O_WRONLY | O_CREAT | O_TRUNC, 0666 );
#else
    lib_file = fopen(source, "w");
#endif
}

size_t getSize(){
#ifdef USE_SYS
    struct stat st;
    fstat(sys_file, &st);
    return st.st_size;
#else
    fseek(lib_file, 0, SEEK_END);
    long size = ftell(lib_file);
    fseek(lib_file, 0, SEEK_SET);
    return size;
#endif
}



char* getFileContent(){                // calloc??
    char* tmp = (char*)calloc(getSize(), sizeof(char));
#ifdef USE_SYS
    size_t size = getSize();
    returns = read(sys_file, tmp, sizeof(char)*size);
#else
    size_t size = getSize();
    fread(tmp, sizeof(char), size, lib_file);
#endif
    return tmp;
}

void writeContentToFile(char* tmp){
#ifdef USE_SYS
    returns = write(sys_file, (void*)tmp, sizeof(char)*strlen(tmp));
#else
    fwrite((void*)tmp, sizeof(char), strlen(tmp), lib_file);
#endif
}

void closing(){
#ifdef USE_SYS
    returns = close(sys_file);
#else
    fclose(lib_file);
#endif
}


int main(int argc, char *argv[])
{
    if(argc != 5)
    {
        fprintf(stderr,"Wrong number of arguments\n");
        return 1;
    }
    if(strlen(argv[1]) != 1  || strlen(argv[2]) != 1)
    {
        fprintf(stderr,"First 2 args must be char\n");
        return 2;
    }

    char find = argv[1][0];
    char replace = argv[2][0];
    char* source_file = argv[3];
    char* output_file = argv[4];

    FILE* file = fopen(source_file, "r");
    if(file == NULL)
    {
        fprintf(stderr,"Source file doesn't exist\n");
        return 3;
    }
    else
        fclose(file);
        
    
    openingRead(source_file);
    char* tmp = calloc(getSize(), sizeof(char)); 
    tmp = getFileContent(tmp);

    closing();

    char* tmp2 = tmp;
    puts(tmp2);
    while(*tmp2)
    {
        if(*tmp2 == find)
            *tmp2 = replace;
        tmp2++;
    }

    puts(tmp);

    openingWrite(output_file);

    writeContentToFile(tmp);
    closing();


}