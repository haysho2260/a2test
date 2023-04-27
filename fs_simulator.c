#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include "find_dir.h"
#include "init_sim.h"
#include "ls.h"


int main(int argc, char *argv[]) {
    int cwd[1024] = {-1};
    char rsp[40];
    char *cmd, *name;
    find_dir(argv[1]);
    init_sim(argv[1], cwd);
    while (1){
        printf("> ");
        scanf("%s", rsp);
        cmd = strtok(rsp, " ");
        name = strtok(NULL, " ");
        if (!strcmp("ls", cmd)){
            ls(cwd);
        } else if (!strcmp("exit", cmd)) {

        }
        
        // if (argv[1] == "cd"){

        // } else if (argv[1] == "ls"){

        // } else if (arg[1] == "mkdir") {

        // } else if (arg[1] == "touch"){

        // }
    }
    return 0;

}





