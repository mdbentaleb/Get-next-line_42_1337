#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SZ 1

char *get_next_line(int fd)
{}


int main()
{
	char buf[BUF_SZ];
	int bytes_red;


	int fd = ("test.txt", O_RDONLY);

	size_t r = read(fd, );

}