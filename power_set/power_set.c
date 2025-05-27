#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void solve_power_set(int tab[],int index_tab,int size,int temp[],int index_temp,int target)
{
    if(index_tab == size)
    {
        int sum = 0;
        int index = 0;
        while(index < index_temp)
        {
            sum += temp[index];
            index++;
        }
        if(sum == target)
        {
            int j = 0;
            while(j < index_temp)
            {
                printf("%d  ", temp[j]);
                if(j < index_temp - 1)
                {
                    printf(" ");
                }
                j++;
            }
            printf("\n");
        }
        return ;
    }
    temp[index_temp] = tab[index_tab];
    solve_power_set(tab,index_tab + 1,size,temp,index_temp + 1,target);
    solve_power_set(tab,index_tab +1 ,size,temp,index_temp,target);
}

int main(int ac ,char **av)
{
    if(ac < 4)
    {
        return 1;
    }
    int target = atoi(av[1]);
    int n = 0;
    int size = ac - 2;
    int *tab = malloc(sizeof(int ) * size);
    while(n < size)
    {
        tab[n] = atoi(av[n + 2]);
        n++;
    }
    int *temp = malloc(sizeof(int ) * size);
    solve_power_set(tab,0,size,temp,0,target);
    free(tab);
    free(temp);
    return 0;
}