#Juan Diego Collazos Mejia # ID: 8977837 # October 27st 2022
#########################################################################################################################################################################################
from math import*
#########################################################################################################################################################################################
#1
def copiaDeMatriz(m):
	ans = []
	for i in range(len(m)):
		ans.append([])
		for e in m[i]:
			ans[-1].append(e)
	return ans

def f(g):
	g2 = copiaDeMatriz(g)
	l = len(g2)
	l2 = len(g2[0])
	vcT = 0
	for i in range(l):
		for e in range(l2):
			var, vde, viz, vba = 0, 0, 0, 0
			if i > 0:
				var = g2[i - 1][e]
			if i < l - 1:
				vba = g2[i + 1][e]
			if e > 0:
				viz = g2[i][e - 1]
			if e < l2 - 1:
				vde = g2[i][e + 1]

			vcT = var + vde + viz + vba

			vf = vcT % 2

			g[i][e] = vf
	return g2

def elementosIgual(m, x):
	ans = True
	i, e = 0, 0
	l, l2 = len(m), len(m[0])
	while i < l and ans:
		while e < l2 and ans:
			if m[i][e] != x:
				ans = False
			e += 1
		i += 1
	return ans

"""
def uva11581(g):
	est = [copiaDeMatriz(g)]
	ans = -1 
	flag = True
	while (not elementosIgual(g, 0)) and flag:
		copyM = f(g)
		if g in est:
			flag = False
			ans = -1		
		else:
			est.append(copyM)
			ans += 1

	return ans
"""

def uva11581(g):
	est = [copiaDeMatriz(g)]
	ans, ac = -1, -1 
	copyM = f(g)

	while (not g in est):
		copyM = f(g)		
		est.append(copyM)
		ac += 1

	if elementosIgual(g, 0):
		ans = ac

	return ans

def leerImprimir11581():
	n = int(input())
	input()
	for i in range(n):
		g = []
		for e in range(3):
			ax = input()
			ax2 = []
			for l in ax:
				ax2.append(int(l))
			g.append(ax2)

		ans = uva11581(g)
		print(ans)

		if i < n - 1:
			input()

leerImprimir11581()

####################################################################################################################################################################
#2
def listaIntAString(l):
	ans = []
	i = 0
	while i < len(l):
		x = str(l[i])
		ans.append(x)
		i += 1
	return ans

def printMatriz(matriz):
	for row in matriz:
		rowListString = listaIntAString(row)
		rowString = "".join(rowListString)
		print(rowString)

def rowt(matriz, rowA, rowB):
	rowA -= 1
	rowB -= 1
	copyRowA = list(matriz[rowA])
	matriz[rowA] = matriz[rowB]
	matriz[rowB] = copyRowA

def col(matriz, columnA, columnB):
	columnA -= 1
	columnB -= 1
	copyColmnA = []
	for row in matriz:
		numberA = row[columnA]
		row[columnA] = row[columnB]
		row[columnB] = numberA

def inc(matriz):
	for row in matriz:
		for column in range(len(row)):
			row[column] += 1
			if row[column] == 10:
				row[column] = 0

def dec(matriz):
	for row in matriz:
		for column in range(len(row)):
			row[column] -= 1
			if row[column] == -1:
				row[column] = 9

def transpose(matriz):
	matrizAx = copiaDeMatriz(matriz)
	sizeMatriz = len(matriz)
	for row in range(sizeMatriz):
		for column in range(sizeMatriz):
			matriz[column][row] = matrizAx[row][column]

def leerImprimir11360():
	caseNumbers = int(input())
	
	for case in range(1 , caseNumbers + 1):
		sizeMatriz = int(input())
		matriz = []

		for i in range(sizeMatriz):
			row = input()
			rowList = []

			for number in row:
				rowList.append(int(number))

			matriz.append(rowList)

		operationNumbers = int(input())

		for i in range(operationNumbers):
			operationTxt = input()
			operationList = operationTxt.split(" ")
			operation = operationList[0]

			if operation == "row":
				row1 = int(operationList[1])
				row2 = int(operationList[2])
				rowt(matriz, row1, row2)

			elif operation ==  "col":
				column1 = int(operationList[1])
				column2 = int(operationList[2])
				col(matriz, column1, column2)

			elif operation == "inc":
				inc(matriz)

			elif operation == "dec":
				dec(matriz)

			elif operation == "transpose":
				transpose(matriz)

		print("Case #%d" %(case))
		printMatriz(matriz)
		print()

############################################################################################################################################################
#3
def bombearCadena(cad, d):
	ans = ""
	for l in cad:
		if l in d:
			for i in range(d[l]):
				ans += l
	return ans

###################################################################################################################################################################
#4
def traducir(d, cad):
	anx = []
	ax1 = cad.split(" ")
	i = 0
	l = len(ax1)
	flag = True
	while i < l and flag:
		if ax1[i] in d:
			anx.append(d[ax1[i]])
		else:
			ans = "impossible"
			flag = False
		i += 1
	if flag:
		ans = " ".join(anx)

	return ans

#######################################################################################################################################################################
#5
def obtenerInversa(d):
	ans = {}
	for key in d:
		for i in d[key]:

			if not i in ans:
				ans[i] = [key]
			else:
				ans[i].append(key)

	return ans

#######################################################################################################################################################################
#6
def crearMatrizDispersa(m):
	ans = {}
	ax = []
	l = len(m)
	l2 = len(m[0])
	for i in range(l):
		for e in range(l2):
			if m[i][e] != 0:
				ax.append((e,m[i][e]))
		if len(ax) > 0:
			ans[i] = ax
		ax = []
	return ans

def obtenerValor(dis, i, j):
	ans = 0
	if i in dis:
		for t in dis[i]:
			if t[0] == j:
				ans = t[1]
	return ans

##############################################################################################################################################################3
#7
def organizarPalabras(cad):
	ax = cad.split(" ")
	ans = {}
	for i in ax:
		if not i[0] in ans:
			ans[i[0]] = [i]
		else:
			ans[i[0]].append(i)

	return ans

#####################################################################################################################################################################