# A[i] = A[i/4] + 3; 
lw     $t0, 0($gp)       
srl    $t1, $t0, 2       
sll    $t1, $t1, 2       
add    $t1, $gp, $t1     
lw     $t1, 28($t1)     
addi   $t1, $t1, 3       
sll    $t2, $t0, 2        
add    $t2, $t2, $gp     
sw     $t1, 28($t2)      
# A[i+1] = 2;
addi   $t1, $zero, 2    
sw     $t1, 32($t2)      
