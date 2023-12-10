def obetenerulnumero(x):
	x %= 10
	return x

def quitanul(x):
	x //= 10
	return x

def noverticalreinamatareina(x,r2x,r3x,r4x,r5x,r6x,r7x,r8x):
	ans=True
	if abs(x-r2x) == 1 or abs(x-r3x) == 2 or abs(x-r4x) == 3 or abs(x-r5x) == 4 or abs(x-r6x) == 5 or abs(x-r7x) == 6 or abs(x-r8x) == 7 or abs(x-r9x) == 8:
		ans=False
	return ans

def diferentede(x,a,b,c,d,e,f,g,h):
	ans=False
	if (x != a) and (x != b) and (x != c) and (x != d) and (x != e) and (x != f) and (x != g) and (x != h):
		ans=True
	return ans

def nohorizontalreinaMatareina(r1x,r2x,r3x,r4x,r5x,r6x,r7x,r8x):
	ans=False
	if diferentede(r1x,r2x,r3x,r4x,r5x,r6x,r7x,r8x) and diferentede(r2x,r1x,r3x,r4x,r5x,r6x,r7x,r8x) and diferentede(r3x,r2x,r1x,r4x,r5x,r6x,r7x,r8x) and diferentede(r4x,r2x,r3x,r1x,r5x,r6x,r7x,r8x) and diferentede(r5x,r2x,r3x,r4x,r1x,r6x,r7x,r8x) and diferentede(r6x,r2x,r3x,r4x,r5x,r1x,r7x,r8x) and diferentede(r7x,r2x,r3x,r4x,r5x,r6x,r1x,r8x) and diferentede(r8x,r2x,r3x,r4x,r5x,r6x,r7x,r1x):     
		ans=True
	return ans

def nomatareina(x):
	ans=False
	a=obetenerulnumero(x)
	b=obetenerulnumero(quitanul(a))
	c=obetenerulnumero(quitanul(b))
	d=obetenerulnumero(quitanul(c))
	e=obetenerulnumero(quitanul(d))
	f=obetenerulnumero(quitanul(e))
	g=obetenerulnumero(quitanul(f))
	h=obetenerulnumero(quitanul(g))
	if noverticalreinamatareina(a,b,c,d,e,f,g,h) and nohorizontalreinaMatareina(a,b,c,d,e,f,g,h):
		ans=True
	return ans

print(nomatareina(25713064))

def contador():
	ans=0
	for x in range(1432,1400):
		if nomatareina(x):
			ans+=1
	return ans
		
#print(contador())



