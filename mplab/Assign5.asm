%macro rw 3
mov rax,%1
mov rdi,01
mov rsi,%2
mov rdx,%3
syscall
%endmacro

section .data
        n1 dq 0000000000000003h
        n2 dq 0000000000000002h
       
        menu db 10d,13d,"**********MENU**********"
             db 10d,13d,"1. Addition"
             db 10d,13d,"2. Subtraction"
             db 10d,13d,"3. Multiplication"
             db 10d,13d,"4. Division"
             db 10d,13d,"5. Exit"
             db 10d,13d,"Enter your Choice: "
        menu_len equ $-menu

        m1 db 10d,13d,"Addition: "
        l1 equ $-m1
        m2 db 10d,13d,"Substraction: "
        l2 equ $-m2
        m3 db 10d,13d,"Multiplication: "
        l3 equ $-m3
        m4 db 10d,13d,"Division: "
        l4 equ $-m4
        count db 00h
        

section .bss
        resultarr resb 16 ;to store the result of operation
        choice resb 2
        res resb 1
       
section .text
        global _start:
        _start:

        up: rw 1,menu,menu_len
       rw 0,choice,2

        cmp byte[choice],'1'
        je case1
        cmp byte[choice],'2'
        je case2
        cmp byte[choice],'3'
        je case3
        cmp byte[choice],'4'
        je case4
        cmp byte[choice],'5'
        je case5

        case1: rw 1,m1,l1
                call addition
                jmp up

        case2: rw 1,m2,l2
       call substraction
       jmp up

        case3: rw 1,m3,l3
       call multiplication
       jmp up

        case4: rw 1,m4,l4
            call division
                jmp up

        case5:  mov rax,60
                mov rdi,0
                syscall


;arithmetic operations
addition:
        mov rcx,qword[n1]
        add rcx,qword[n2]
        mov qword[res],rcx
        mov rax,qword[res]
        call h_to_a
        ret



substraction:

        mov rcx,qword[n1]
        sub rcx,qword[n2]
        mov qword[res],rcx
        mov rax,qword[res]
        call h_to_a
        ret




multiplication:
        mov rcx,qword[n1]
        mul qword[n2]
        mov rax,qword[res]
        call h_to_a
        ret


division:
        mov rcx,qword[n1]
        div qword[n2]
        mov rax,qword[res]
        call h_to_a
        ret

h_to_a:
mov al,byte[res]
mov rbp,resultarr
mov byte[count],16
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