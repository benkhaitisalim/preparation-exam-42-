#include <stdio.h>
#include  <unistd.h>
#include <stdlib.h>

#define TEMPLATE -1



int is_safe(int tab[],int col,int row)
{
    int i = 0;
    while(i < row)
    {
        if(tab[i] == col || abs(tab[i] - col) == abs(i - row))
        {
            return 0;
        }
        i++;
    }
    return 1;
}
void solve_nqueen(int tab[],int nqueen,int row)
{
    if(row == nqueen)
    {
        int i = 0;
        while(i < nqueen)
        {
            fprintf(stdout,"%d",tab[i]);
            if(i < nqueen - 1)
            {
                fprintf(stdout," ");

            }
            i++;
        }
        fprintf(stdout,"\n");
        return ;
    }
    int col = 0;
    while(col < nqueen)
    {
        if(is_safe(tab,nqueen,col,row))
        {
            tab[row] = col;
            solve_nqueen(tab,nqueen,row + 1);
            tab[row] = TEMPLATE;
        }
        col++;
    }
}

int main(int ac , char **av)
{
    if(ac != 2)
    {
        return 1;
    }
    int nqueen = atoi(av[1]);
    if(nqueen < 0)
    {
        fprintf(stderr,"NQUEEN negative values\n");
        return 1;
    }
    int *table = malloc(sizeof(int) * nqueen);
    if(!table)
    {
        return 1;
    }
    int index = 0;
    while(index < nqueen)
    {
        table[index] = TEMPLATE;
        index++;
    }
    solve_nqueen(table,nqueen,0);
    return 0;

}