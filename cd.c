#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include "uint32_to_str.h"
#include "file_path.h"


void cd(char* fileDir, struct file_path *cwd){
    char curd[1024];
    // printf("%s", fileDir);
    // printf("cwd: %s\n", getcwd(curd, sizeof(curd)));
    // chdir(fileDir);
    // printf("cwd: %s\n", getcwd(curd, sizeof(curd)));
    // printf("cwd: %s\n", getcwd(curd, sizeof(curd)));
    // chdir("..");
    // printf("cwd: %s\n", getcwd(curd, sizeof(curd)));

    // printf("cwd: %s\n", getcwd(curd, sizeof(curd)));
    if (chdir(fileDir) == -1) {
        perror("Error: Unable to change directory");
        printf("cwd: %s\n", getcwd(curd, sizeof(curd)));
    } else if (fileDir == NULL){
        while (!is_empty(cwd)){
            pop(cwd);
            chdir("..");
        }
    } else if (strcmp(".", fileDir)){
        //do nothing
    } else if (strcmp("..", fileDir)){
        pop(cwd);
    } else {
        push(cwd, *fileDir);
    }
    return;
}