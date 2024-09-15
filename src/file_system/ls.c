#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

/// @brief Display files/ dirs with size.
/// @param arg Path of directory.
void ls (char *arg)
{
    DIR *mydir;
    struct dirent *myfile;
    struct stat mystat;

    char buf[512];
    mydir = opendir(arg);
    if(mydir)
    {
        while((myfile = readdir(mydir)))
        {
            sprintf(buf, "%s/%s", arg, myfile->d_name);
            stat(buf, &mystat);
            char *name = myfile->d_name;
            printf("%zu .... %s\n",mystat.st_size, myfile->d_name);
        }
        closedir(mydir);
    }else{
        printf("Directory does not exist: %s !\n", arg);
    }
}
