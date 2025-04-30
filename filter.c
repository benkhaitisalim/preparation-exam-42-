#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

int ft_strlen(const char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return i;
}
int ft_strncmp(const char *s1, const char *s2,int n)
{
    int i  = 0;
    int j = 0;
    while(s1[i] && s2[j] && s1[i] == s2[j] && i < n)
    {
        i++;
    }
    return((unsigned char)s1[i] - (unsigned char)s2[i]);
}
void *ft_memcpy(char *dst, char *src, size_t n)
{
    int i = 0;
    while(i < n)
    {
        dst[i] = src[i];
        i++; 
    }
}
int main(int ac, char **av)
{
    if (ac != 2)
    {
        perror("error");
        return 1;
    }
    char *word = av[1];
    int word_len = ft_strlen(word);
    char buffer[BUFFER_SIZE];
    char *input = malloc(1);
    int total_len = 0;
    int bytes;

    while ((bytes = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0)
    {
        char *tmp = realloc(input, total_len + bytes + 1);
        if (!tmp)
        {
            perror("realloc failed");
            free(input);
            return 1;
        }
        input = tmp;
        memmove(input + total_len, buffer, bytes);
        total_len += bytes;
        input[total_len] = '\0';
    }
    printf("%s\n",input);
    char *p = input;
    int i = 0;
    int j = 0;
    while (p[i])
    {
        if (ft_strncmp(p, word,i) == 0)
        {
            j = 0;
            while(av[j])
            {
                p[i] = '*';
                i++;
                j++;
            }
        }
        else
        {
            i++;
        }
    }
    printf("%s\n",input);

    free(input);
    return 0;
}
