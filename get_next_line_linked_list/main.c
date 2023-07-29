#include "get_next_line_linked_lists.h"

int main(void)
{
	int fd1 = open("file1.txt", O_RDONLY);
	int fd2 = open("file2.txt", O_RDONLY);
	int fd3 = open("file3.txt", O_RDONLY);
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd3));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd3));
	printf("%s", get_next_line(fd2));
}