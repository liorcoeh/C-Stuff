/*
 * File System
 */

#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include <linux/fs.h>
#include </usr/include/ext2fs/ext2_fs.h>
#include <linux/types.h>

#define BASE_OFFSET (1024)  /* location of the super-block in the first group */
#define BLOCK_OFFSET(block) (BASE_OFFSET + (block - 1) * block_size)

unsigned int block_size;

/* Reads the first (most important) super block */
void ReadSuperBlock(int fd, struct ext2_super_block *super_block);

/* Reads the group descriptor block */
void ReadGroupDescBlock(int fd, struct ext2_group_desc *group_desc);

/* Reads the inode */
void ReadInode(int fd, int inode_number,
               const struct ext2_group_desc *group_descriptor,
               struct ext2_inode *ret_inode);

/* Reads the directory files */
void PrintDirectoryFiles(int fd, struct ext2_inode *inode);

/* Given inode of a directory, find inode to the requested file name: */
int FindFileInDir(int fd, const struct ext2_group_desc *group_descriptor,
                  struct ext2_inode *inode,
                  char *file_name_to_search,
                  struct ext2_inode *ret_inode);

/* Given an inode of a file, print the file: */
void PrintFile(int fd, struct ext2_inode* inode);

/* Finding the file by it's path */
void FindByPath(char *path_name);
/*void FindByPath(int fd, struct ext2_group_desc *group_descriptor,
                char *path_name);*/


#endif /* FILE_SYSTEM_H */