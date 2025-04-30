#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#define ERROR_CHAR -1;
char ft_read_char()
{
    char c;
    while(read(1,&c,1) > 0)
    {
        if(!isspace(c))
        {
            return c;
        }
    }
    return ERROR_CHAR;
}
int read_int()
{
    char c;
    int sign = 1;
    int result = 0;
    while(read(1,&c,1)> 0 && isspace(c))
    ;
    if(c == '-' || c == '+')
    {
        if(c == '-')
        {
            sign *= -1;
        }
        read(1,&c,1);
    }
    result = c - '0';
    while(read(1,&c,1)> 0 && c >= '0' && c <= '9')
    {
        result = result * 10 + (c - '0');
    }
    return result * sign;
}
char *ft_str_put()
{
    char *str;
    
}
int    ft_scanf(char *fmt, ...)   /* '...' is C syntax for a variadic function */

{
    va_list ap;

    va_start(ap, fmt);
    int i = 0;
    int count = 0;
    while (fmt[i])
    {
        if (fmt[i] == '%')
        {
            i++;
            write(1,"ft_scanf :\n",12);

            if(fmt[i] ==  's')
            {
                char *s = va_arg(ap, char *);
                read(1,s,500);
                while(*s)
                {
                    write(1,s,1);
                    s++;
                }
                // printf("string %s\n", s);
                count++;
            }              /* string */
            if(fmt[i] ==  'd')
            {    
                int *dig = va_arg(ap, int *);
                int d = read_int();
                *dig = d;
                count++;
            }              /* int */
            if(fmt[i] == 'c')
            {
                char *cha = va_arg(ap, char *);
                char c = ft_read_char();
                *cha = c; 
                count++;    
            }
        }
        i++;              /* char */

    }
            /* need a cast here since va_arg only
               takes fully promoted types */
    va_end(ap);
    return count;
}
int main()
{
    int c;
    char *s;
    ft_scanf("%s",s);
    ft_scanf("%d",&c);
    printf("%d\n",c);

}