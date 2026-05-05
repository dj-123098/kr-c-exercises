// ex8-04(syscalls).c -- implement fseek

#include <fcntl.h>
#include "ex8-04(syscalls).h"

#define PERMS 0666 // RW for owner, group, others

// fopen: open file, return file ptr
FILE *fopen(char *name, char *mode)
{
    int fd;
    FILE *fp;

    if (*mode != 'r' && *mode != 'w' && *mode != 'a')
        return NULL;

    for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
        if ((fp->flag & (_READ | _WRITE)) == 0)
            break;

    if (fp >= _iob + OPEN_MAX)
        return NULL;

    if (*mode == 'w')
        fd = creat(name, PERMS);
    else if (*mode == 'a')
    {
        if ((fd = open(name, O_WRONLY, 0)) == -1)
            fd = creat(name, PERMS);
        lseek(fd, 0L, 2);
    }
    else
        fd = open(name, O_RDONLY, 0);

    if (fd == -1)
        return NULL;

    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    fp->flag = (*mode == 'r') ? _READ : _WRITE;

    return fp;
}

// _fillbuf: allocate and fill input buffer
int _fillbuf(FILE *fp)
{
    int bufsize;

    if ((fp->flag & (_READ | _EOF | _ERR)) != _READ)
        return EOF;

    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;

    if (fp->base == NULL)
        if ((fp->base = (char *) malloc(bufsize)) == NULL)
            return EOF;

    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);

    if (--fp->cnt < 0)
    {
        if (fp->cnt == -1)
            fp->flag |= _EOF;
        else
            fp->flag |= _ERR;
        fp->cnt = 0;
        return EOF;
    }

    return (unsigned char) *fp->ptr++;
}

// fseek: set position of file to offset, according to origin
int fseek(FILE *fp, long offset, int origin)
{
    unsigned bufsize;

    if ((fp->flag & (_READ | _WRITE)) == 0)
        return -1;
    if (fp->flag & _WRITE)
        if (fflush(fp) == EOF)
            return -1;
    else if (fp->flag & _READ)
    {
        if (origin == 1)
            offset -= fp->cnt;
        fp->cnt = 0;
        fp->ptr = fp->base;
    }
    if (lseek(fp->fd, offset, origin) == -1)
    {
        fp->flag |= _ERR;
        return -1;
    }
    fp->flag &= ~_EOF;
    return 0;
}

// stdin, stdout, stderr
FILE _iob[OPEN_MAX] =
{
    { 0, (char *) 0, (char *) 0, _READ, 0 },
    { 0, (char *) 0, (char *) 0, _WRITE, 1 },
    { 0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2 }
};