section .text

global ft_strcmp

ft_strcmp:
	movsx rax, byte[rdi]
	sub al, byte[rsi]
	cmp al, 0x0
	je next
	jl is_lesser
	jg is_greater
next:
	cmp byte[rdi], 0x0
	je stop
	inc rdi
	inc rsi
	jmp ft_strcmp
stop:
	ret
is_lesser:
	mov rax, -1
	ret
is_greater:
	mov rax, 1
	ret
