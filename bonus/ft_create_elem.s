section .text

global ft_create_elem

extern malloc

ft_create_elem:
    push rdi
    mov rdi, 16
    call malloc wrt ..plt        ;t_list* lst = (t_list*)malloc(sizeof(t_list));
    pop rdi
    cmp rax, 0x0            ; if(!lst) return NULL;
    je error
    xor rdx, rdx
    mov [rax], rdx       ;  lst->next = NULL;
    mov [rax + 1*8], rdi    ; lst->data = data;
    ret
error:
    ret