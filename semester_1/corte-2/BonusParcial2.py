#Juan Diego Collazos Mejia # ID: 8977837 # October 10st 2022
####################################################################################################################################################################################
from math import*
#########################################################################################################################################################################################
#1
def posicion(l,a):
	i = 0
	ans = -1
	while i < len(l) and not ans == i:
		if l[i] == a:
			ans = i
		i += 1
	return ans

def acomodar(n, r):
	i = 0
	ans = []
	ax = []

	while i < len(n):
		ax.append(n[i])
		ax.append(r[i])
		ans.append(ax)
		ax = []
		i += 1

	return ans
def conteoPeliculasActor(l):
	i = 0
	ans = None
	gen = []
	rec = []
	ax = []
	while i < len(l):

		x = posicion(gen, l[i][2])

		if x == -1:
			ax.append(l[i][2])
			ax.append(l[i][])
		else: 
			rep[x] += 1

		e += 1
		i += 1

	ans = acomodar(name, rep)

	return ans