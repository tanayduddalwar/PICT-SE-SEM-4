section .data


extern msg6,len6,scount,ncount,occrance,new,new_len



section .bss


extern cnt,cnt2,cnt3,scall,buffer



%macro scall 4

mov rax,%1

mov rdi,%2

mov rsi,%3

mov rdx,%4

syscall

%endmacro



section .text

global main2

main2:


global spaces,enters,occ


;************checking number of spaces ************************
spaces:

mov rsi,buffer


up:

mov al, byte[rsi]

cmp al,20H

je next3

inc rsi

dec byte[cnt]

jnz up


jmp next4


next3:

inc rsi

inc byte[scount]     ;increment space count

dec byte[cnt]

jnz up


next4:

add byte[scount], 30h

scall 1,1,scount, 2

scall 1,1,new,new_lenret


; ************ check new line ****************
enters:

mov rsi,buffer

up2:

mov al, byte[rsi]
cmp al,0AH          ;check enter key

je next5

inc rsi

dec byte[cnt2]

jnz up2


jmp next6

next5:

inc rsi

inc byte[ncount]             ;new line counter increment

dec byte[cnt2]

jnz up2


next6:

add byte[ncount], 30h

scall 1,1,ncount, 2

scall 1,1,new,new_len
ret


;*********** occurance of character *****************
occ:

mov rsi,buffer

up3:

mov al, byte[rsi]

cmp al,bl


je next7

inc rsi

dec byte[cnt3]

jnz up3

jmp next8


next7:

inc rsi

inc byte[occrance]

dec byte[cnt3]

jnz up3


next8:

add byte[occrance], 30h

scall 1,1,msg6,len6

scall 1,1,occrance, 1

scall 1,1,new,new_len
ret

;***********Text file ************

;abc.txt
;Hello
;Welcome to Pune
;This is microprocessor Lab
;***********************************



;*******output*******
; nasm -f elf64 p1 p1.asm
; nasm -f elf64 p2 p2.asm
; ld -o p p1.o p2.o
; ./p
;File opened successfully
;Spaces:
;6
;NewLines:
;3
;Enter character
;e
;No of occurances:
;5
;file closed successfuly