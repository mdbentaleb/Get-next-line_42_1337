#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 100

char *get_next_line(int fd) {
    char *buf = malloc(BUFFER_SIZE);
    int bytes_read, i = 0;

    if (!buf) {
        return NULL;
    }

    while ((bytes_read = read(fd, &buf[i], 1)) > 0) {
        if (buf[i] == '\n') {
            i++;  // Move to the next position to include the newline
            break;
        }
        i++;
        if (i >= BUFFER_SIZE - 1) {
            buf = realloc(buf, i + 2);
        }
    }

    if (bytes_read <= 0 && i == 0) {
        free(buf);
        return NULL;
    }

    buf[i] = '\0';  // Null-terminate the string including the newline
    return buf;
}

int main() {
    int fd = open("med.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    char *line = get_next_line(fd);
	printf("%s", line);
    // while ((line = get_next_line(fd)) != NULL) {
    //     printf("%s", line); 
    //     free(line);  // Free memory for each line
    // }

    close(fd);
    return 0;
}

