#include <stdlib.h>
#include <unistd.h>
#include <string.h>
void ft_swap(char *a , char *b)
{
    char c = *a;
    *a = *b;
    *b = c;
}

int permatation(char *input,int len_total)
{
    int i = len_total - 2;
    while(i >= 0 && input[i] >= input[i + 1])
    {
        i--;
    }
    if(i < 0)
    {
        return 0;
    }
    int j = len_total - 1;
    while(j >= 0 && input[j] <= input[i])
    {
        j--;
    }
    ft_swap(&input[i],&input[j]);
    int left = i + 1;
    int right = len_total - 1;
    while(left < right)
    {
        ft_swap(&input[left],&input[right]);
        right--;
        left++;
    }
    return 1;
}
int ft_strlen(char *s)
{
    int i = 0;
    while(s[i])
    {
        i++;
    }
    return i;
}
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
int main(int ac, char **av)
{
    if(ac != 2)
    {
        return 1;
    }
    char *input = ft_strdup(av[1]);
    if(!input)
        return 1;
    int len_input = ft_strlen(input);
    if(len_input == 0)
    {
        return 1;
    }
    int i = 0;
    while(input[i])
    {
        int j = i + 1;
        while(input[j])
        {
            if(input[i] > input[j])
            {
                ft_swap(&input[i],&input[j]);
            }
            j++;
        }
        i++;
    }
    write(1,input,strlen(input));
    write(1,"\n",1);
    while(permatation(input,len_input))
    {
        write(1,input,strlen(input));
        write(1,"\n",1);
    }
    return 0;

}
