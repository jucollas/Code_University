def m1(x, y):
	ans = False
	x = x + y
	y = x * y

	if x < y:
		ans = True
	return ans

def m2(x, y):
	ans = False
	if (x > y):
		tmp = x
		x = y
		y = tmp

	if x < y :
		ans = True
	return ans

def m3(d, a):
	ans = False
	if d % a == 0:
		ans = True

	return ans

