#ifndef _MITAR_H
#define _MITAR_H

#include <limits.h>

typedef enum{
    NONE,
    ERROR,
    CREATE,
    EXTRACT
} flags;

typedef struct {
    char *name;
    unsigned int size;
} stHeaderEntry;

int createTar(int nFiles, char *fileNames[], char tarName[]);

int extractTar(char tarName[]);

static const char * stHeadFormat = "%s\n%d\n";
static const char * numFilesInTarFormat = "%d\n";

#endif /* _MITAR_H */
