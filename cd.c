#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include "uint32_to_str.h"
#include "file_path.h"


void cd(char* fileDir, struct file_path *cwd){
    if (chdir(fileDir) == -1) {
        perror("Error: Unable to change directory");
        exit(EXIT_FAILURE);
    } else if (strcmp(".", fileDir)){

    } else if(strcmp("..", fileDir)){
        pop(cwd);
    } else if (fileDir == NULL){
        while ()
    } else {
        push(cwd, fileDir);
    }
    printf("%d", (cwd->cur));
    return;
}