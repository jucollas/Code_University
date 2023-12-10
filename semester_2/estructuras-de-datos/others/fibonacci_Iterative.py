def fibonacci(n):
	if n == 0:                  # 1
		ans = 0                 
	else:
		ans, a, b = 1, 0, 1     # 3
		for i in range(1, n):   # n
			ans = a + b         # n - 1
			a = b               # n - 1
			b = ans             # n - 1

	return ans                  # 1