#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void ft_swap(char *a, char *b)
{
    char c = *a;
    *a = *b;
    *b = c;
}
int permetation_generate(char *input,int len_input)
{
    int i = len_input - 2;
    while(i >= 0 && input[i] > input[i + 1])
    {
        i--;
    }
    if(i < 0)
    {
        return 0;
    }
    int j = len_input - 1;
    while(j >= 0 && input[j] <= input[i])
    {
        j--;
    }
    ft_swap(&input[i],&input[j]);
    int right = len_input - 1;
    int left = i + 1;
    while(left < right)
    {
        ft_swap(&input[left],&input[right]);
        left++;
        right--;
    }
    return 1;
}
int main(int ac, char **av)
{
    if(ac != 2)
        return 1;
    char *input = strdup(av[1]);
    if(!input)
    {
        printf("error : no input lah yahdik \n");
        return 1;
    }
    int len_input = strlen(input);
    int prev = 0;
    while(input[prev])
    {
        int next = prev + 1;
        while(input[next])
        {
            if(input[prev] > input[next])
            {
                ft_swap(&input[prev],&input[next]);
            }
            next++;
        }
        prev++;
    }
    write(1,input,len_input);
    write(1,"\n",1);
    while(permetation_generate(input,len_input))
    {
        write(1,input,len_input);
        write(1,"\n",1);
    }
    free(input);
    return 0;
}