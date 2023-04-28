#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include "find_dir.h"
#include "init_sim.h"
#include "ls.h"
#include "cd.h"
#include "file_path.h"


int main(int argc, char *argv[]) {
    struct file_path cwd;
    char cmd[40];
    char name[40];
    find_dir(argv[1]);
    init_sim(argv[1], &cwd);
    while (1){
        printf("> ");
        scanf("%s %s", cmd, name);
        if (!strcmp("ls", cmd)){
            ls(&cwd);
        } 
        if (!strcmp("cd", cmd)){
            cd(name, &cwd);
        }
        else if (!strcmp("exit", cmd)) {

        }
        
        // if (argv[1] == "cd"){

        // } else if (argv[1] == "ls"){

        // } else if (arg[1] == "mkdir") {

        // } else if (arg[1] == "touch"){

        // }
    }
    return 0;

}





