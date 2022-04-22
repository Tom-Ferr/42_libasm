section .text

global ft_strlen

ft_strlen:
	xor rax, rax
	call loop
	ret
loop:	
	cmp byte [rdi], 0x0
	jne next
	ret
next:
	inc rdi
	inc rax
	jmp loop
