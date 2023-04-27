#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include "file_path.h"

int init_sim(char* fileDir, char* cwd){
    chdir(fileDir);
    FILE *fp = fopen("inodes_list", "rb");
    if (fp == NULL) {
        perror("Failed to open file");
        return 1;
    }
    uint32_t num;
    char ch;
    while (fread(&num, sizeof(num), 1, fp) == 1 &&
            fread(&ch, sizeof(ch), 1, fp) == 1){
        if ((num < 0) || (num > 1023)){
                printf("Inode: %d is invalid\n", num);
        }
    }
    fclose(fp);
    cwd[0] = 0;
    return 0;
}