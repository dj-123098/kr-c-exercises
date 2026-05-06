// ex8-05(sys_dir).h -- fsize header

#ifndef DIRSIZ
#define DIRSIZ 14
#endif

#include <sys/types.h>

// directory entry
struct direct
{
    ino_t d_ino;         // inode number
    char d_name[DIRSIZ]; // long name does not have '\0'
};