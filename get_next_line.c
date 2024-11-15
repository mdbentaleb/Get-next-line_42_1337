#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 42 

char *get_next_line(int fd)
{
    char buffer[BUFFER_SIZE];
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
    }


    return bytes_read;
}


// int main()
// {
//     int fd = open("med.txt", O_RDONLY);
//     if (fd == -1) {
//         perror("Failed to open file");
//         return 1;
//     }

//     printf("%s", get_next_line(fd));

//     close(fd);

//     return 0;
// }