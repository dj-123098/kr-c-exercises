// ex8-03(syscalls).c -- implement _flushbuff, fflush, fclose

#include <fcntl.h>
#include "ex8-03(syscalls).h"

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

// fclose: open file, return 0 if succeed
int fclose(FILE *fp)
{
    int fd;

    if (fp == NULL)
        return EOF;
    fd = fp->fd;
    fflush(fp);
    if (fp->base != NULL)
        free(fp->base);
    fp->ptr = NULL;
    fp->cnt = 0;
    fp->base = NULL;
    fp->flag = 0;

    return close(fd);
}

// fflush: flush buffer
int fflush(FILE *fp)
{
    if (fp->flag & _WRITE == 0)
        return EOF;
    if (_flush_buffer('0', fp) == EOF)
        return EOF;
    fp->ptr = fp->base;
    fp->cnt = (fp->flag & _UNBUF == 0) ? BUFSIZ : 1;
    return 0;
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

//_flushbuf: flush buffer
int _flushbuf(int c, FILE *fp)
{
    unsigned bufsize, n;

    if ((fp->flag & (_WRITE | _ERR)) != _WRITE)
        return EOF;
    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    if (fp->base == NULL)
        if ((fp->base = (char *) malloc(bufsize)) == NULL)
            return EOF;
    else
    {
        n = fp->ptr - fp->base;
        if (write(fp->fd, fp->base, n) != n)
        {
            fp->flag |= _ERR;
            return EOF;
        }
    }
    fp->ptr = fp->base;
    *fp->ptr++ = c;
    fp->cnt = bufsize - 1;
    
    return c;
}

// stdin, stdout, stderr
FILE _iob[OPEN_MAX] =
{
    { 0, (char *) 0, (char *) 0, _READ, 0 },
    { 0, (char *) 0, (char *) 0, _WRITE, 1 },
    { 0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2 }
};