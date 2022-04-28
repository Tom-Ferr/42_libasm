section .text

global ft_atoi_base
extern ft_strlen

ft_atoi_base:
	jmp check

check:
	push rdi
	mov rdi, rsi
	call ft_strlen
	pop rdi
	cmp rax, 1
	jle error
	mov r10, rax
	xor rcx, rcx
	jmp find

find:
	cmp byte[rsi + rcx], 0x0
	je continue

	cmp byte[rsi + rcx], 0x20 ; is whitespace?
	je error

	cmp byte[rsi + rcx], 0x2b ; is '+' sign?
	je error

	cmp byte[rsi + rcx], 0x2d ; is '-' sign?
	je error

	xor rdx, rdx
	xor r11, r11
	jmp check_double

increment_find:
	inc rcx
	jmp find
	
check_double:
	mov r8b, byte[rsi + rcx]
	cmp r8b, byte[rsi + rdx]
	je set_double
	inc rdx
	cmp byte[rsi + rdx], 0x0
	jne check_double
	jmp increment_find

set_double:
	cmp r11, 0x0
	jne error
	inc r11
	inc rdx
	cmp byte[rsi + rdx], 0x0
	jne check_double
	jmp increment_find

error:
	xor rax, rax
	ret

continue:
	xor rax, rax
	xor rdx, rdx
	xor rcx, rcx
	xor r9, r9
	jmp compare_elements

iterate:
	inc rdi
	xor rcx, rcx
	jmp compare_elements

compare_elements:
	cmp byte[rdi], 0x2d ; compare with '-' sign
	je set_sign
	jmp check_base

set_sign:
	not rdx
	jmp iterate

check_base:
	cmp byte[rdi], 0x0
	je end
	mov r8b, byte[rdi]
	cmp r8b, byte[rsi + rcx]
	je is_base
	inc rcx
	cmp byte[rsi + rcx], 0x0
	je cross_roads
	jmp check_base

is_base:
	push rdx
	mul r10
	pop rdx
	add rax, rcx
	inc r9
	jmp iterate

cross_roads:
	cmp r9, 0x0
	jne end
	jmp iterate
end:
	cmp rdx, 0x0
	jne negate
	ret
negate:
	neg rax
	ret

