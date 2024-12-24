.global sum
.text //x8 -counter, x9 - buff, x10 - pointer

sum:
    mv x8, 0
    mv x10, 0
LoopBegin:
    cmp x8, x1  
    bge LoopEnd
    ldr x9, [x2, x10]
    add x0, x0, x9
    add x10, x10, 4
    add x8, x8, 1
    b LoopBegin
LoopEnd:
    ret