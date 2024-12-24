.intel_syntax noprefix
.global very_important_function
.extern A

.data
input_mask:
    .string "%d"
output_mask:
    .string "%lld "
input:
    .quad 0


.text
very_important_function:
    mov rcx, rdi
    mov r13, 0
    mov r12, A
x:
    push rcx
    lea rdi, [input_mask]
    lea rsi, [input]
    mov rax, 0
    call scanf
    pop rcx

    movsxd r14, [input]
    movsxd rax, [r12 + r13]
    imul r14

    push rcx
    lea rdi, [output_mask]
    mov rsi, rax
    mov rax, 0
    call printf
    pop rcx

    add r13, 4
    loop x
    ret