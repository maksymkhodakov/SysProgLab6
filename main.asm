gcd:
        pushq   %rbp
        movq    %rsp, %rbp
        subq    $48, %rsp
        movl    %ecx, 16(%rbp)
        movl    %edx, 24(%rbp)
        movl    24(%rbp), %edx
        movl    16(%rbp), %eax
        movl    %eax, %ecx
        call    min
        movl    %eax, -4(%rbp)
        jmp     .L2
.L5:
        movl    16(%rbp), %eax
        cltd
        idivl   -4(%rbp)
        movl    %edx, %eax
        testl   %eax, %eax
        jne     .L3
        movl    24(%rbp), %eax
        cltd
        idivl   -4(%rbp)
        movl    %edx, %eax
        testl   %eax, %eax
        je      .L7
.L3:
        subl    $1, -4(%rbp)
.L2:
        cmpl    $0, -4(%rbp)
        jg      .L5
        jmp     .L4
.L7:
        nop
.L4:
        movl    -4(%rbp), %eax
        addq    $48, %rsp
        popq    %rbp
        ret