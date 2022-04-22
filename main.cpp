#include <iostream>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

extern "C" size_t ft_strlen(const char*);
extern "C" ssize_t ft_write(int, const void*, size_t);
extern "C" ssize_t ft_read(int, const void*, size_t);
extern "C" char* ft_strcpy(char* dest, const char* src);
extern "C" char ft_strcmp(const char* s1, const char* s2);
extern "C" char* ft_strdup(const char*);

int main(){
	const char* greeting = "hello Tomas";
	size_t l = ft_strlen(greeting);
	std::cout << l << std::endl;
	ssize_t w = ft_write(1, greeting, l);
	std::cout << std::endl;
	std::cout << w << std::endl;
	char buff[15];
	ft_read(0, buff, 5);
	std::cout << buff << std::endl;
	char* cp = ft_strcpy(buff, greeting);
	std::cout << cp << std::endl;
	int diff = ft_strcmp(buff, greeting);
	std::cout << diff << std::endl;
	char* dup = ft_strdup("This is a deep copy");
	std::cout << "dup: " << dup << std::endl;
	free(dup);
	return 0;
}

