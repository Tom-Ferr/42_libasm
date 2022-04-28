#ifndef LIBASM_BONUS_HPP
    #define LIBASM_BONUS_HPP

    #include <stdio.h>
    #include <stdlib.h>

    typedef struct s_list{
        struct s_list *next;
        void          *data;
    }t_list;

    int ft_strcmp(const char* s1, const char* s2);
    int ft_atoi_base(const char* str,const char* base);
    t_list* ft_create_elem(void *data);
    void ft_list_push_front(t_list **begin_list, void *data);
    int ft_list_size(t_list *begin_list);
    t_list* ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
    void ft_list_sort(t_list **begin_list, int (*cmp)());

#endif