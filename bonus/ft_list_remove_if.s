section .text

global ft_list_remove_if

ft_list_remove_if:          ;   rdi: **begin_list, rsi: *data_ref, rdx: (*cmp)(), rcx: (*free_fct)(void *) 
    cmp qword[rdi], 0x0
    je end
    mov r10, rdi
    mov rdi, [rdi]
    xor r11, r11
    mov r8, rsi
    jmp compare

compare:
    mov rsi, r8
    push rdi
    mov rdi, qword[rdi + 1*8]
    push r8
    call rdx
    pop r8
    pop rdi
    cmp rax, 0x0
    je free
    cmp qword[rdi], 0x0
    je end
    mov r11, rdi
    mov rdi, qword[rdi]
    jmp compare

free:
    cmp r11, 0x0
    jne relink
    mov r11, [rdi]
    mov [r10], r11
    push qword[rdi + 1*8]
    push rcx
    call rcx
    pop rcx
    pop rdi
    call rcx
    jmp end

relink:
    mov r9, qword[rdi]
    mov qword[r11] , r9
    push r11
    push r10
    push rdx
    push r8
    push rcx
    push qword[rdi + 1*8]
    call rcx
    pop rdi
    pop rcx
    pop r8
    jmp remove_element

    remove_element:
    push r8
    push rcx
    call rcx
    pop rcx
    pop r8
    pop rdx
    pop r10
    pop rdi
    jmp compare

end:
    ret
