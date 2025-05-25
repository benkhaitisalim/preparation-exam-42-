#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ft_check_left_right(char *input, int *left,int *right)
{
    int i = 0;
    *left = 0;
    *right = 0;
    while(input[i])
    {
        if(input[i] == '(')
        {
            (*left)++;
        }
        else if(input[i] == ')')
        {
            if((*left) > 0)
            {
                (*left)--;
            }
            else
            {   
                (*right)++;
            }
        }
        i++;
    }
}
int ft_check_result(char *input)
{
    int i = 0;
    int left = 0;
    while(input[i])
    {
        if(input[i] == '(')
        {
            left++;
        }
        else if(input[i] == ')')
        {
            left--;
            if(left < 0)
                return 1;
        }
        i++;
    }
    return 0;
}

void permetation(char *input,int index_input,int left,int right,char *tmp,int tmp_pos)
{
    if(!input[index_input])
    {
        if(left == 0 && right == 0)
        {
            if(ft_check_result(tmp) == 0)
            {
                tmp[tmp_pos] = '\0';
                write(1,tmp,strlen(tmp));
                write(1," \n",2);
            }
        }
        return ;
    }
    if(input[index_input] == '(' && left > 0 || input[index_input] == ')' && right > 0)
    {
        tmp[tmp_pos] = ' ';
        
        if(input[index_input] == '('  && left > 0)
        {
            permetation(input,index_input + 1, left - 1, right,tmp,tmp_pos + 1);
        }
        if(input[index_input] == ')'  && right > 0)
        {
            permetation(input,index_input + 1, left, right - 1,tmp,tmp_pos + 1);
        }
    }
    tmp[tmp_pos] = input[index_input];
    permetation(input,index_input + 1, left, right ,tmp,tmp_pos + 1);
}
int main(int ac , char **av)
{
    if(ac != 2)
    {
        return 1;
    }
    char *input = strdup(av[1]);
    int len_input = strlen(input);
    char *tmp = malloc(sizeof(char ) * len_input);
    int left,right;
    ft_check_left_right(input,&left,&right);
    permetation(input,0, left, right,tmp,0);
    return 0;
    
}