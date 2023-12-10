def estaenlista(l,a):
	i = 0
	ans = False
	while i < len(l) and not(ans):
		if l[i] == a:
			ans = True
		i += 1
	return ans

def nombreEquipos(l):
	i = 0
	ans = []
	while i < len(l):

		if not(estaenlista(ans, l[i][0])):
			ans.append(l[i][0])
		if not(estaenlista(ans, l[i][2])):
			ans.append(l[i][2])

		i += 1
	return ans

def puntajePartido(l):
	if l[1] > l[3]:
		l[1] = 3
		l[3] = 0
	elif l[1] < l[3]:
		l[1] = 0
		l[3] = 3
	else:
		l[1] = 1
		l[3] = 1

	return l

def puntajeListaPartido(l):
	i = 0
	while i < len(l):
		puntajePartido(l[i])
		i += 1

	return l

def contador(l, v):
	i = 0
	ac = 0
	ans = []
	while i < len(l):
		if l[i][0] == v:
			ac += l[i][1]
		if l[i][2] == v:
			ac += l[i][3]
		i += 1
	ans.append(v)
	ans.append(ac)
	return ans

def determinarPuntaje(l):
	i = 0
	nom = nombreEquipos(l)
	put = puntajeListaPartido(l)
	ax = []
	ans = []

	while i < len(nom):
		ax = contador(put, nom[i])
		ans.append(ax)
		ax = []
		i+=1

	return ans

def determinarGanador(l):
	i = 0
	mat = float("-inf")
	ax = determinarPuntaje (l)
	ans = None

	while i < len(ax):

		if ax[i][1] > mat:
			ans = ax[i]
			mat = ax[i][1]
		i += 1

	return ans