// #include "get_next_line.h"
// #include <fcntl.h>
// #include <stdio.h>


// int main()
// {
//     int fd1 = open("fd1.txt", O_RDONLY);
//     if (fd1 != -1)
//         printf("%s", get_next_line(fd1));
//     else
//         printf("Error open fd1\n");

//     int fd2 = open("fd2.txt", O_RDONLY);
//     if (fd2 != -1)
//         printf("%s", get_next_line(fd2));
//     else
//         printf("Error open fd1\n");

//     int fd3 = open("fd3.txt", O_RDONLY);
//     if (fd3 != -1)
//         printf("%s", get_next_line(fd3));
//     else
//         printf("Error open fd3\n");


//     int fd4 = open("fd4.txt", O_RDONLY);
//     if (fd4 != -1)
//         printf("%s", get_next_line(fd4));
//     else
//         printf("Error open fd4\n");
    
// }

#include <stdio.h>
#include <limits.h>

int main() {
    // طباعة الحد الأقصى للملفات التي يمكن فتحها
    printf("The maximum number of open files is: %d\n", FOPEN_MAX);
    return 0;
}