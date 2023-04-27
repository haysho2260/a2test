#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include "uint32_to_str.h"
#include "file_path.h"


void cd(char* fileDir, char* cwd){
    if (chdir(fileDir) == -1) {
        perror("Error: Unable to change directory");
        exit(EXIT_FAILURE);
    } 
    if ()
    return 0;
}