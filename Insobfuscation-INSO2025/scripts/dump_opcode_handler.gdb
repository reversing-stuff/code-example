define dump_rdi_rsi
    set $r = $rdi
    set $a = *(void**)(*(void**)(*(void**)$rsi))
    continue
end

define print_values
    set logging file opcodeToHandler.txt
    set logging on
    printf "0x%lx:0x%x\n", $a, $r
    set logging off
    continue
end

break *0x55555555829b
break *0x5555555582D6
commands 1
    silent
    dump_rdi_rsi
    continue
end

commands 2
    silent
    print_values
    continue
end
run

