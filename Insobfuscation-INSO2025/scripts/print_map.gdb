define print_map
  set logging file map.txt
  set logging on
  set $node = 0x5555555c86a0
  set $counter = 0

  while $counter <= 282
    printf "Node Address: %p\n", $node
    printf "Key: %d\n", *(int*)($node+32)
    printf "Value 1: %u\n", *(unsigned int*)($node+36)
    printf "Value 2: %u\n", *(unsigned char*)($node+40)

    
    set $counter = $counter + 1
    
    if (*(void**)($node+24) != 0x0)
      set $node = *(void**)($node+24)
      while (*(void**)($node+16) != 0x0)
        set $node = *(void**)($node+16)
      end
    else
      set $parent = *(void**)($node+8)
      while $node == *(void**)($parent+24)
        set $node = $parent
        set $parent = *(void**)($node+8)
      end
      set $node = $parent
    end
  end
  set logging off
end




