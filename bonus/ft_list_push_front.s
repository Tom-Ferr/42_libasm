section .text

global ft_list_push_front

extern ft_create_elem

ft_list_push_front:
push rdi        ;**lst
mov rdi, rsi    ; rdi = *data
call ft_create_elem
pop rdi         ; rdi = **lst
push qword[rdi] ; *lst
mov [rdi], rax  ;  *lst = new eleme
pop qword[rax]  ;   lst->next = *lst
ret

