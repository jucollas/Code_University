#Juan Diego Collazos Mejia # ID: 8977837 # October 19st 2022
#########################################################################################################################################################################################
# entrega2
def leerImprimir945():
	n = 0
	c = input()

	while c != "":

		tain, pkes = [], []

		c = int(c)

		n += 1

		for i in range(c):
			ax = int(input())
			tain.append(ax)

		input()

		p = int(input())

		for i in range(p):
			ax = int(input())
			pkes.append(ax)

		print("caso: %d (Datos leidos)" %(n))
		print("Numero de contenedores: %d" %(c))
		print("Pesos de contenedores: %s" %(tain))
		print("Numero de paquetes: %d" %(p))
		print("Pesos de paquetes: %s" %(pkes))
		print()

		input()

		c = input()