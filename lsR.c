#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void    ls_r(char *path)
{
    DIR             *dir;
    struct dirent   *entry;
    struct stat     statbuf;
    char            newpath[1024];

    if ((dir = opendir(path)) == NULL)
    {
        perror("opendir");
        return;
    }
    printf("%s:\n", path);
    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        printf("  %s\n", entry->d_name);
        snprintf(newpath, sizeof(newpath), "%s/%s", path, entry->d_name);
        if (lstat(newpath, &statbuf) == -1)
        {
            perror("lstat");
            continue;
        }
        if (S_ISDIR(statbuf.st_mode))
            ls_r(newpath);
    }
    closedir(dir);
}

int     main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    ls_r(argv[1]);
    return 0;
}