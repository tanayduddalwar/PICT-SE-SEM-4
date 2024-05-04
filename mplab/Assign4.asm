%macro rw 3
mov rax,%1
mov rdi,0
mov rsi,%2
mov rdx,%3
syscall
%endmacro

section .data
	msg1 db "Largest number is: "
	msglen1 equ $-msg1
	arr dq 1234567812345678h,8765432112345678h,8111111111111111h,2222222222222222h,3333333333333333h
	count db 05h
	largest dq 0
	
	
section .bss
	resultarr resb 16
	
	
	
section .text
	global _start
		_start:
		
		mov rbp,arr
	up:
		mov rax,[rbp]
		cmp qword[largest],rax
		ja next
		mov qword[largest],rax
	next:
		add rbp,08h
		dec byte[count]
		jnz up
		
		rw 1,msg1,msglen1
		mov rax,qword[largest]
		call h_to_a
		
		rw 1,resultarr,16
				
		mov rax,60
		mov rdi,00
		syscall
		
	h_to_a:
		mov rax,qword[largest]
		mov rbp,resultarr
		mov byte[count],16
	up1:
		rol rax,04
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
		ret
