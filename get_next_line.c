#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1 

char *get_next_line(int fd) {
    char buffer[BUFFER_SIZE];
    char *line = NULL;
    char *temp = NULL;
    int len = 0;
    int bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0) {
        return NULL; 
    }

    line = (char *)malloc(1);
    if (!line) return NULL;
    line[0] = '\0';

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        if (buffer[0] == '\n') break;

        temp = (char *)malloc(len + 2); 
        if (!temp) {
            free(line);
            return NULL;
        }

        for (int i = 0; i < len; i++) temp[i] = line[i]; 
        temp[len] = buffer[0];
        temp[len + 1] = '\0';

        free(line);
        line = temp;
        len++;
    }

    
    if (bytes_read == 0 && len == 0) {
        free(line);
        return NULL;
    }

    return line;
}

