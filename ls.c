#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include "uint32_to_str.h"
#include "file_path.h"

int ls(char* cwd){
    uint32_t num;
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
