#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>

int find_dir(char* fileDir);

int main(int argc, char *argv[]) {
    find_dir(argv[1]);
    chdir("./empty");
    FILE *fp = fopen("inodes_list", "rb");
    if (fp == NULL) {
        perror("Failed to open file");
        return 1;
    }
    uint32_t num;
    char ch;
    char inodes[1024];
    while (fread(&num, sizeof(num), 1, fp) == 1 &&
            fread(&ch, sizeof(ch), 1, fp) == 1){
        if ((0 <= num) && (num <= 1023)){
            inodes[num] = ch;
        } else{
            printf("Inode: %d is invalid\n", num);
        }
    }
    fclose(fp);
    return 0;

}

int find_dir(char* fileDir){
    if (access(fileDir, F_OK) == 0){
        printf("Successfully found %s\n", fileDir);
    }
    else {
        perror("Error: ");
        printf("errno = %d\n", errno);
    }
    return 0;
}


int init_sim(){
    chdir("./empty");
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
        // char inode[1024];
        // if ((0 <= num) && (num <= 1023)){
            //inodes[num] = ch;
        // } else{
        //    printf("Inode: %d is invalid\n", num);
        // }
    }
    fclose(fp);
    return 0;
}
