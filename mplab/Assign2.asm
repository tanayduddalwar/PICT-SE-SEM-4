%macro rw 3
mov rax,%1
mov rdi,0
mov rsi,%2
mov rdx,%3
syscall
%endmacro

section .data
	msg1 db "Enter the String ",0XA,0XD
	msglen1 equ $-msg1
	msg2 db "Length of string is: "
	msglen2 equ $-msg2
	
	
section .bss
	count resb 1
	str1 resb 16
	resultarr resb 16
	
	
	
section .text
	global _start
		_start:
		rw 1,msg1,msglen1
		rw 0,str1,25	
		mov rbp,resultarr
		mov byte[count],16
		up:
		rol rax,04
		mov bl,al
		and bl,0Fh
		cmp bl,09h
		jle next
		add bl,07h
		
		next: 
		add bl,30h
		mov [rbp],bl
		inc rbp
		dec byte[count]
		jnz up
		
		rw 1,msg2,msglen2
		rw 1,resultarr,16
		
		mov rax,60
		mov rdi,00
		syscall
		
