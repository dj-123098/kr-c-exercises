// ex8-05(dirent).h -- fsize header

#define NAME_MAX 14 // longest filename component

// portable directory entry
typedef struct
{
    long ino;               // inode number
    char name[NAME_MAX+1];  // name + '\0' terminator
} Dirent;

// minimal DIR: no buffering, etc
typedef struct
{
    int fd;     // file descriptor for the directory
    Dirent d;   // the directory entry
} DIR;

DIR *opendir(char *dirname);
Dirent *readdir(DIR *dfd);
void closedir(DIR *dfd);