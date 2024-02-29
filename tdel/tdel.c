#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <ftw.h>
#include <windows.h>
// Function to be called for each file/directory
int list_files(const char *fpath, const struct stat *sb, int typeflag) {
    printf("%s\n", fpath);
    return 0; // Return 0 to continue, or non-zero to stop
}

int main() {

    if (ftw("build", list_files, 20) == -1) {
        perror("ftw");
        return 1;
    }

    return 0;
}
