#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#define BUFFER_SIZE 42
char *ft_strdup(char *old)
{
    char *new_copy = malloc(sizeof(char * ) * (strlen(old) + 1));
    int i = 0;
    while(i < strlen(old))
    {
        new_copy[i] = old[i];
        i++;
    }
    new_copy[i] = '\0';
    return new_copy;
}
int main(int ac ,char **av)
{
    if(ac != 2)
        return 1;
    char *word = ft_strdup(av[1]);
    if(!word)
    {
        return 1;
    }
    int len_word = strlen(word);
    if(len_word == 0)
    {
        perror("bla taneez rah input khawi \n");
        return 1;
    }
    int len_total = 0;
    int byte;
    char *input = malloc(sizeof(char) * BUFFER_SIZE);
    char buffer[BUFFER_SIZE];
    while((byte = read(0,buffer,BUFFER_SIZE)) > 0)
    {
        char *temporary = realloc(input, len_total + byte + 1);
        if(!temporary)
        {
            perror("error : ");
            return 1;
        }
        temporary = input;
        memmove(input + len_total, buffer, byte);
        len_total += byte;
        input[len_total] = '\0';
    }
    char *pointer_to_input = input;
    while(*pointer_to_input)
    {
        if(strncmp(pointer_to_input,word,len_word) == 0)
        {
            int j = 0;
            while(j < len_word)
            {
                pointer_to_input[j] = '*';
                j++;
            }
        }
        pointer_to_input++;
    }
    fprintf(stdout,"%s",input);
    free(input);
    return 0;
}