# if ( n%2 == 0 ) n++
lw    $t0, 4($gp)         
ori   $t0, $t0, 1         
sw    $t0, 4($gp)         
