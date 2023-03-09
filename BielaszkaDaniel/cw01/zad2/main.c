#ifdef DYNAMIC_LIB
    #include "lib1_dyn.h"
#else
    #include "lib1.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <regex.h>
#include <time.h>
#include <sys/times.h>
#include "dynamic.h"


int main(int argc, char *argv[])
{

      

    regex_t INIT;
    regex_t COUNT;
    regex_t SHOW;
    regex_t DELETE;
    regex_t DESTROY;

    int initialized = 0;
    WordCounters obj;

    regcomp(&INIT, "init [0-9][0-9]*",0);
    regcomp(&COUNT, "count ..*",0);
    regcomp(&SHOW, "show [0-9][0-9]*",0);
    regcomp(&DELETE, "delete [0-9][0-9]*",0);
    regcomp(&DESTROY, "destroy",0);

    struct timespec start, finish;
    struct tms buffer_start, buffer_finish;
    
    while(1){
        char* command = NULL;
        size_t commandSize;
        
        int param = 0;

        char* path = "";
        fputs("rrrreppl>> ",stdout);
        int code = getline(&command,&commandSize,stdin);
        puts("\n");
        clock_gettime(CLOCK_REALTIME,&start);
        times(&buffer_start);
        
        if(regexec(&INIT,command,0,NULL,0)==0){
            if(initialized==1){
                fprintf(stderr,"already initialized\n");
                continue;
            }
            sscanf(command,"init %d", &param);
            obj = Lib1CreateStruct(param);
            initialized = 1;
        }
        else if(regexec(&COUNT,command,0,NULL,0)==0){
            if(initialized==0) {
                fprintf(stderr,"you need to init first\n");
                continue;
            }
            memmove(command,command+6,strlen(command));
            Lib1Count(&obj, command);

        }
        else if(regexec(&SHOW,command,0,NULL,0)==0){
            if(initialized==0) {
                fprintf(stderr,"you need to init first\n");
                continue;
            }
            sscanf(command,"show %d",&param);
            printf("%s",Lib1GetBlock(&obj,param));
        }
        else if(regexec(&DELETE,command,0,NULL,0)==0){
            if(initialized==0) {
                fprintf(stderr,"you need to init first\n");
                continue;
            }
            sscanf(command,"delete %d",&param);
            Lib1RemoveBlock(&obj,param);
        }
        else if(regexec(&DESTROY,command,0,NULL,0)==0){
            if(initialized==0) {
                fprintf(stderr,"you need to init first\n");
                continue;
            }
            Lib1DeleteBlocks(&obj);
            initialized = 0;
        }
        else{
            fprintf(stderr,"wrong/empty command\n");
        }

        clock_gettime(CLOCK_REALTIME,&finish);
        times(&buffer_finish);

        printf("\nreal time: %ldns\n",finish.tv_nsec-start.tv_nsec);
        printf("user time: %ld\n",buffer_finish.tms_utime-buffer_start.tms_utime);
        printf("system time: %ld\n\n",buffer_finish.tms_stime-buffer_start.tms_stime);

        free(command);
    }
}

