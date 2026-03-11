#ifndef PASSWORD_MANAGER
# define PASSWORD_MANAGER
#include <unistd.h>
#include <fcntl.h>


int ft_strcmp(char *s1, char *s2 );
void ft_putstr(char *str); 
void ft_putchar(char c);
char *ft_strcpy(char *dest, char *src);
int ft_strlen(char *str); 

struct credential
{
    char *site;
    char *id;
    char *password; 
};

//struct credential *add_credential();
int write_credential(struct credential *my_credential);
struct credential *add_credential();
void free_credential(struct credential *my_credential);
int verif_format(char *site);
int list_credential();
int connexion(char *str);
char *first_connexion(); 
#endif