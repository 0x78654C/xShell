/*

  main.c - Simple shell for linux.

 */


#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <pwd.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include "UI/color_print.c"
#include "file_system/ls.c"

char *getlogin(void);
struct passwd *pw;
void clear_screen();
void ls( char *arg);
void red_print();
void reset_print();
void cyan_print();
void print_ps1(char *username, char *hostname);

// Entry point
int main (int argc, char *argv[])
{
    while(1){
        if(isatty(STDIN_FILENO))
        {
            char hostname[1024];

            //Get user name
            pw = getpwuid(getuid());

            //Get hostname
            gethostname(hostname, sizeof(hostname));

            //Print ps1
            print_ps1(pw->pw_name, hostname);

            // Get commands
            char buffer[50];
            if(fgets(buffer, sizeof(buffer),stdin) != NULL)
            {
                buffer[strcspn(buffer, "\n")] = 0;  // Remove newline
                char *cmd = strtok(buffer," ");
                char *param = strtok(NULL," ");
                char cwd[1024];

                 // pwd
                 if(strcmp(cmd,"exit")== 0)
                 {
                    printf("%s\n","Exiting xShell...");
                    return 0;
                 } 

                 // pwd
                 if(strcmp(cmd,"pwd")== 0)
                 {
                    getcwd(cwd, sizeof(cwd));
                    printf("%s\n",cwd);
                 }  

                 // clear
                 else if(strcmp(cmd,"clear")== 0)
                 {
                    system("@cls||clear");
                 } 

                 // whoami
                 else if(strcmp(cmd,"whoami")== 0)
                 {
                    printf("%s\n",pw->pw_name);
                 } 

                 // ls (not getting param from argv[1])
                 else if(strcmp(cmd,"ls") == 0)
                 {
                    if(param != NULL)
                    {
                        if(strcmp(param,"/")==0)
                        {
                            ls(param);
                        }
                        else
                        {
                            getcwd(cwd, sizeof(cwd));
                            char  split[]  = "/";
                            strcat(cwd, split);
                            strcat(cwd, param);
                            ls(param);
                        }
                    }
                    else
                    {
                        ls(".");
                    }
                 }
                 else 
                 {
                    printf("Unknown command...\n");
                 }
            } 
        } 
    }
}  