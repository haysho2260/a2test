#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include "uint32_to_str.h"


int ls(char* cwd){
    uint32_t num;
    // char ch;
    // char lst[1024] = {'\0'};

    // FILE *fp = fopen("inodes_list", "rb");
    // if (fp == NULL) {
    //     perror("Failed to open file");
    //     return 1;
    // }

    // // read values and get list of all inodes
    // while (fread(&num, sizeof(num), 1, fp) == 1 &&
    //         fread(&ch, sizeof(ch), 1, fp) == 1){
    //     if ((num < 0) || (num > 1023)){
    //             printf("Inode: %d is invalid\n", num);
    //     } else {
    //         lst[num] = ch;
    //         // printf("num: %u, char: %c\n", num, ch);
    //     }
    // }
    // fclose(fp);
    char fname[33];
    int i = 0;
    while(cwd[i++] != '\0');
    FILE *fp = fopen(uint32_to_str(cwd[i--]), "rb");
    if (fp == NULL) {
        perror("Failed to open file");
        return 1;
    }
    while (fread(&num, sizeof(num), 1, fp) == 1 &&
    fread(&fname, 32, 1, fp) == 1){
        printf("%d %s\n", num, fname);
    }

    fclose(fp);
    return 0;
}
