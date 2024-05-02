;-------------------------------HEX TO BCD--------------------------------------
%macro rw %3
mov rax,%1
mov rdi,%1
mov rsi,%2
mov rdx,%3
syscall
%endmacro 

section .data
msg1 db"Enter 4 digit hex number"
lmsg1 equ $-msg1
msg2 db "bcd number is:"
lmsg2 equ $-msg2
count db 04h
msg3 db"Error performing operation"
lmsg3 equ $-msg3


section .bss
buff resb ,5


section .text
global_start:
_start:
rw,1,msg1,lmsg1
rw,0,buff,5

up:
mov rsi,buffer
loop:
rol rbx,4
mov al,[rsi]
cmp al,0
jbe error
cmp al,9
jmp sub30

cmp al,'a'
jbe error
cmp al 'f'
jmp sub57

cmp al,'A'
jbe error
cmp al,'F'
jmp sub37

sub57:sub al,20
sub37:sub al,7
sub30:sub al,30

add bx,al
inc rsi
dec byte[count]
jnz loop

error:
rw,1,msg3,lmsg3


exit:
mov rax,60
mov rdi,00

;-------------------------------BCD TO HEX--------------------------------------
section. data
msg1 db"Enter 5 digit bcd number"
lmsg1 equ $-msg1
msg2 db "Hec number is:"
lmsg2 equ $-msg2
count db 6

section.bss
resultarr resb 16
buffer resb 6


section.text
global_start:
_start:
bcd_to_hex:
rw,1,msg1,lmsg1
rw,0,buffer,6
xor rax,rax  ;rax=0
mov rsi,buffer
mov rbx,10  ;rax=rax*rbx+cl


up:
mul rbx
mov cl,[rsi]
sub cl,30h
add rax,cl
inc rsi
dec byte[count]
jnz up


mov [resultarr],rax
call h_to_a








