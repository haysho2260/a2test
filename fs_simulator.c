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
#include "touch.h"
#include "mkdir.h"


int main(int argc, char *argv[]) {
    // struct file_path cwd;
    int cwd, indSize=0;
    char cmd[6], name[33], rsp[39];
    char indlst[1024] = {'\0'};
    find_dir(argv[1]);
    init_sim(argv[1], &cwd, indlst, &indSize);
    while (1){
        printf("> ");
        fgets(rsp, 100, stdin);
        sscanf(rsp, "%s %s", cmd, name);
        name[32] = '\0';
        if (!strcmp("ls", cmd)){
            ls(cwd);
        } 
        else if (!strcmp("cd", cmd)){
            cd(name, &cwd, indlst);
        }
        else if (!strcmp("touch", cmd)){
            touch(name, &cwd, &indSize);
        }
        else if (!strcmp("mkdir", cmd)){
            mkdir(name, &cwd, indlst, &indSize);
        }
        else if (!strcmp("exit", cmd)) {
           return 0;
        }
    }
    return 0;

}






