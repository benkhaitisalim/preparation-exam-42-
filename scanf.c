#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdio.h>
int is_digit(int num)
{
    return(num >= '0' && num <= '9');
 
}
int is_space(char c)
{
    return(c == ' ' || c == '\t' || c == '\v' || c == '\n');
}
int function_to_read_char()
{
    write(1,"ft_scanf : ",11);
    char c;
    while(read(0,&c,1) > 0)
    {
        if(!is_space(c))
        {
            return c;
        }
    }
    return -1;
}
int fuction_to_read_int()
{
    char c;
    int sing = 1;
    int result;
    write(1,"ft_scanf : ",11);
    while(read(0,&c,1) > 0 && is_space(c))
    ;
    if(c == '-' || c == '+')
    {
        if(c == '-')
            sing *= -1;
        read(0,&c,1);
    }
    result = c - '0';
    while(read(0,&c,1) > 0 && is_digit(c))
    {
        result = result * 10 + (c - '0');
    }
    return (result * sing);
}
#include <stdio.h>
#include <stdarg.h>
void ft_putchar(char c)
{
    write(1,&c,1);
}
int    foo(char *fmt, ...)

{
    va_list ap;
    int d;
    char c, *s;

    va_start(ap, fmt);
    int i = 0;
    int count = 0;
    while (fmt[i])
    {
        if(is_space(fmt[i])) 
        {
            while(fmt[i] && is_space(fmt[i]))
            {
                i++;
            }
        }
        if(fmt[i] == '%')
        {
            i++;
            if(fmt[i] == 'd')
            {
                int *num = (int *)va_arg(ap, int*);
                d = fuction_to_read_int();
                *num = d;
                count++;
            } 
            if(fmt[i] == 'c')
            {
                char *charachter = (char *) va_arg(ap, int*);
                c = function_to_read_char();
                *charachter = c;
                count++;
            } 
        }
        i++;
    }
    va_end(ap);
    return count;
}
