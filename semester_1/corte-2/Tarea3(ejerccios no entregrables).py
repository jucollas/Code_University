def operacion1(n):
	i=n
	res=0
	while i>0:
		print(i)
		res+=i
		i=i//2
	return res

#operacion1(100)
#print(operacion1(100))

def operacion2(n):
	res=0
	for j in range(n,0,2):
		print(j)
		res+=1
	return res
#operacion2(10)
#print(operacion2(10))

def incognita(num, num2):
	a, b = 1, 2
	while a <= num:
		c=a
		b, a = b + (c * num2), a + 1
	return b

#print(incognita(4,5))