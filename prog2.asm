# STRCPY. 
addi  $sp, $sp, 4
sw    $s0, 0($sp)
add   $s0, $zero, $zero
# L1:(address with offset->96)
add   $t1, $s0, $a1
lb    $t2, 0($t1)
add   $t3, $s0, $a0
sb    $t2, 0($t3)
beq   $t2, $zero, 120
addi  $s0, $s0, 1
j     96
# L2:(->120)
lw    $s0, 0($sp)
addi  $sp, $sp, 4
jr    $ra
