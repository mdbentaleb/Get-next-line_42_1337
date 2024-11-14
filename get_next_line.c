#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1  // Reading one character at a time

char *get_next_line(int fd) {
    char buffer[BUFFER_SIZE];
    char *line = NULL;
    char *temp = NULL;
    int len = 0;
    int bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0) {
        return NULL;  // Invalid file descriptor or buffer size
    }

    line = (char *)malloc(1);
    if (!line) return NULL;
    line[0] = '\0';

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        if (buffer[0] == '\n') break;

        temp = (char *)malloc(len + 2);  // Allocating space for new char + '\0'
        if (!temp) {
            free(line);
            return NULL;
        }

        for (int i = 0; i < len; i++) temp[i] = line[i];  // Copy old data to new space
        temp[len] = buffer[0];
        temp[len + 1] = '\0';

        free(line);
        line = temp;
        len++;
    }

    // If no bytes were read and no line was constructed, return NULL
    if (bytes_read == 0 && len == 0) {
        free(line);
        return NULL;
    }

    return line;
}

