def ganadorPartido(name1, name2, l1, l2):
	x1 = 0
	x2 = 0
	i = 0
	while i < len(l1):

		if l1[i] > l2[i]:
			x1 += 1
		elif l1[i] < l2[i]:
			x2 += 1

		i += 1 

	if x1 > x2: ans = name1
	else: ans = name2

	return ans
	
	