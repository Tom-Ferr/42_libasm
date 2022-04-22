section .text

global ft_strcpy

ft_strcpy:
	mov rax, rdi
	call loop
	ret
loop:
	cmp byte[rsi], 0x0
	jne copy
	mov byte[rdi], 0x0
	ret
copy:
	mov dl, byte[rsi]
	mov byte[rdi], dl
	inc rdi
	inc rsi
	jmp loop
