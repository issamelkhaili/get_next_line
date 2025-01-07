#include "get_next_line.h"

void	test_big_file(void)
{
	int		fd;
	char	*line;
	int		count;

	printf("\n=== Testing Big File ===\n");
	fd = open("big_file.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening big file");
		return ;
	}
	count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		count++;
		if (count % 1000 == 0)
			printf("Lines read: %d\n", count);
		free(line);
	}
	printf("Total lines read: %d\n", count);
	close(fd);
}

void	test_multiple_files(void)
{
	int		fd1;
	int		fd2;
	char	*line1;
	char	*line2;
	int		count;

	printf("\n=== Testing Multiple Files ===\n");
	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
	{
		perror("Error opening files");
		return ;
	}
	count = 0;
	while (count < 3)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		if (line1)
			printf("File1, line %d: %s", count + 1, line1);
		if (line2)
			printf("File2, line %d: %s", count + 1, line2);
		free(line1);
		free(line2);
		count++;
	}
	close(fd1);
	close(fd2);
}

void	test_invalid_fd(void)
{
	char	*line;

	printf("\n=== Testing Invalid FD ===\n");
	line = get_next_line(-1);
	if (!line)
		printf("Invalid FD test passed\n");
	else
	{
		printf("Invalid FD test failed\n");
		free(line);
	}
}

int	main(void)
{
	test_big_file();
	test_multiple_files();
	test_invalid_fd();
	return (0);
}