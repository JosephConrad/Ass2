DEFAULT REL

    extern malloc
    extern free

;; Sekcja danych
section .bss
    kule        resq    1
    obraz       resq    1
    szer        resd    1
    wys         resd    1
    liczbaKul   resd    1

    x           resd    1
    y           resd    1 
    i           resd    1 
    bestNo      resd    1 
    globalCut   resd    1 
    cut         resd    1 
    best        resd    1
    dist        resd    1

;; We start our program with the start procedure
section .text
    global sztokfisz                  ; musi  byc zadeklarowny dla linkera (gcc)
    global ifCut
    global distance 


sztokfisz:
    enter 0,0
    sub rsp, 64
    mov [kule], rdi
    mov [obraz], rsi
    mov [szer], edx
    mov [wys], ecx
    mov [liczbaKul], r8d


    mov dword [y], 0
WYS_LOOP:
    mov eax, dword [y]
    cmp eax, [wys]
    jge AFTER_WYS_LOOP

    mov dword [x], 0
SZER_LOOP:
    mov eax, dword [x]
    cmp eax, [szer]
    jge AFTER_SZER_LOOP

    




SZER_LOOP_FINISH:
    mov eax, dword [x]
    add eax, 1
    mov dword [x], eax
    jmp SZER_LOOP


AFTER_SZER_LOOP:
    jmp WYS_LOOP_FINISH

WYS_LOOP_FINISH:
    mov eax, dword [y]
    add eax, 1
    mov dword [y], eax
    jmp WYS_LOOP

AFTER_WYS_LOOP:

    leave 
    ret

ifCut:
    enter 0,0
    sub rsp, 64

    leave 
    ret

distance:
    enter 0,0
    sub rsp, 64

    leave 
    ret