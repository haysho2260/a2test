#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include "uint32_to_str.h"
#include "make.h"
/*
touch
    makes a new inode in my ind list
    add to inodes_list (inode and file type f)
    write to current directory with new inode number and file name
*/
void touch(char *fileDir, int *cwd, int* indSize){
    if (!check_dupe(cwd, fileDir)){
        append_inodes(indSize, "f");
        add_file_to_cwd(fileDir, cwd, indSize);
    }
    return;
}
