section .text

global ft_list_size

ft_list_size:
    xor rax, rax
    cmp rdi, 0x0               ;if(!lst->next)
    je end
    inc rax
    jmp loop

loop:
    cmp qword[rdi], 0x0        ;if(!lst->next)
    je end
    inc rax                   ;++ret
    mov rdi, [rdi]            ; lst = ls->next
    jmp loop
end:
    ret