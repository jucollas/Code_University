"""
Juan Diego Collazos Mejia  ID: 8977837  2022 
========================================================================================================================================================================
====== Como miembro de la comunidad académica de la Pontificia Universidad Javeriana Cali me comprometo a seguir los más altos estándares de integridad académica.======
========================================================================================================================================================================

Entrega 4
"""
from sys import stdin

"""
funcíon: seleccionContenedor
entrada:
	package: un entero positivo (representa el peso del paquete respectivo).
	boat: una lista que contiene cadenas (si la cadena es ":" representa un espacio vacio en ese nivel, si contiene un a cadena de numero positivo representa un paquete ya procesado).
	containersCap: una lista que contiene numeros entreros positivos (capacidad maxima contenedores). 

salida: un entero, en caso de que se pueda almacenar el paquete en el contenedor seleccionado sera un entero positivo (representa la posicion del contenedor seleccionado segun los criterios), en caso contrario retornara -1.
"""
def seleccionContenedor(package, boat, containersCap):
	ans, i= 0, 0
	math = float("-inf")

	while i < len(boat):
		if boat[i] == ":":
			if containersCap[i] > math:
				math = containersCap[i]
				ans = i
		i += 1

	if containersCap[ans] < package: ans = -1
	else: containersCap[ans] -= package

	return ans

"""
funncion: uva945
entrada: 
	containsNum: Un entero positivo (cantidad de contenedores). 
	containersCap: Una lista de enteros positivos (capacidad maxima de cada contenedor).
	packegsNum: Un entero positivo (cantidad de paquetes). 
	packagseWe: Una lista de enteros positivos. (peso de cada paquete).

salida: Una tupla con dos elementos, una lista de listas que contiene cadenas (estado final de procesamiento de los paquetes) y un entero positivo (peso total cargado).
"""

def uva945(containsNum, containersCap, packegsNum, packagseWe):
	cargoWeight, location, i, j = 0, 0, 0, 0
	ax = [[":" for i in range(containsNum)]]

	while i < packegsNum and location != -1:

		if j == containsNum:
			ax.append([":" for i in range(containsNum)])
			j = 0

		location = seleccionContenedor(packagseWe[i], ax[-1], containersCap)

		if location != -1:
			ax[-1][location] = str(packagseWe[i])
			cargoWeight += packagseWe[i]
			j += 1
		i += 1

	if j == 0:
		ax.pop(-1)

	ans = (ax, cargoWeight)

	return ans

"""
procedimiento: imprimir
entrada: 
	boat: Una lista de listas que contienen cadenas de numeros (estado final de ordenamiento de los paquetes en cada nivel de los contenedores).
	containsNum: Un entero positivo (numero de contenedores).
	cargoWeight: Un entero positivo (total de peso cargado).
	totalContainerAb: Un entero positivo (la suma de la capacidad de todos los contenedores).
	totalPackageWe: Un entero positivo (la suma del peso de todos los paquetes).

descripcion: imprime la matriz y demas elementos con el formato solicitado.

"""
def imprimir(boat, containsNum, cargoWeight, totalContainerAb, totalPackageWe, caso):

	if caso != 1:
		print()

	num = [str(i) for i in range(1,containsNum + 1)]

	for i in range(len(boat)-1, -1, -1):
		print(" ".join(boat[i]))

	for i in range(containsNum*2-1):
		print("=", end = "")

	print()
	print(" ".join(num))
	print()
	print("cargo weight: %d" %(cargoWeight))
	print("unused weight: %d" %(totalContainerAb - cargoWeight))
	print("unloaded weight: %d" %(totalPackageWe - cargoWeight))

"""
procedimiento: leerImprimir945
entrada:
	containsNum: Un entero positivo (cantidad de contenedores). 
	containersCap: Una lista de enteros positivos (capacidad maxima de cada contenedor).
	packegsNum: Un entero positivo (cantidad de paquetes). 
	packagseWe: Una lista de enteros postivos. (peso de cada paquete)

descripcion: lee los datos de la manera solicitada y llama a las demas funciones.
"""

def leerImprimir945():
	caso = 1
	containsNum = stdin.readline()

	while containsNum != "":
		totalContainerAb, totalPackageWe = 0, 0
		containersCap, packagseWe = [], []

		containsNum = int(containsNum)

		for i in range(containsNum):
			capacity = int(stdin.readline())
			totalContainerAb += capacity
			containersCap.append(capacity)

		stdin.readline()

		packegsNum = int(stdin.readline())

		for i in range(packegsNum):
			weight = int(stdin.readline())
			totalPackageWe += weight
			packagseWe.append(weight)

		ans, cargoWeight = uva945(containsNum, containersCap, packegsNum, packagseWe)

		imprimir(ans, containsNum, cargoWeight, totalContainerAb, totalPackageWe, caso)

		stdin.readline()

		containsNum = stdin.readline()
		caso += 1

leerImprimir945()
#=======================================================================================================================================================================