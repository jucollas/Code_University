def fibonacci(n):
	if n == 0:
		ans = 0
	elif n == 1:
		ans = 1
	else:
		ans = figo(n - 1) + figo(n - 2)
		
	return ans