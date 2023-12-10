#Juan Diego Collazos Mejia # ID: 8977837 # September 24th 2022
##########################################################################################################
from math import*
###########################################################################################################
#1
def imprimirSucesion(n):
	for x in range(1, n + 1):
		a = (-1 / x) ** x
		if x < n:
			print("%.4f, " % (a), end = "")
		else:
			print("%.4f" % (a))

###########################################################################################################
#2
def prin(e, a):
	for x in range(e):
		print(" ", end = "")
	for x in ra
	nge(a):
		print("*", end = "")
	print()

def imprimirAsteriscos(n):
	a = 1
	i = 0
	e = (n * 2) - 2
 
	while a > 0:
		if e > 0:
			prin(e, a)
			a += 2
			e -= 2
		else:
			prin(i, a)
			a -= 2
			i += 2
			
#############################################################################################################
#3
def f(x):
	ans = x ** 3
	return ans

def simpsonRule(a, b, n):
	h = (b - a) / n
	ac = f(a) + f(a + (n * h))

	for k in range(1, n):
		if k % 2 == 0:
			ac += 2 * f(a + (k * h))
		else:
			ac += 4 * f(a + (k * h))

	ans = (h / 3) * ac
	return ans

##############################################################################################################
#4
def factorial(n):
  ans = 1
  for x in range(1, n + 1):
    ans *= x
  return ans

def e(n):
	e = 2
	for x in range(2, n):
		e += (1 / factorial(x))
	print("%f" %(e))

################################################################################################################
#5
def imprimirLineasNumeros(n):
	a = 1
	b = n
	for x in range(1, n + 1):
		c = b
		while a <= b:
			print("%d " % (b), end = "")
			b -= 1
		print()
		a = c + 1
		b = c + n - x

##################################################################################
#6
def filtrarValoresEnPosicion(l):
	i = 0
	ans = []
	while i < len(l):
		if l[i] == i:
		  ans.append(i)
		i += 1
	return ans

#########################################################################################
#7
def reemplazar(l, v1, v2):
	i = 0
	while i < len(l):
		if l[i] == v1:
			l[i] = v2
		i += 1
	return l

########################################################################################
#8
def perimetroFigura(lx, ly):
	ans = 0
	i = 0
	while i < len(lx):
		if i < len(lx) - 1:
			x1 = lx[i]
			x2 = lx[i + 1]
			y1 = ly[i]
			y2 = ly[i + 1]
			ans += sqrt(((x1 - x2) ** 2) + ((y1 - y2) ** 2))
		else:
			x1 = lx[i]
			x2 = lx[0]
			y1 = ly[i]
			y2 = ly[0]
			ans += sqrt(((x1 - x2) ** 2) + ((y1 - y2) ** 2))
		i += 1
	return ans

#########################################################################################
#9
def factorial(n):
  ans = 1
  for x in range(1, n + 1):
    ans *= x
  return ans

def factAcumInv(n):
	i = factorial(n)
	ans = []
	for x in range(n, 0, -1):
		ans.append(i)
		i //= x
	return ans

#######################################################################################
#10
def giveGift(x):
    if 1 <= x <= 99 :
      ans = 1
    elif x == 0:
    	ans =- 1
    return ans

def emoogleBalance():
	f = 1
	x = True
	while x:
		n = int(input())
		if n == 0:
			x = False
		else:
			ac = 0
			for y in range(n):
				z = int(input())
				ac += giveGift(z)
			print("Case %d: %s" % (f, ac))
			f += 1
			

#########################################################################################
#11
def lumberjackSequencing():
	i = int(input())
	print("Lumberjacks:")
	for x in range(i):
		a = int(input())
		b = int(input())
		c = int(input())
		d = int(input())
		e = int(input())
		f = int(input())
		g = int(input())
		h = int(input())
		i = int(input())
		j = int(input())
		if (a < b < c < d < e < f < g < h < i < j) or (a > b > c > d > e > f > g > h > i > j):
			print("Ordered") 
		else:
			print("Unordered")

###########################################################################################


