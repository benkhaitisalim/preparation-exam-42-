#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int match_space(FILE *f)
{
    int space = fgetc(f);
    while(space != EOF && isspace(space))
    {
        space = fgetc(f);
    }
    if(space == EOF)
    {
        return 0;
    }
    ungetc(space,f);
    return (1);
}

int match_char(FILE *f, char c)
{
    int ch = fgetc(f);
    if(ch == c)
    {
        return 0;
    }
    return (1);
}

int scan_char(FILE *f, va_list ap)
{
    char *stor_char = va_arg(ap,char *);
    char c = fgetc(f);
    if(c == EOF)
    {
        return 0;
    }
    *stor_char = c;
    return (1);
}

int scan_int(FILE *f, va_list ap)
{
    int sign = 1;
    int num = fgetc(f);
    int scaned_char = 0;
    if(num == '+' || num == '-')
    {
        if(num == '-')
            sign *= -1;
        num = fgetc(f);
    }
    if(!isdigit(num))
    {
        ungetc(num,f);
        return -1;
    }
    int result = 0;
    while(num != EOF && isdigit(num))
    {
        result = (result * 10) + (num - '0');
        num = fgetc(f);
        scaned_char++;
    }
    int *tab = va_arg(ap , int *);
    *tab = (result * sign);
    return (scaned_char);
}

int scan_string(FILE *f, va_list ap)
{
    char c = fgetc(f);
    int scaned_char = 0;
    char *stor_string = va_arg(ap, char *);
    int index = 0;
    while(c != EOF && !isspace(c))
    {
        stor_string[index] = c;
        index++;
        scaned_char++;
        c = fgetc(f);
    }
    if(scaned_char == 0 || index ==0)
    {
        return 0;
    }
    return (1);
}


int    match_conv(FILE *f, const char **format, va_list ap)
{
    switch (**format)
    {
        case 'c':
            return scan_char(f, ap);
        case 'd':
            match_space(f);
            return scan_int(f, ap);
        case 's':
            match_space(f);
            return scan_string(f, ap);
        case EOF:
            return -1;
        default:
            return -1;
    }
}

int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
    int nconv = 0;

    int c = fgetc(f);
    if (c == EOF)
        return EOF;
    ungetc(c, f);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (match_conv(f, &format, ap) != 1)
                break;
            else
                nconv++;
        }
        else if (isspace(*format))
        {
            if (match_space(f) == -1)
                break;
        }
        else if (match_char(f, *format) != 1)
            break;
        format++;
    }
    if (ferror(f))
        return EOF;
    return nconv;
}


int ft_scanf(const char *format, ...)
{
    va_list ap;
    va_start(ap,format);
    int ret = ft_vfscanf(stdin, format, ap);
    va_end(ap);
    return ret;
}
int main()
{
    char num[20];
    ft_scanf("%s",num);
    printf("%s\n",num);
    int n;
    ft_scanf("%d",&n);
    printf("%d\n",n);
    char c;
    ft_scanf("%c",&c);
    printf("%c\n",c);
}
