gcd:
        pushq   %rbp
        movq    %rsp, %rbp
        subq    $16, %rsp
        movl    %ecx, 16(%rbp)
        movl    %edx, 24(%rbp)
        jmp     .L2
.L3:
        movl    24(%rbp), %eax
        movl    %eax, -4(%rbp)
        movl    16(%rbp), %eax
        cltd
        idivl   24(%rbp)
        movl    %edx, 24(%rbp)
        movl    -4(%rbp), %eax
        movl    %eax, 16(%rbp)
.L2:
        cmpl    $0, 24(%rbp)
        jne     .L3
        movl    16(%rbp), %eax
        addq    $16, %rsp
        popq    %rbp
        ret