#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int match_space(FILE *f)
{
    int space = fgetc(f);
    while(space != EOF && isspace(space))
    {
        space = fgetc(f);
    }
    if(space == EOF)
        return -1;
    ungetc(space,f);
    return (1);
}

int match_char(FILE *f, char c)
{
    char ch = fgetc(f);
    if(ch == c)
    {
        return 1;
    }
    return (-1);
}

int scan_char(FILE *f, va_list ap)
{
    char *capture = va_arg(ap,char *);
    char c = fgetc(f);
    *capture = c;
    return (1);
}

int scan_int(FILE *f, va_list ap)
{
    int num = fgetc(f);
    int sign = 1;
    while(num != EOF && isspace(num))
    {
        num = fgetc(f);
    }
    if(num == '+' || num == '-')
    {
        if(num == '-')
        {
            sign *= -1;
        }
        num = fgetc(f);
    }
    if(!isdigit(num))
    {
        return -1;
    }
    int result = 0;
    while(num != EOF && isdigit(num))
    {
        result = (result * 10) + (num - '0');
        num = fgetc(f);
    }
    int *store_result = va_arg(ap, int *);
    *store_result = result * sign;
    return (1);
}

int scan_string(FILE *f, va_list ap)
{
    char *store_string = va_arg(ap, char *);
    int char_scaned = 0;
    char c = fgetc(f);
    while(c != EOF && !isspace(c))
    {
        store_string[char_scaned] = c;
        char_scaned++;
        c = fgetc(f); 
    }
    store_string[char_scaned] = '\0';
    return (char_scaned);
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

