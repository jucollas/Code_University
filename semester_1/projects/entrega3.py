#Juan Diego Collazos Mejia # ID: 8977837 # 2022 
####################################################################################################################################################################################
######### Como miembro de la comunidad académica de la Pontificia Universidad Javeriana Cali me comprometo a seguir los más altos estándares de integridad académica.###############
####################################################################################################################################################################################
# entrega 3

"""
funcion: seleccionContenedor
entrada: e) un entereo positivo; peso del paquete respectivo. bar) un lista de cantidad de elementos n, donde n es la cantidad de contenedores; puede contener un string ":" o enteros positivos que representan los pesos de los paquertes ya procesados en ese nivel
salida: un entero, en caso de que se puede almacenar el paquete en el contenedor seleccionado sera un entero positivo, en caso contrario retornara -1
"""
def seleccionContenedor(e , bar, tain):
	ans, i= 0, 0
	math = float("-inf")

	while i < len(bar):
 
		if bar[i] == ":":
			if tain[i] > math:
				math = tain[i]
				ans = i
		i += 1

	if tain[ans] < e:
		ans = -1
	else:
		tain[ans] -= e

	return ans

"""
funcion: barco
entrada: un entero positivo n; cantidad de contedores
salida: una lista contiene de n cantidad de elementos string ":" 
"""

def barco(n):
	i = 0
	ans = []
	while i < n:
		ans.append(":")
		i += 1
	return ans

"""
funncion: uva945
entrada: c) un entero positivo; cantidad de contenedores. tain) una lista de enteros positivos; pesos maximos de cada contenedor respectivo a la posicion.
p) un entero positivo; numero de paquetes. pkes) una lista de enteros postivos; peso de paquete en el orden respecto a la posicion 
salida: una lista de un entero positivo y una listas de listas, donde el elemento en la posicion 0 es una lista de listas de strings (el estado final del ordenamiento de los paquetes en los contenedores),
y su elemento en la poscion 1 es un entero positivo (peso de carga total). 
"""

def uva945(c, tain, p, pkes):
	pkp, e, i, j = 0, 0, 0, 0
	bar = barco(c)
	bar2 = list(bar)
	ax = []
	ans = []

	while i < p and e != -1:

		if j == c:
			ax.append(bar)
			bar = list(bar2)
			j = 0

		e = seleccionContenedor(pkes[i], list(bar), tain)

		if e != -1:
			bar[e] = str(pkes[i])
			pkp += pkes[i]
			j += 1
		i += 1

	if j >= 1:
		ax.append(bar)
	ans.append(ax)
	ans.append(pkp)

	return ans

"""
procedimiento: imprimir
entrada: l) una lista de lista que contiene string; estado final de ordenamiento de los paquetes en los contenedores n) un entero postivo; cantidad de contenedores
descripcion: imprime en el formato solicitado el estado final del ordeamiento de los paquetes en los contedores, imprime g veces en una sola linea el string "=", donde g es ((n*2) +1), 
imprime en una sola linea los numero de 1 hasta n con un espacio de separacion entre cada uno

"""
def imprimir(l, n):
	i, e, j = 0, len(l)-1, 0

	while e >= 0:
		print(" ".join(l[e])) 
		i = 0
		e -= 1

	while j < ((n*2)-1):
		print("=", end = "")
		j += 1
	print()
	j = 1

	while j <= n:

		print("%s" %(j), end = "")

		if j != n:
			print(" ", end = "")
				
		j += 1

"""
procedimiento: leerImprimir945
entrada:  c) un entero positivo; cantidad de contenedores. tain) una lista de enteros positivos; pesos maximos de cada contenedor respectivo a la posicion.
p) un entero positivo; numero de paquetes. pkes) una lista de enteros postivos; peso de paquete en el orden respecto a la posicion
descripcion: lee los datos de la manera solicitada, llama a las demas funciones y por ultimo imprime "cargo weinght:", "unused weight:", "unloaded weight:" con un entero postivo que lo describe asignado a cada uno
"""

def leerImprimir945():
	cnT, pkT = 0, 0
	
	c = input()

	while c != "":
		tain, pkes = [], []
		c = int(c)

		for i in range(c):
			ax = int(input())
			cnT += ax
			tain.append(ax)

		input()

		p = int(input())

		for i in range(p):
			ax = int(input())
			pkT += ax
			pkes.append(ax)

		ax = uva945(c, tain, p, pkes)
		ans = ax[0]

		imprimir(ans, c)
		print("\n")
		print("cargo weight: %d" %(ax[1]))
		print("unused weight: %d" %(cnT- ax[1]))
		print("unloaded weight: %d" %(pkT- ax[1]))
		print()

		cnT = 0
		pkT = 0

		input()

		c = input()

############################################################################################################################################################################################################