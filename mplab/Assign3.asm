%macro rw 3
mov rax,%1
mov rdi,0
mov rsi,%2
mov rdx,%3
syscall
%endmacro

section .data
	msg1 db "Number of Positive numbers: ",0XA,0XD
	msglen1 equ $-msg1
	msg2 db "Number of Negative numbers: ",0XA,0XD
	msglen2 equ $-msg2
	res db 00h
	arr dq 1234567812345678h,8765432112345678h,8111111111111111h,2222222222222222h,3333333333333333h
	count db 05h
	pcnt db 0
	ncnt db 0
	
	
section .bss
	arr resb 2
		
section .text
	global _start
		_start:
		mov rbp,arr
	up:
		mov rax,[rbp]
		bt rax,63
		jc negative
		inc byte[pcnt]
		jmp next
	negative:
		inc byte[ncnt]
	next:
		add rbp,08h ;inc rbp
		dec byte[count]
		jnz up
		
		mov al,byte[pcnt]
		mov byte[res],al
		rw 1,msg1,msglen1
		call h_to_a
		
		mov al,byte[ncnt]
		mov byte[res],al
		rw 1,msg2,msglen2
		call h_to_a

				
		mov rax,60
		mov rdi,00
		syscall
		
	h_to_a:
		mov al,byte[res]
		mov rbp,resultarr
		mov byte[count],2
	up1:
		rol al,04
		mov bl,al
		and bl,0Fh
		cmp bl,09h
		jle next1
		add bl,07h
		
	next1: 
		add bl,30h
		mov [rbp],bl
		inc rbp
		dec byte[count]
		jnz up1
		rw 1,resultarr,2
		ret
	