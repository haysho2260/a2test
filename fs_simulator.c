#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include "find_dir.h"
#include "init_sim.h"


int main(int argc, char *argv[]) {
    char cwd[1024];
    char rsp[40];
    ;
    find_dir(argv[1]);
    init_sim(argv[1], cwd);
    while (){
        printf("> ");
        scanf("%s", &num);
        char cmd[] = strtok(rsp, ",");
        char name[] = strtok(rsp, ",")
        if (strcmp("ls", cmd)){
            ls();
        } else if (cmd == "exit") {

        }
        
        // if (argv[1] == "cd"){

        // } else if (argv[1] == "ls"){

        // } else if (arg[1] == "mkdir") {

        // } else if (arg[1] == "touch"){

        // }
    }
    return 0;

}





