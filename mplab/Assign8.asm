%macro rw 3
mov rax,%1
mov rdi,01
mov rsi,%2
mov rdx,%3
syscall
%endmacro

section .data
	msg1 db "Before transfer: ",0XA,0XD
	msglen1 equ $-msg1
	msg3 db "Source: ",0XA,0XD
	msglen3 equ $-msg3
	msg4 db "Dest Block : ",0XA,0XD
	msglen4 equ $-msg4
	msg2 db "After overlapped: ",0XA,0XD
	msglen2 equ $-msg2
	msg3 db 10,13,"address: "
	msglen3 equ $-msg3
	msg4 db " value: "
	msglen4 equ $-msg4
	
	sblock db 10h,20h,30h,40h,50h
    dblock db 0h,0h,0h,0h,0h
	count db 5
	cnt db 7
	cnt2 db 05h
	count3 dw 05h
section .bss
	resultarr resb 16
	
section .text
	global _start
		_start:

        rw,1,msg1,lmsg1
		rw,
        mov rsi,sblock
        call block_display

        rw,1,msg2,lmsg2
        mov rsi,dblock
        call block_display

        mov rax,60
        mov rdi,00

block_transfer:
mov rsi,sblock+4
mov rdi,dblock+2
up:
movsb
dec rsi
dec rdi
dec byte[count]
jnz up
ret

block_display:
mov rbp,5
next_num:
mov al,[rsi]
push rsi
call h_to_a
pop rsi
inc rsi
dec byte[count];
jnz block_display

h_to_a:
mov rbp,resultarr
mov byte[count],16
up1:
rol rax,4
mpv bl,al
and bl,0Fh
cmp bl,09h
jle down
add bl,7h

down:
add bl,30h
mov [rbp],bl
		inc rbp
		dec byte[count]
		jnz up1
        ret






