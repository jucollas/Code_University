# Juan Diego Collazos Mejia # ID: 8977837 # November 13st 2022
#########################################################################################################################################################################################
#########################################################################################################################################################################################
#1
"""
funcion: obtenerElementos
entrada: recibe una lista de listas de numeros
salida: una lista que contiene de los numeros repetidos dos o mas veces en la lista de listas de input
"""
def obtenerElementos(m):
	ax1 = set()
	ax2 = set()
	for lista in m:
		conj = set(lista)  
		for num in conj:
			if not num in ax2:
				ax2.add(num)
			else:
				ax1.add(num)
	ans = list(ax1)
	return ans

################################################################################################################################################################################################
#2
"""
funcion: esPangrama
entrada: cadena de texto
salida: un Boleano, True si el texto es un pangrama, False si no lo es
"""
def esPangrama(cad):
	ax = set()
	for caracter in cad:
		if ord("a") <= ord(caracter) <= ord("z") or caracter == "ñ":
			ax.add(caracter)
		elif ord("A") <= ord(caracter) <= ord("Z") or caracter == "Ñ":
			minus =  chr(ord(caracter) + 32)
			ax.add(minus)

	ans = (len(ax) == 27)
	return ans

################################################################################################################################################################################################
#3
"""
(a)
funcion: obtenerEstudiantes
entrada: un diccionario con informacion que relaciona los nombres de cursos de una universisdad con una lista de lista que contiene la informacion basica de los estudiantes que estan matriculados en dichos cursos
salida: una lista que contiene los nombres de los estudiantes que estan madriculado en por lo menos algun curso de la universidad
"""

def obtenerEstudiantes(dic):
	ax = set()
	for curso in dic:
		for estudiante in dic[curso]:
			ax.add(estudiante[0])
	ans = list(ax)
	return ans

"""
(b)
funcion: estudiantesEnComun 
entrada: un dicionario con la informacion de los cursos y el nombre de dos cursos
salida: una lista de tuplas que contienen de los nombres y codigos de los estudiantes que se encuentre matriculados en ambos cursos 
"""
def estudiantesEnComun(dic,curso1,curso2):
	estudCurso1= set()
	estudCurso2 = set()
	for estudiante in dic[curso1]:
		estudCurso1.add((estudiante[0],estudiante[1]))

	for estudiante in dic[curso2]:
		estudCurso2.add((estudiante[0],estudiante[1]))

	ans = list(estudCurso1 & estudCurso2)
	return ans 

#########################################################################################################################################################################################################
#4
"""
(a)
funcion: profesoresParaCurso
entrada: un dicionario de los cursos en relacion con los profesores y un string de el nombre de un curso en especifico
salida: una lista que contiene los nombres (string) de todos los profesores que pueden dictar ese curso en especifico
"""

def profesoresParaCurso(profCursos,curso):
	ans = []
	for profesor in profCursos:
		if curso in profCursos[profesor]:
			ans.append(profesor)
	return ans

"""
(b)
funcion: estudiantesConProfesor
entrada: dos dicionario uno con la informacion de cada curso y otro con la informacion de los proferores en relacion con los cursos; y el nombre de un profersor en especifico
salida: una lista con los nombre de los estudiantes que ven alguna clase con dicho profesor
"""
def estudiantesConProfesor(dicCursos, dicProfCursos, profesor):
	cursosdictados = dicProfCursos[profesor]
	ax = set()
	for curso in cursosdictados:
		for estudiante in dicCursos[curso]:
			ax.add(estudiante[0])
	ans = list(ax)
	return ans

##########################################################################################################################################################################################################
#5
"""
funcion: uva13037
entrada: lista de conjuntos que contienen los codigos de los chocolates
salida: lista de 3 tublas que contienen dos valores; 1)la canrtidad de codigos exclusivos 2) la cantidad de codigos que tiene los demas y no tiene este en especifico
"""
def uva13037(codeChocolat):
	l = codeChocolat[0]
	r = codeChocolat[1]
	s = codeChocolat[2]
	excL = len(l - (r | s))
	excR = len(r - (l | s))
	excS = len (s - (l | r))
	auL = len((r & s) - l)
	auR = len((l & s) - r)
	auS = len((l & r) - s)
	ans = [(str(excL),str(auL)), (str(excR), str(auR)), (str(excS), str(auS))]

	return ans
"""
procedimiento: imprimir
entrada: una lista de tuplas
descripcion: imprime el resultado como se expecifica en el problema
"""
def imprimir(ans):
	for i in ans:
		txt = " ".join(i)
		print(txt)
"""
procedimiento: leerImprimir13037
entrada: 1) numero entrero (cantidad de casos), 2) string que convierte a lista de strings (cantidad de chocolates por cada primo), 
3) 3 string de codigos de chocolates separados por un espacio, que se convierte en 3 listas de strings respectivamente.
descripcion: lee todos datos requeridos, imprime "Case #n:" con n repectivo al numero de caso y llama a las demas funciones
"""
def leerImprimir13037():
	numberCases = int(input())
	for case in range(numberCases):
		chocolat = []
		numberChoco = input().split()
		for cousin in numberChoco:
			ax = set(input().split())
			chocolat.append(ax)

		ans = uva13037(chocolat)
		print("Case #%d:" %(case + 1))
		imprimir(ans)

##########################################################################################################################################################################################################