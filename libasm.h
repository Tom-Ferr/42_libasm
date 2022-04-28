#ifndef LIBASM_HPP
    #define LIBASM_HPP
    
    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdlib.h>
    #include <errno.h>

    size_t ft_strlen(const char*);
    ssize_t ft_write(int, const void*, size_t);
    ssize_t ft_read(int, const void*, size_t);
    char* ft_strcpy(char* dest, const char* src);
    int ft_strcmp(const char* s1, const char* s2);
    char* ft_strdup(const char*);
    
#endif