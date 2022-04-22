section .text

global ft_strdup

extern ft_strlen
extern ft_strcpy
extern malloc
extern __errno_location

ft_strdup:
	mov rsi, rdi
	call ft_strlen
	mov rdi, rax
	inc rdi
	push rsi
	call malloc wrt ..plt
	cmp rax, 0x0
	jl error
	mov rdi, rax
	pop rsi
	call ft_strcpy
	ret

error:
	neg rax
	mov rdx, rax
	call __errno_location wrt ..plt
	mov [rax], rdx
	mov rax, 0x0
	ret


