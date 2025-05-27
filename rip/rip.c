#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void    count_brackets(char *input,int *left,int *right)
{
    int i = 0;
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
                (*right)++;
        }
        i++;
    }
}
int si_correct(char *p)
{
    int i = 0;
    int balance = 0;
    while(p[i])
    {
        if(p[i] == '(')
        {
            balance++;
        }
        else if(p[i] == ')')
        {
            balance--;
            if(balance < 0)
            {
                return 1;
            }
        }
        i++;
    }
    return 0;
}
void solve_brackets_problem(char *str,int index_str,int left,int right,char *input_tem,int index_tem)
{
    if(!str[index_str])
    {
        if(left == 0 && right == 0)
        {
            input_tem[index_tem] = '\0';
            if(si_correct(input_tem) != 1)
            {
                write(1,input_tem,strlen(input_tem));
                write(1," \n",2);
            }
        }
        return ;
    }
    if((str[index_str] == '('  && left > 0) || (str[index_str] == ')' && right > 0))
    {
        input_tem[index_tem] = ' ';
        if(str[index_str] == '(')
        {
            solve_brackets_problem(str,index_str + 1,left - 1,right,input_tem,index_tem + 1);
        }
        else if(str[index_str] == ')')
        {
            solve_brackets_problem(str,index_str + 1,left,right - 1,input_tem,index_tem + 1);
        }

    }
    input_tem[index_tem] = str[index_str];
    solve_brackets_problem(str,index_str + 1,left,right ,input_tem,index_tem + 1);

}

int main(int ac ,char **av)
{
    if(ac != 2)
    {
        return 1;
    }
    int left,right;
    count_brackets(av[1],&left,&right);
    char input_tem[strlen(av[1]) + 1];
    solve_brackets_problem(av[1],0,left,right,input_tem,0);
    return 1;
}