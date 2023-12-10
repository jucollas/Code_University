# Juan Diego Collazos Mejia # 07 october 2022
######################################################################################################################################################################
#6
#(b)

def posicion(l,a):
	i = 0
	ans = -1
	fag = True
	while i < len(l) and fag:
		if l[i] == a:
			ans = i
			fag = False
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
	rep= []
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
	fag = True
	while i < len(l) and fag:
		if l[i] == a:
			ans = i
			fag = False
		i += 1
	return ans

def listas(l):
	i = 0
	name = []
	points = []
	ans=[]
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