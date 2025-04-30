#include <unistd.h>
#include <stdarg.h>

int is_space(char c)
{
    return(c == '\t' || c == ' ' || c == '\n');
}
int is_digit(int c)
{
    return(c >= '0' && c <= '9');
}
int read_charachter()
{
    char c;
    write(1,"ft_scanf :\n",11);
    while(read(0,&c,1) > 0)
    {
        if(!is_space(c))
        {
            return c;
        }
    }
    return -1;
}
int read_int()
{
    char c;
    write(1,"ft_scanf :\n",11);
    while(read(0,&c,1) > 0 && is_space(c));
    if(!is_digit(c))
    {
        return -1;
    }
    int result;
    result = c - '0';
    while(read(0,&c,1) > 0 && is_digit(c))
    {
        result = result * 10 + (c - '0'); 
    }
    return result;
}

int ft_scanf(char *format, ...)
{
    va_list ap;
    int index = 0;
    int count = 0;
    va_start(ap, format);
    while(format[index])
    {
        if(is_space(format[index]))
        {
            while(is_space(format[index]))
            {
                index++;
            }
        }
        if(format[index] == '%')
        {
            index++;
            if(format[index] == 'd')
            {
                int *pn = va_arg(ap, int *);
                int value = read_int();
                *pn = value;
                count++;
            }
            else if(format[index] == 'c')
            {
                char *pc = va_arg(ap, char *);
                char charachter = read_charachter();
                *pc = charachter;
                count++;
            }
        }
        index++;
    }
    va_end(ap);
    return count;
}
void ft_putchar(char c)
{
    write(1,&c,1);
}
void ft_putnbr(int num)
{
    if(num > 9)
    {
        ft_putnbr(num / 10);
    }
    ft_putchar((num % 10) + '0');
}
int main()
{
    int num;
    char charachter;
    // ft_scanf("%c",&charachter);
    // write(1,&charachter,1);
    // write(1,"\n",1);
    ft_scanf("%d",&num);
    ft_putnbr(num);
    write(1,"\n",1);


}