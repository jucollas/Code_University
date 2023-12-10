def figo(n):
	if n == 0:
		ans = 0
	elif n == 1:
		ans = 1
	else:
		ans = figo(n - 1) + figo(n - 2)

	return ans

def figo2(n):
	if n == 0:
		ans = 0
	else:
		ans, a, b = 1, 0, 1
		for i in range(1, n):
			ans = a + b
			a = b
			b = ans 
	return ans

print(figo2(10000))