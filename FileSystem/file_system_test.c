/*
 * File System - Test file
 */

#include <string.h>

#include "file_system.h"

#define BUFFER_SIZE (255)

int main(int argc, char *argv[])
{
    char path_name[BUFFER_SIZE] = {0};
    int length = strlen(argv[1]);

    memcpy(path_name, argv[1], length + 1);

    FindByPath(path_name);

    return (0);
}


/*unsigned int block_size = 0;
int main() 
{
    int fd;
    int found = 0;
    char check = 'n';
    struct ext2_super_block super_block;
    struct ext2_group_desc group_desc;
    struct ext2_inode inode;
    struct ext2_inode inode2;
    struct ext2_inode ret_inode;

    char path_name[] = "/home/liorcoeh/mnt/stdio.h";

     Opening the device 
    if (-1 == (fd = open("/dev/ram0", O_RDONLY)))
    {
        perror("Failed to open the device");
        return (1);
    }

    ReadSuperBlock(fd, &super_block);

    block_size = 1024 << super_block.s_log_block_size;

    ReadGroupDescBlock(fd, &group_desc);
    ReadInode(fd, 2, &group_desc, &inode);
    PrintDirectoryFiles(fd, &inode);

    FindByPath(fd, &group_desc, path_name);

    found = FindFileInDir(fd, &group_desc, &inode, "stdio.h", &ret_inode);

    if (found)
    {
        printf("File Was Found, print it [Y/n]?");
        scanf("%c", &check);
        if (('y' == check) || ('Y' == check))
        {
            PrintFile(fd, &ret_inode);
        }
    }

    close(fd);

    return (0);
}*/