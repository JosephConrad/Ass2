
section .text
    global distance

distance:
    enter 0,0
    sub rsp, 64

    movss [rbp-4], xmm0
    movss [rbp-8], xmm1
    movss [rbp-12], xmm2
    movss [rbp-16], xmm3
    movss [rbp-20], xmm4
    movss [rbp-24], xmm4
    movss xmm0, [rbp-4]
    subss xmm0, [rbp-20]
    movss xmm1, [rbp-4]
    subss xmm1, [rbp-20]
    mulss xmm0, xmm1
    movss xmm1, [rbp-8]
    subss xmm1, [rbp-24]
    movss xmm2, [rbp-8]
    subss xmm2, [rbp-24]
    mulss xmm1, xmm2
    addss xmm0, xmm1
    movss [rbp-28], xmm0

    movss xmm0, [rbp-12]

    movss xmm1, [rbp-16] 
    mulss xmm1, [rbp-16]
    subss xmm1, [rbp-28]

    sqrtss xmm1, xmm1

    subss xmm0, xmm1

    leave 
    ret