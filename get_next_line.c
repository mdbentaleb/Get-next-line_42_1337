#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 42 

char read_to_newline(int fd, char **remaind)
{
    char buffer[BUFFER_SIZE + 1];
    ssize_t bytes_read;
    char *line = NULL;
    size_t line_len = 0;

    if (fd < 0 || buffer == NULL || BUFFER_SIZE == 0)
        return NULL;
    while (bytes_read = read(fd, buffer, BUFFER_SIZE) > 0)
    {
        buffer[bytes_read] = '\0';

        //search if theres a \n
        char *new_line_search = ft_strchr(buffer, '\n');
        if (new_line_search)
        {
            *new_line_search = '\0';
            *remaind = ft_strdu(new_line_search + 1);
        }

        line = ft_strjoin(line, buffer);
        if (*remaind)
            break;
    }
    return line;
}

char *get_next_line(int fd) {
    static char *remaind;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0) {
        return NULL;
    }
    
    if (remaind) {
        line = ft_strdup(remaind);
        free(remaind);
        remaind = NULL;
    } else {
        line = read_until_newline(fd, &remaind);
    }

    return line;
}