#include <unistd.h>
#include <string.h>
#include <stdlib.h>
void ft_swap(char *s1,char *s2)
{
    char tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}
int permutation(char *input , int len)
{
    int i;
    int j;
    int left;
    int right;
    i = len - 2;
    while(i >= 0 && input[i] <= input[i + 1])
        i--;
    if(i < 0)
    {
        return 0;
    }
    j = len - 1;
    while(input[i] >= input[j])
    {
        j--;
    }
    ft_swap(&input[i],&input[j]);
    left =  i + 1;
    right = len - 1;
    while(left < right)
    {
        ft_swap(&input[left],&input[right]);
        right--;
        left++;
    }
    return 1;
}
int main(int ac , char **av)
{
    if(ac != 2)
    {
        return 1;
    }
    char *input = strdup(av[1]);
    int lenth = strlen(input);
    int i = 0;
    while(input[i])
    {
        int j = i + 1;
        while(input[j])
        {
            if(input[i] > input[j])
            {
                char tmp = input[i];
                input[i] = input[j];
                input[j] = tmp;
            }
            j++;
        }
        i++;
    }
    write(1,input,lenth);
    write(1,"\n",1);
    while(permutation(input,lenth))
    {
        write(1,input,lenth);
        write(1,"\n",1);
    }
    free(input);
    return 0;
}