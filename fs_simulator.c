#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>


int main(int argc, char *argv[]) {
    if (chdir(argv[1]) != -1){
        printf("Success reading directory!\n");
    }
    else {
        perror("chdir failed");
        printf("errno = %d\n", errno);
    }
    FILE *fp = fopen("inodes_list", "rb");
    if (fp == NULL) {
        perror("Failed to open file");
        return 1;
    }
    int byte;
    while ((byte = fgetc(fp)) != EOF) {
        printf("%02x\n", byte);
    }
    fclose(fp);
    return 0;

}
