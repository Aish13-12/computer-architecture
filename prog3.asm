# i=N*N+5*N
lw    $t0, 4($gp)       
add   $t1, $t0, $zero   
addi  $t1, $t1, 5       
mult  $t1, $t0     
sw    $t1, 0($gp) 
