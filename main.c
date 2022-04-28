
#include "libasm.h"

int main(){

	printf("\n---ft_strlen---\n");
	{
		printf("\nEmpty String\n");
		const char* empty_string = "";
		size_t l = ft_strlen(empty_string);
		printf("\nft_strlen returned: %zu\n", l);

		printf("\nAlphabet\n");
		const char* alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		l = ft_strlen(alphabet);
		printf("\nft_strlen returned: %zu\n", l);

		printf("\nVery Big String\n");
		const char* loremimpsumX100 = "loremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsum";
		l = ft_strlen(loremimpsumX100);
		printf("\nft_strlen returned: %zu\n", l);
	}

	printf("\n---ft_write---\n");
	{
		ssize_t l = ft_write(1, "Hello, dear\n",12);
		printf("\nft_write returned: %zd\n", l);


		printf("\nWrite in Wrong Fd:\n");
		l = ft_write(10, "Hello, dear\n",12);
		printf("\nft_write returned: %zd\n", l);
		printf("\nerrno: %d\n", errno);

		printf("\nWrite in File\n");
		int fd = open("testing.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);

		l = ft_write(fd, "Awsome!!!\n", 10);
		printf("\nft_write returned: %zd\n", l);
		close(fd);

	}

	printf("\n---ft_read---\n");
	{
		printf("Read from STD_IN:\n");
		char buff[100];
		ssize_t l = ft_read(0, buff,100);
		printf("STD_IN: %s\n", buff);
		printf("ft_read returned: %zd\n", l);

		printf("\nRead from Wrong Fd:\n");
		l = ft_read(10, buff,100);
		printf("ft_write returned: %zd\n", l);
		printf("errno: %d\n", errno);

		int fd = open("testing.txt", O_RDONLY);

		printf("\nRead from File Fd:\n");
		l = ft_read(fd, buff,100);
		printf("data: %s\n", buff);
		printf("\nft_write returned: %zd\n", l);
		close(fd);


	}


	printf("\n---ft_strcpy---\n");
	{
		printf("\nEmpty String\n");
		char buff[1001];
		const char* empty_string = "";
		char* cp = ft_strcpy(buff, empty_string);
		printf("\nft_strcpy returned: %s\n", cp);

		printf("\nAlphabet\n");
		const char* alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		cp = ft_strcpy(buff, alphabet);
		printf("\nft_strcpy returned: %s\n", cp);

		printf("\nVery Big String\n");
		const char* loremimpsumX100 = "loremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsum";
		cp = ft_strcpy(buff, loremimpsumX100);
		printf("\nft_strcpy returned: %s\n", cp);

	}

	printf("\n---ft_strcmp---\n");
	{
		printf("\nEmpty String\n");
		int diff = ft_strcmp("", "");
		printf("\nft_strcmp returned: %d\n", diff);

		const char* alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";


		diff = ft_strcmp("", alphabet);
		printf("\nft_strcmp returned: %d\n", diff);


		diff = ft_strcmp(alphabet, "");
		printf("\nft_strcmp returned: %d\n", diff);


		diff = ft_strcmp(alphabet, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
		printf("\nft_strcmp returned: %d\n", diff);


		diff = ft_strcmp(alphabet, "abcdefghijklmnopqrstuvwxyz");
		printf("\nft_strcmp returned: %d\n", diff);


		diff = ft_strcmp("abcdefghijklmnopqrstuvwxyz", alphabet);
		printf("\nft_strcmp returned: %d\n", diff);


		diff = ft_strcmp("ABCDEFGHIJKLMNOPQRSTUVWXYZ", alphabet);
		printf("\nft_strcmp returned: %d\n", diff);

		
		diff = ft_strcmp("abcdefghijklmnopqrstuvwxyz!!!ABCDEFGHIJKLMNOPQRSTUVWXYZ", alphabet);
		printf("\nft_strcmp returned: %d\n", diff);

	}

	printf("\n---ft_strdup---\n");
	{
		printf("\nEmpty String\n");
		const char* empty_string = "";
		char* dup = ft_strdup(empty_string);
		printf("\nft_strdup returned: %s\n", dup);
		free(dup);

		printf("\nAlphabet\n");
		const char* alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		dup = ft_strdup(alphabet);
		printf("\nft_strdup returned: %s\n", dup);
		free(dup);

		printf("\nVery Big String\n");
		const char* loremimpsumX100 = "loremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsumloremipsum";
		dup = ft_strdup(loremimpsumX100);
		printf("\nft_strdup returned: %s\n", dup);
		free(dup);

	}
	return 0;
}

