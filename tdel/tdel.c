#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <ftw.h>
#include <windows.h>
#include <stdbool.h>
// Function to be called for each file/directory
int list_files(const char *fpath, const struct stat *sb, int typeflag) {
    printf("%s\n", fpath);

    return 0; // Return 0 to continue, or non-zero to stop
}

int silently_remove_directory(LPCTSTR dir) 
{
    int len = strlen(dir) + 2;
    char* tempdir = (char*)malloc(len);
    memset(tempdir, 0, len);
    strcpy(tempdir, dir);

    SHFILEOPSTRUCT file_op = {
        NULL,
        FO_DELETE,
        tempdir,
        NULL,
        FOF_NOCONFIRMATION |
        FOF_NOERRORUI |
        FOF_SILENT,
        false,
        0,
        "" };
    int output = SHFileOperation(&file_op);
    printf("Value of kernet API : %d\n", output);

    return output;
}

int main(int argc, char *argv[]) {

    if (argc == 1) {
        printf("No directory provided to delete");
        return 1;
    }

    char* dir =  argv[1];

    printf("Dir to delete is: %s\n", argv[1]);
    return  silently_remove_directory(dir);
}
