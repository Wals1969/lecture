#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

void showStatInfo(const char *fname, struct stat *buf);

int main(int argc, char *argv[])
{
    struct stat info; 

    if (argc > 1)
    {
        if (stat(argv[1], &info) != -1)
        {
            showStatInfo(argv[1], &info);
            return 0;
        }
        else
        {
            perror(argv[1]); 
        }
    }
    return 1;
}

/**
 * @brief Displays some info from stat in name=value format
 * 
 * @param fname  filename
 * @param buf    stat information for the filename
 */
void showStatInfo(const char *fname, struct stat *buf)
{
    printf("   mode: %o\n", buf->st_mode);
    printf("  links: %ld\n", buf->st_nlink);
    printf("   user: %d\n", buf->st_uid);
    printf("  group: %d\n", buf->st_gid);
    printf("   size: %ld\n", buf->st_size);
    printf("modtime: %ld\n", buf->st_mtime);
    printf("   name: %s\n", fname);
}