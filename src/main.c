#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <pwd.h>
#include <unistd.h>
#include <stdlib.h>

char *getlogin(void);
struct passwd *pw;
void clear_screen();

int main (int argc, char **argv)
{
    while(1){
        if(isatty(STDIN_FILENO))
        {
            char hostname[1024];
            pw = getpwuid(getuid());
            gethostname(hostname, sizeof(hostname));
            printf("(%s@%s) $ ", pw->pw_name, hostname);

            char buffer[50];
            if(fgets(buffer, sizeof(buffer),stdin) != NULL)
            {
                 // pwd
                 if(strcmp(buffer,"pwd")==10)
                 {
                    char cwd[1024];
                    getcwd(cwd, sizeof(cwd));
                    printf("%s\n",cwd);
                 }  

                 // clear
                 if(strcmp(buffer,"clear")==10)
                 {
                    system("@cls||clear");
                 } 

                 // ls
                 if(strcmp(buffer,"ls") == 10)\
                 {
                   char* argument_list[] = {"ls", "-l", NULL};
                   execve("ls",argument_list,"/bin");
                 }
            } 
            else 
            {
                printf("Unknown command...");
            }

        } else {

        }
    }
}  

// Clear screen
void clearScreen()
{
  system("@cls||clear");
}
