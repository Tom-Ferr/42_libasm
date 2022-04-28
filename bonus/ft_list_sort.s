section .text

global ft_list_sort

ft_list_sort:
    mov r10, rdi            ; r10 = **lst
    mov r9,  r10            ; r9 = **lst
    mov r11, rsi            ; r11 = cmp()
    mov rdi, [rdi]          ; rdi = *lst
    mov rsi, [rdi]          ; rsi = lst->next
    jmp compare

compare:
    push rdi
    push rsi
    mov rdi, [rdi + 1*8]    ; rxi = lst->data
    mov rsi, [rsi + 1*8]    ; rsi = lst->next->data
    call r11
    pop rsi
    pop rdi
    cmp rax, 0x0
    jg  swap
    jmp next

swap:
    push qword[rdi + 1*8]
    push qword[rsi + 1*8]
    pop qword[rdi + 1*8]
    pop qword[rsi + 1*8]
    jmp rewind


rewind:
    mov rdi, [r10]
    mov rsi, [rdi]
    jmp compare

next:
    mov r9, rdi
    mov rdi, rsi
    mov rsi, [rsi]
    cmp rsi, 0x0
    je  exit
    jmp compare

exit:
    ret
    