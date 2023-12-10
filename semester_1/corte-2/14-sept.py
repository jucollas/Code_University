def imprimirlinea(n, m, cad):
	for x in range(n - m):
		print(" ", end = "")
	for x in range(m+1):
		print(cad, end = "")

#print(imprimirlinea(12, 8, "x"))

def sumandigitos(n):
	a=0
	while n > 0:
		a += (n % 10)
		n //= 10
	return a
#print(sumandigitos(123456789))

def diferentede(x,a,b,c,d,e,f,g,h):
	ans=False
	if (x != a) and (x != b) and (x != c) and (x != d) and (x != e) and (x != f) and (x != g) and (x != h):
		ans=True
	return ans

def nohorizontalreinaMatareina(r1x,r2x,r3x,r4x,r5x,r6x,r7x,r8x,r9x):
	ans=False
	if diferentede(r1x,r2x,r3x,r4x,r5x,r6x,r7x,r8x,r9x) and diferentede(r2x,r1x,r3x,r4x,r5x,r6x,r7x,r8x,r9x) and diferentede(r3x,r2x,r1x,r4x,r5x,r6x,r7x,r8x,r9x) and diferentede(r4x,r2x,r3x,r1x,r5x,r6x,r7x,r8x,r9x) and diferentede(r5x,r2x,r3x,r4x,r1x,r6x,r7x,r8x,r9x) and diferentede(r6x,r2x,r3x,r4x,r5x,r1x,r7x,r8x,r9x) and diferentede(r7x,r2x,r3x,r4x,r5x,r6x,r1x,r8x,r9x) and diferentede(r8x,r2x,r3x,r4x,r5x,r6x,r7x,r1x,r9x):     
		ans=True
	return ans

print(nohorizontalreinaMatareina(1,2,3,4,5,6,7,8,8))
#print(diferentede(1,2,3,4,5,6,7,8,9))