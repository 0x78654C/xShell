#include <unistd.h>
#include <stdio.h>
// pwd command display.
void pwd_show()
{
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("%s\n",cwd);
}