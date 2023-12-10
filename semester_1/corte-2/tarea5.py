#Juan Diego Collazos Mejia # ID: 8977837 # October 7st 2022
####################################################################################################################################################################################
from math import*
#########################################################################################################################################################################################
#1
def sumasAcumuladas(l):
	i, ac = 0, 0
	ans = []
	while i < len(l):
		ac += l[i]
		ans.append(ac)
		i += 1
	return ans

###########################################################################################################################################################################
#2
def listaStringAint(l):
	ans = []
	i = 0
	while i < len(l):
		x = int(l[i])
		ans.append(x)
		i += 1
	return ans

def listaIntAString(l):
	ans = []
	i = 0
	while i < len(l):
		x = str(l[i])
		ans.append(x)
		i += 1
	return ans

def listadesde(l, i):
	ans = []
	while i < len(l):
		x = l[i]
		ans.append(x)
		i += 1
	return ans

def leerImprimirSumasAcumuladas():
	t = int(input())
	i = 1
	while i <= t:
		x = input()
		ax1 = x.split(" ")
		ax2 = listaStringAint(ax1)
		ax3 = listadesde(ax2, 1)
		ax4 = sumasAcumuladas(ax3)
		ax5 = listaIntAString(ax4)
		ans = ", ".join(ax5)
		print("Case %d: %s" %(i , ans))
		i += 1

###########################################################################################################################################################################
#3
def matrizPorVector(mat, v):
	e, i = 0, 0
	n, m = len(mat), len(mat[0]) 
	ans, ac = [], []

	while e < n:

		while i < m:
			x = mat[e][i]
			y = v[i]
			z = x * y
			ac.append(z)
			i += 1

		ans.append(ac)
		ac = []
		i = 0
		e += 1
	return ans

#########################################################################################################################################################################
#4
def crearDeListaDeConteo(lPar):
	e , i= 0, 0
	l = len(lPar)
	ans = []
	while e < l:
		v = lPar[e][0]
		r = lPar[e][1]

		while i < r:
			ans.append(v)
			i += 1
		i = 0
		e += 1
	return ans

###########################################################################################################################################################################
#5
def esSubcadena(cad1, cad2):
	l1, l2 = len(cad1), len(cad2)
	e, i, j = 0, 0, 0
	ans = False

	while e < l1  and j + l1 <= l2:

		if cad1[e] == cad2[i]:
			e += 1
			i += 1
		else:
			e = 0
			i = j + 1
			j += 1

	if e == l1 : ans = True

	return ans

#######################################################################################################################################################################
#6
#(a)
def peliculasFrasadas(l):
	i = 0
	ans = []

	while i < len(l):

		if l[i][4] > l[i][5]:
			ans.append(l[i][0])

		i += 1
	return ans

#(b)

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
	e = 0
	ans = None
	name = []
	rep = []
	while i < len(l):

		while e < len(l[i][6]):

			x = posicion(name, l[i][6][e])

			if x == -1:
				name.append(l[i][6][e])
				rep.append(1)
			else: rep[x] += 1

			e += 1
		e = 0
		i += 1

	ans = acomodar(name, rep)

	return ans

#########################################################################################################################################################################
#7
def posicion(l,a):
	i = 0
	ans = -1
	while i < len(l) and not ans == i:
		if l[i] == a:
			ans = i
		i += 1
	return ans

def listas(l):
	i = 0
	name = []
	points = []
	ans = []
	while i < len(l):

		x = posicion(name, l[i][0])
		y = posicion(name, l[i][2])

		if x == -1:
			name.append(l[i][0])
			points.append(0)
			x = len(name)-1
			
		if y == -1:
			name.append(l[i][2])
			points.append(0)
			y = len(name) - 1

		if l[i][1] > l[i][3]:
			points[x] += 3
		elif l[i][1] < l[i][3]:
			points[y] += 3
		else:
			points[x] += 1
			points[y] += 1
		
		i += 1

	ans.append(name)
	ans.append(points)

	return ans

def determinarGanador(l):
	i = 0
	math = float("-inf")
	ax = listas(l)
	ans = []
	while i < len(ax[1]):
		if ax[1][i] > math:
			math = ax[1][i]
			imax = i
		i += 1

	ans.append(ax[0][imax])
	ans.append(math)

	return ans

#######################################################################################################################################################################