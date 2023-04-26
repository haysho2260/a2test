#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>

int find_dir(char* fileDir){
    if (access(fileDir, F_OK) == 0){
        printf("Successfully found %s\n", fileDir);
    }
    else {
        perror("Error");
        printf("errno = %d\n", errno);
    }
    return 0;
}