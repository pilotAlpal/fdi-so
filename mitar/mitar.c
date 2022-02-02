#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "mitar.h"

int main(int argc, char *argv[]) {
    int c;
    char *ifile;
    extern char *optarg;
    extern int optopt;
    flags flag = NONE;

    while ((c = getopt(argc, argv, ":cxf:")) != -1) {
        switch(c) {
        case 'x':
            if (flag != CREATE) {
                flag = EXTRACT;
            }
            else {
                fprintf(stderr,
                        "Can not extract and compress\n");
                flag = ERROR;
                    
            }
            break;
        case 'c':
            if (flag != EXTRACT) {
                flag = CREATE;
            }
            else {
                fprintf(stderr,
                        "Can not extract and compress\n");
                flag = ERROR;
            }
            break;
        case 'f':
            ifile = optarg;
            break;
        case '?':
                    fprintf(stderr,
                            "Unrecognized option: -%c\n", optopt);
        }
    }

    if (flag == CREATE) {
        char **fNames = &argv[optind];
        int c_tar = createTar(argc - optind, fNames, ifile);
    } else if (flag == EXTRACT) {
        int e_tar = extractTar(ifile);
    } else {
                    fprintf(stderr,
                            "Either extract or compress\n");
    }
}
