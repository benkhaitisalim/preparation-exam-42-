#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define BUFFER_SIZE 1
char *get_next_line(int fd)
{
    static int pos;
    static int p_read;
    static char buffer[BUFFER_SIZE];
    char *line = malloc(sizeof(char ) * BUFFER_SIZE);
    int i = 0;
    while(1)
    {
        if(pos >= p_read)
        {
            p_read = read(fd,buffer,BUFFER_SIZE);
            if(p_read <= 0)
            {
                break;
            }
            pos = 0;
        }
        line[i++] = buffer[pos++];
        if(buffer[pos - 1] == '\n' || i >= BUFFER_SIZE)
        {
            break;
        }
    }
    line[i] = '\0';
    if(i == 0)
        return NULL;
    return(strdup(line));
}

int main(int ac ,char **av)
{
    if(ac != 2)
        return 1;
    char *line;
    int fd = open(av[1],O_RDONLY);
    while((line = get_next_line(fd)))
    {
        printf("%s", line);
        
    }
    free(line);
    return 0;
}