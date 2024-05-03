%macro rw ,3
mov rax,%1
mov rdi,%1
mov rsi,%2
mov rdx,%3
syscall
%endmacro

section.data
msg1 db "Number is:"
lmsg1 equ $-msg1
msg2 db "Factorial is:"
lmsg2 equ $-msg2
num resb 2

section.text
global_start:
_start
pop rbx
pop rbx
pop rbx

mov [num],rbx
rw,1,msg1,lmsg1
rw,1,[num],02

call a_to_h
mov rax,rbx
call facto

facto:
dec rbx
cmp rbx,01
je b1
mul rbx
call facto
b1:
ret

a_to_h:
mov rsi,[num]
up1:
rol rax,04
mov bl,al
and,bl,0Fh
cmp bl,39h
jae A1
sub bl,7h
AL:
sub bl,30h
mov [rsi],bl
inc rsi













