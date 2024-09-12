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
                 
                 // pwd
                 if(strcmp(buffer,"pwd")== 0)
                 {
                    char cwd[1024];
                    getcwd(cwd, sizeof(cwd));
                    printf("%s\n",cwd);
                 }  

                 // clear
                 else if(strcmp(buffer,"clear")== 0)
                 {
                    system("@cls||clear");
                 } 

                 // whoami
                 else if(strcmp(buffer,"whoami")== 0)
                 {
                    printf("%s\n",pw->pw_name);
                 } 

                 // ls (not getting param from argv[1])
                 else if(strcmp(buffer,"ls") == 0)
                 {
                   char *arg = ".";
                   ls(arg);
                 }
                 else 
                 {
                        printf("Unknown command...");
                 }
            } 
           
        } else {

        }
    }
}  

// Display files/ dirs with size.
void ls (char *arg)
{
    DIR *mydir;
    struct dirent *myfile;
    struct stat mystat;

    char buf[512];
    mydir = opendir(arg);
    while((myfile = readdir(mydir)) != NULL)
    {
        sprintf(buf, "%s/%s", arg, myfile->d_name);
        stat(buf, &mystat);
        char *name = myfile->d_name;
        if(strchr(name, '.') != NULL)
        {
           printf("%zu .... %s\n",mystat.st_size, myfile->d_name);
        }
    }
    closedir(mydir);
}

// Clear screen
void clearScreen()
{
  system("@cls||clear");
}

// Red Print
void red_print(){
    printf("\033[1;31m");
}

// Red Print
void cyan_print(){
    printf("\033[0;36m");
}

// Reset Print
void reset_print(){
    printf("\033[0m");
}

void print_ps1(char *username, char *hostname)
{
    cyan_print();
    printf("(%s@%s) ", username, hostname);
    red_print();
    printf(" $ ");
    reset_print();
}
