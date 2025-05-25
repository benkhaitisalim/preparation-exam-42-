// Expected files : *.c *.h
// Allowed functions: atoi, fprintf, malloc, calloc, realloc, free, stdout, stderr, write
// Write a program that will take as argument an integer n followed by a set s of integer. your program should display all the subsets of s whose sum of elements is n.
// The order of the lines is not important, but the order of the element in a subset is. You must not have any duplicates (eg: '1 2' and '2 1').
// in case of a malloc error your program will exit with the code 1.
// We will not test with invalid sets (for example '1 1 2')
// For example this should work:
// $>./powerset 3 1 0 2 4 5 3 cat-e
// 3$
// 0 3$
// 1 2$
// 1 0 2$
// $>./powerset 12 5 2 1 8 4 3 7 11 | cat -e
// 8 4$
// 1 11$
// 1 4 7$
// 1 8 3$
// 2 3 7$
// 5 7$
// 5 4 3$
// 5 2 1 4$
// $>./powerset 0 1 -1 | cat -e
// 1 -1$
// $> ./powerset 7 3 8 2 | cat -e
#include <stdio.h>
#include <stdlib.h>
void solve_problem(int *tab,int index_tab,int size,int *tem,int pos_tem,int target)
{
    if(index_tab == size)
    {
        int i = 0;
        int sum = 0;
        while(i < pos_tem)
        {
            sum += tem[i];
            i++;
        }
        if(sum == target)
        {
            int x = 0;
            while(x < pos_tem)
            {
                printf("%d ",tem[x]);
                x++;
            }
            printf("\n");
        }
        return ;
    }
    tem[pos_tem] = tab[index_tab];
    solve_problem(tab,index_tab + 1,size,tem,pos_tem + 1,target);
    solve_problem(tab,index_tab + 1,size,tem,pos_tem ,target);

}

int main(int ac ,char **av)
{
    if(ac < 4)
    {
        return 1;
    }
    int size = ac - 2;
    int *tab = malloc(sizeof(int ) * size);
    int i = 0;
    int target = atoi(av[1]);
    while(i < size)
    {
        tab[i] = atoi(av[i + 2]);
        i++;
    }
    int *tem = malloc(sizeof(int) * size);
    solve_problem(tab,0,size,tem,0,target);

}