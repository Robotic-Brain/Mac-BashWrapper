
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <regex.h>

const int c_pathArg = 0;    // argument to extract path from

int main(int argc, char* argv[]) {
    int path_len = 0;
    int i = 0;
    while (argv[c_pathArg][i] != '\0') {
        if (argv[c_pathArg][i] == '/') {
            path_len = i;
        }
        ++i;
    }
    
    char* cmd = NULL;
    asprintf(&cmd, "%.*s/../Resources/command.sh", path_len, argv[c_pathArg]);
    if (!cmd) { return EXIT_FAILURE; }
    
    int result = system(cmd);
    free (cmd);
    return result;
}


