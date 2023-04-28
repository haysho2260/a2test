/*
mkdir
    -check to see if directory already exists in the current directory
    record the current directory for ..
    makes a new inode in my ind list
    add to inodes_list (inode and file type d)
    make new file with fopen("", "wb")
    write to current directory with new inode number and file name
*/


/*
touch
    makes a new inode in my ind list
    add to inodes_list (inode and file type f)
    write to current directory with new inode number and file name
*/
void touch(char* fileDir, int* cwd, char indlst[], int* indSize);