.global f
.text

f:
    mul x8, x3, x3
    mul x8, x8, x0
    mul x9, x1, x3
    add x8, x8, x9
    add x8, x8, x2
    mov x0, x8
    ret