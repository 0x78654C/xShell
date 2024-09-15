#include <stdio.h>

/// @brief Clear screen
void clearScreen()
{
  system("@cls||clear");
}

/// @brief Print cyan
void red_print(){
    printf("\033[1;31m");
}

/// @brief Red Print
void cyan_print(){
    printf("\033[0;36m");
}

/// @brief Reset Print
void reset_print(){
    printf("\033[0m");
}

/// @brief Print ps1 info.
/// @param username 
/// @param hostname 
void print_ps1(char *username, char *hostname)
{
    cyan_print();
    printf("(%s@%s) ", username, hostname);
    red_print();
    printf(" $ ");
    reset_print();
}
