#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>


int main(int argc, char** argv){
    long long sum = 0;

    DIR* dir = opendir(".");
    if(dir == NULL){
        printf("Error while opening directory");
        exit(1);
    }
    struct dirent* files;
    struct stat st;
    printf("%lld",sum);
    while((files = readdir(dir))!= NULL){
        stat(files->d_name, &st);
        if(!S_ISDIR(st.st_mode)){
            sum += st.st_size;
            printf("%s %ld\n", files->d_name, st.st_size);
        }
    }


    closedir(dir);
    printf("Total size: %lld\n", sum);
}