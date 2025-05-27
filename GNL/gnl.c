#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#define BUFFER_SIZE 42
char *get_next_line(int fd)
{
    static int int_pos;
    static int  int_read;
    static char buffer[BUFFER_SIZE];
    char *line;
    int i;
    line = malloc(sizeof(char ) * (5000));
    if(!line)
        return NULL;
    i = 0;
    while(1)
    {
        if(int_pos >= int_read)
        {
            int_read = read(fd,buffer,BUFFER_SIZE);
            if(int_read <= 0)
            {
                break;
            }
            int_pos = 0;
        }
        line[i++] = buffer[int_pos++];
        if(buffer[int_pos - 1] == '\n' || i >= 4999)
        {
            break;
        }
    }
    if(i == 0)
    {
        free(line);
        return NULL;
    }
    line[i] = '\0';
    return (strdup(line));
}
int main(int ac , char **av)
{
    if(ac != 2)
        return 1;
    int fd = open(av[1], O_RDONLY);
    char *line;
    while((line = get_next_line(fd)))
    {
        printf("%s",line);
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    return 0;
}