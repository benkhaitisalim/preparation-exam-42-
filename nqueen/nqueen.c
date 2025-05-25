#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int is_safe(int tab[],int nqueen,int col, int row)
{
    int i = 0;
    while(i < row)
    {
        if((tab[i] == col) || abs(tab[i] - col) == abs(i - row))
            return 0;
        i++;
    }
    return 1;
}
void    solve_nqueen(int tab[],int nqueen,int row)
{
    if(row == nqueen)
    {
        int i = 0;
        while(i < nqueen)
        {
            fprintf(stdout,"%d", tab[i]);
            if(i < nqueen - 1)
                fprintf(stdout," ");
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
            tab[row] = -1;
        }
        col++;
    }
}

int main(int ac, char **av)
{
    if(ac != 2)
        return 1;
    int nqueen = atoi(av[1]);
    if(nqueen < 2)
        return 1;
    int *tab = malloc(sizeof(int ) * (nqueen));
    int i = 0;
    while(i < nqueen)
    {
        tab[i] = -1;
        i++; 
    }
    solve_nqueen(tab,nqueen,0);
    return 0;
}

// For example this should work :
// $> ./n_queens 2 | cat -e

// $> ./n_queens 4 | cat -e
// 1 3 0 2$
// 2 0 3 1$

// $> ./n_queens 7 | cat -e
// 0 2 4 6 1 3 5$
// 0 3 6 2 5 1 4$
// etc...