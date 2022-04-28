section .text

global ft_strcmp

ft_strcmp:
	cmp byte[rdi], 127
	jg negate_dest
	cmp byte[rsi], 127
	jg negate_src
	movsx rax, byte[rdi]
	cmp al, byte[rsi]
	je next
	jl is_lesser
	jg is_greater

negate_dest:
	neg byte[rdi]
	jmp ft_strcmp

negate_src:
	neg byte[rsi]
	jmp ft_strcmp

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
