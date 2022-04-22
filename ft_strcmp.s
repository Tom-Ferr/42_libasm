section .text

global ft_strcmp

ft_strcmp:
	movsx rax, byte[rdi]
	sub al, byte[rsi]
	cmp rax, 0x0
	je next
	ret
next:
	cmp byte[rdi], 0x0
	je stop
	inc rdi
	inc rsi
	jmp ft_strcmp
stop:
	ret
