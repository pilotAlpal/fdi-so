#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mitar.h"

int copynFile(FILE *ori, FILE *dest, int nBytes);
int readHeader(FILE *tarFile, stHeaderEntry **header, int *nFiles);

int createTar(int nFiles, char *filenames[], char tarName[]) {
    printf("Creating tar..\n");

    stHeaderEntry *stHeaders = (stHeaderEntry *) malloc(sizeof(stHeaderEntry) * (nFiles));

    FILE * tar_file = fopen(tarName, "w+");
    int wr_num_f = fprintf(tar_file, numFilesInTarFormat, nFiles);

    // write files name and size 2 tarfile
    int i;
    for (i = 0; i < nFiles; i++) {
        stHeaders[i].name = filenames[i];
        FILE * file2tar = fopen(filenames[i], "r");
        fseek(file2tar, 0L, SEEK_END);
        stHeaders[i].size = (int) ftell(file2tar);
        fclose(file2tar);
        int wr_st_h = fprintf(tar_file, stHeadFormat, stHeaders[i].name, stHeaders[i].size);
    }

    // write files content to tarfile
    int copied = 0;
    for (i = 0; i < nFiles; i++) {
        FILE * file2tar = fopen(filenames[i], "r");
        copied += copynFile(file2tar, tar_file, stHeaders[i].size);
        fclose(file2tar);
    }
    fclose(tar_file);
    return 0;
}

int extractTar(char tarName[]) {
    FILE * tar_file = fopen(tarName, "r");
    stHeaderEntry **stHeads = (stHeaderEntry **) malloc(sizeof(int));
    int *nFiles = malloc(sizeof(int));
    int rh = readHeader(tar_file, stHeads, nFiles);
    int i;
    for (i = 0; i < *nFiles; i++) {
        printf("Creating file %s, size: %d(B)\n", stHeads[i]->name, stHeads[i]->size);
        FILE * extr_f = fopen(stHeads[i]->name, "w+");
        int cnf = copynFile(tar_file, extr_f, stHeads[i]->size);
        fclose(extr_f);
    }
    fclose(tar_file);
    return 0;
}

/** Copy nBytes bytes from the origin file to the destination file.
 *
 * origin: pointer to the FILE descriptor associated with the origin file
 * destination:  pointer to the FILE descriptor associated with the destination file
 * nBytes: number of bytes to copy
 *
 * Returns the number of bytes actually copied or -1 if an error occured.
 */
int copynFile(FILE * origin, FILE * destination, int nBytes) {
    char *buffer = malloc(2048 * sizeof(char));
    size_t n_read = fread(buffer, sizeof(char), nBytes, origin);
    size_t n_write = fwrite(buffer, sizeof(char), nBytes, destination);

    if (n_read != n_write) {
        return -1;
    }
    return n_read;
}

int readHeader(FILE *tarFile, stHeaderEntry **header, int *nFiles){
    int read_num_files = fscanf(tarFile, numFilesInTarFormat, nFiles);
    printf("%d files in tar\n", *nFiles);

    int i;
    int *fi_size = malloc(sizeof(int));
    for (i = 0; i < *nFiles; i++) {
        header[i] = (stHeaderEntry *) malloc(sizeof(stHeaderEntry));
        char *fi_name = (char *)malloc(PATH_MAX * sizeof(char));
        /*
        header[i]->name = (char *) malloc(PATH_MAX * sizeof(char));
        int read_st_h = fscanf(tarFile, stHeadFormat, header[i]->name, &header[i]->size);
        */
        int read_st_h = fscanf(tarFile, stHeadFormat, fi_name, fi_size);

        header[i]->name = fi_name;
        header[i]->size = *fi_size;

        printf("File %s, size (B): %d\n", header[i]->name, header[i]->size);

    }
    
    return 0;
}

