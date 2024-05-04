%macro rw 3
mov rax,%1
mov rdi,0
mov rsi,%2
mov rdx,%3
syscall
%endmacro

section .data
	msg1 db "Processor in protected ",0XA,0XD
	msglen1 equ $-msg1
	
	msg2 db "Processor not in protected ",0XA,0XD
	msglen2 equ $-msg2
	
	msg3 db "MSW value is: "
	msglen3 equ $-msg3
	
	msg4 db 10, 13, "TR value is: "
	msglen4 equ $-msg4
	
	msg5 db 10, 13, "LDTR value is: "
	msglen5 equ $-msg5
	
	msg6 db 10, 13, "GDTR value is: "
	msglen6 equ $-msg6
	
	msg7 db 10, 13, "IDTR value is: "
	msglen7 equ $-msg7
	
	msg8 db ":"
	msglen8 equ $-msg8

    
	msw1 dw 00h
	tr_val dw 00h
	ldt_val dw 00h
	gdt_val dq 00h
	idt_val dq 00h
	
	count db 00h
	
	
	
	
section .bss
	resultarr resb 4
	resarr resb 16
	
	ans resb 8

section .text
	global _start
		_start:
		
		smsw word[msw1]
		mov ax,word[msw1]
		bt ax,0
		jc is_one
		rw 1,msg2,msglen2
	is_one:
		rw 1,msg1,msglen1
		
		
		
		mov ax,word[msw1]
		call h_to_a
		rw 1,msg3,msglen3
		rw 1,resultarr,16
		
		
		str word[tr_val]
		mov ax,word[tr_val]
		call h_to_a
		rw 1,msg4,msglen4
		rw 1,resultarr,16
		
		sldt word[ldt_val]
		mov ax,word[ldt_val]
		call h_to_a
		rw 1,msg5,msglen5
		rw 1,resultarr,16
		
		sgdt qword[gdt_val]
		mov rax,qword[gdt_val]
		call hex_to_ascii
		rw 1,msg8,msglen8
		rw 1,resarr,16
		
		
		mov rax,60
		mov rdi,00
		syscall
		
	h_to_a:
		mov rbp,resultarr
		mov byte[count],4
	up1:
		rol ax,04
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
	
	
	hex_to_ascii:
			rol rax,16
			mov rbp, resarr
			mov byte[count], 12
		up:
			rol rax, 04h
			mov bl, al
			and bl, 0Fh
			cmp bl, 09h
			jle skip
			add bl, 07h
		skip:
			add bl, 30h
			mov [rbp], bl
			inc rbp
			dec byte[count]
			jnz up
			ret
	
