#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <ftw.h>

long sum = 0;
int returns = 0;

int sumDirectory(const char* path, const struct stat* stat, int type){
    if(type != FTW_D){
        printf("%s %ld\n", path, stat->st_size);
        sum += stat->st_size;
    }
    return 0;
}


int main(int argc, char** argv){

    if(argc != 2){
        printf("Wrong number of arguments");
        exit(1);
    }
    char* path = argv[1]; 

    returns = ftw(path,sumDirectory,1);

    DIR* dir = opendir(path);
    if(dir == NULL){
        printf("Error while opening directory");
        exit(3);
    }
    closedir(dir);

    if(returns != 0){
        printf("Error with ftw()");
        exit(2);
    }

    printf("\nTotal size: %ld\n", sum);

    return 0;
}