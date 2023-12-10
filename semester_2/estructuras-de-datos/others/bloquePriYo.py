def esPrimo(num, listprim):           # n = len(listprim)
	ans, i = True, 0                  # 2
	while i < len(listprim) and ans:  # n + 1
		if num % listprim[i] == 0:    # n
			ans = False            
		i += 1                        # n
	return ans                        # 1