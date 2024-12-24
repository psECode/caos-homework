.intel_syntax noprefix
.global sum

.text
sum:
    mov r10d, 0
    mov r11, rcx
    mov ecx, edi
    mov r13, 0

iter:
    mov r10d, [rsi + r13]
    add r10d, [rdx + r13]
    mov [r11 + r13], r10d

    add r13, 4
    loop iter

    ret