#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void print_table(int *table,int queens)
{
    int i = 0;
    while(i < queens - 1)
    {
        printf("%d ",table[i]);
        i++;
    }
    printf("%d\n",table[queens - 1]);
}
int is_safe(int table[],int queens,int col,int row)
{
    int tol = 0;
    while(tol < row)
    {
        if(table[tol] == col)
        {
            return 0;
        }
        tol++;
    }
    int lard = col;
    tol = row;
    while(tol >= 0 && lard >= 0)
    {
        if(table[tol] == lard)
        {
            return 0;
        }
        lard--;
        tol--;
    }
    lard = col;
    tol = row;
    while(tol >= 0 && lard <= queens - 1)
    {
        if(table[tol] == lard)
        {
            return 0;
        }
        lard++;
        tol--;
    }
    return 1;

}
void solve_nqueen(int table[],int queens,int row)
{
    if(row >= queens)
    {
        print_table(table,queens);
    }
    int col = 0;
    while(col < queens)
    {
        if(is_safe(table,queens,col,row))
        {
            table[row] = col;
            solve_nqueen(table,queens,row + 1);
            table[row] = -1;
        }
        col++;
    }
}

int main(int ac , char **av)
{
    if(ac != 2)
    {
        return 0;
    }
    int queens = atoi(av[1]);
    int *table = malloc(sizeof(int) * queens);
    int row = 0;
    while(row < queens - 1)
    {
        table[row] = -1;
        row++;
    }
    solve_nqueen(table,queens,0);
    free(table);
}