#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include "uint32_to_str.h"

int ls(uint32_t cur){
    uint32_t num;
    char fname[33];
    FILE *fp = fopen(uint32_to_str(cur), "rb");
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
