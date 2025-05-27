#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 42
#include <string.h>
char *ft_strdup(char *old)
{
    char *new = malloc(sizeof(char ) * (strlen(old) + 1));
    int i = 0;
    while(i < strlen(old))
    {
        new[i] = old[i];
        i++;
    }
    new[i] = '\0';
    return new;
}
int ft_strncmp(char *a, char *b, int len)
{
    int i = 0;
    while(i < len)
    {
        if(a[i] != b[i])
        {
            return (unsigned char)a[i] - (unsigned char)b[i];
        }
        i++;
    }
    return 0;
}
int main(int ac, char **av)
{
    if(ac != 2)
    {
        perror("arg not ok\n");
        return 1;
    }
    char *word_hiden = ft_strdup(av[1]);
    int len_word = strlen(word_hiden);
    if(len_word == 0)
    {
        free(word_hiden);
        return 0;
    }
    char buffer[BUFFER_SIZE];
    char *input_echo = malloc(sizeof(char ) * (BUFFER_SIZE + 1));
    if(!input_echo)
    {
        free(word_hiden);
        return 1;
    }
    int byte;
    int len_total;
    len_total = 0;
    while((byte = read(STDIN_FILENO,buffer,BUFFER_SIZE)) > 0)
    {
        char *tmp = realloc(input_echo,len_total + byte + 1);
        if(!tmp || byte <= 0)
        {
            perror("allocation fail \n");
            return 1; 
        }
        input_echo = tmp;
        memmove(input_echo,buffer, byte);
        len_total += byte;
        input_echo[len_total] = '\0';
    }
    fprintf(stdout,"%s",input_echo);
    char *pointer = input_echo;
    while(*pointer)
    {
        if(ft_strncmp(pointer,word_hiden,len_word) == 0)
        {
            int j = 0;
            while(j < len_word)
            {
                pointer[j] = '*';
                j++;
            }
        }
        pointer++;
    }
    fprintf(stdout,"%s",input_echo);
    free(input_echo);
    return 0;
}