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
    char rsp[40];
    char* cmd;
    char* name;
    find_dir(argv[1]);
    init_sim(argv[1], &cwd);
    while (1){
        printf("> ");
        scanf("%s", rsp);
        cmd = strtok(rsp, " ");
        name = strtok(NULL, " ");

        printf("%s\n", cmd);
        printf("name %s\n", name);
        if (!strcmp("ls", cmd)){
            ls((&cwd)->cur);
        } 
        if (!strcmp("cd", cmd)){
            cd(name, &cwd);
        }
        else if (!strcmp("exit", cmd)) {

        }
        
    }
    return 0;

}






