/*
 * File System - Functions definitions file
 */

#include <stdio.h>     /* printf() */
#include <stdlib.h>    /* exit() */
#include <string.h>    /* memcpy() */
#include <unistd.h>    /* lseek(), read() */
#include <fcntl.h>     /* O_RDONLY */

#include "file_system.h"

#define FILE_NAME_SIZE (255)

/******************************************************************************/

void ReadSuperBlock(int fd, struct ext2_super_block *super_block)
{
    lseek(fd, 1024, SEEK_SET);
    read(fd, super_block, sizeof(struct ext2_super_block));

    if (EXT2_SUPER_MAGIC != super_block->s_magic)
    {
        printf("Couldn't find the right super block\n");
        exit(1);
    }
}

/******************************************************************************/

void ReadGroupDescBlock(int fd, struct ext2_group_desc *group_desc)
{
    lseek(fd, 1024 + sizeof(struct ext2_super_block), SEEK_SET);
    read(fd, group_desc, sizeof(struct ext2_group_desc));
}

/******************************************************************************/

void ReadInode(int fd, int inode_number,
                const struct ext2_group_desc *group_descriptor,
                struct ext2_inode *ret_inode)
{
    lseek(fd, BLOCK_OFFSET(group_descriptor->bg_inode_table) +
              (inode_number - 1) * sizeof(struct ext2_inode), SEEK_SET);
    read(fd, ret_inode, sizeof(struct ext2_inode));
}

/******************************************************************************/

void PrintDirectoryFiles(int fd, struct ext2_inode *inode)
{
    char block[BLOCK_SIZE];
    struct ext2_dir_entry_2 *entry = (struct ext2_dir_entry_2 *)block;
    unsigned int size = 0;

    char file_name[EXT2_NAME_LEN + 1];

    lseek(fd, BLOCK_OFFSET(inode->i_block[1]), SEEK_SET);
    read(fd, block, BLOCK_SIZE);

    while ((size < inode->i_size) && entry->inode)
    {
        memcpy(file_name, entry->name, entry->name_len);
        file_name[entry->name_len] = '\0';

        /*printf("%10u %s\n", entry->inode, file_name);*/
        printf("%s  ", file_name);
        entry = (void*)entry + entry->rec_len;
        size += entry->rec_len;
    }
    printf("\n\n");
}

/******************************************************************************/

int FindFileInDir(int fd, const struct ext2_group_desc *group_descriptor,
                  struct ext2_inode *inode,
                  char *file_name_to_search,
                  struct ext2_inode *ret_inode)
{
    char block[BLOCK_SIZE];
    struct ext2_dir_entry_2 *entry = (struct ext2_dir_entry_2 *)block;
    unsigned int size = 0;

    char file_name[EXT2_NAME_LEN + 1];

    lseek(fd, BLOCK_OFFSET(inode->i_block[1]), SEEK_SET);
    read(fd, block, BLOCK_SIZE);

    while ((size < inode->i_size) && entry->inode)
    {
        memcpy(file_name, entry->name, entry->name_len);
        file_name[entry->name_len] = '\0';

        if (0 == strcmp(file_name_to_search, file_name))
        {
            /*printf("%10u %s %s\n", entry->inode, file_name);*/
            ReadInode(fd, entry->inode, group_descriptor, ret_inode);
            
            return (entry->inode);
        }
        entry = (void*)entry + entry->rec_len;
        size += entry->rec_len;
    }
}

/******************************************************************************/

void PrintFile(int fd, struct ext2_inode* inode)
{
    char buffer[BLOCK_SIZE + 1] = {0};
    int i = 0;

    for (i = 0; inode->i_block[i] != 0; ++i)
    {
        memset(buffer, 0, BLOCK_SIZE + 1);
        lseek(fd, inode->i_block[i] * BLOCK_SIZE, SEEK_SET);
        read(fd, buffer, BLOCK_SIZE);
        printf("%s\n", buffer);
    }
}

/******************************************************************************/

void FindByPath(char *path_name)
{
    int fd;
    int found = 0;
    char check = 'n';
    struct ext2_super_block super_block;
    struct ext2_group_desc group_desc;
    struct ext2_inode inode;
    struct ext2_inode ret_inode;

    int length = strlen(path_name);
    int i = length;
    int j = 0;
    char file_name[FILE_NAME_SIZE] = {0};

    for (i = length - 1; i > 0; --i)
    {
        if ('/' == path_name[i])
        {
            for (i + 2, j = 0; i < length; ++i, ++j)
            {
                file_name[j] = path_name[i + 1];
            }
            break;
        }
    }

    /* Opening the device */
    if (-1 == (fd = open("/dev/ram0", O_RDONLY)))
    {
        perror("Failed to open the device");
        exit (1);
    }

    ReadSuperBlock(fd, &super_block);

    block_size = 1024 << super_block.s_log_block_size;

    ReadGroupDescBlock(fd, &group_desc);
    ReadInode(fd, 2, &group_desc, &inode);
    PrintDirectoryFiles(fd, &inode);

    found = FindFileInDir(fd, &group_desc, &inode, file_name, &ret_inode);

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
}

/*void FindByPath(int fd, struct ext2_group_desc *group_descriptor,
                char *path_name)
{
    /*struct ext2_inode inode;
    struct ext2_inode f_inode;
    char check = 'n';
    const char s[2] = "/";
    char *token = NULL;
    int found = 0;

    ReadInode(fd, 2, group_descriptor, &inode);

    token = strtok(path_name, s);

    while (S_ISDIR(inode.i_mode) && NULL != token)
    {
        found = FindFileInDir(fd, group_descriptor, &inode, token, &f_inode);
        token = strtok(NULL, s);
        inode = f_inode;
    }

    if (found)
    {
        printf("File Was Found, Print It [Y/n]?");
        scanf("%c", &check);
        if (('y' == check) || ('Y' == check))
        {
            PrintFile(fd, &f_inode);
        }
    }
    else
    {
        printf("File Not Found\n");
    }
}*/







