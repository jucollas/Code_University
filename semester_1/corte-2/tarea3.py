 #Juan Diego Collazos Mejia # ID: 8977837 # September 8th 2022
###########################################################################################################
#1
def imprimirnumeros():
	x = 1
	while x <= 1000:
	    if ((900 % x) == 0 or (x % 13) == 0):
	    	print(x)
	    x += 1

def imprimirnumeros2():
	for x in range(1 , 1001):
		if ((900 % x) == 0 or (x % 13) == 0):
			print(x)

################################################################################################################
#2
# a=Cantidad de datos leidos # b=Cantidad de numeros impares
# c=la suma de los multiplos del 5 que fueron leidos 
# d= cantidad de numeros mayoes que 10 y menores que 20 que fueron leidos
def leerNumeros():
    a, b, c, d = 0, 0, 0, 0
    y = True
    while y:
    	x = input()
    	if x == "Fin":
            y = False
    	else:
            x = int(x)
            a += 1
            if x % 2 != 0:
                b += 1
            if x % 5 == 0:
                c += x
            if 10 < x < 20:
                d += 1
    t = (a, b, c, d)
    print (t)

###############################################################################################################
#3
def imprimirPotencias(n, m):
    p = 1
    while p <= m:
        print(p)
        p *= n

def leerImprimirPotencias():
  v = int(input())
  i = 0
  while i < v:
    n = int(input())
    m = int(input())
    imprimirPotencias(n, m)
    i += 1

##################################################################################################################
#4
def sumade1aN(n):
    res = 0
    for x in range(n + 1):
        res += x
    return res

def sueldodeempleado(sal, e, n):
    ans = sal + (e * 10000) + ((sumade1aN(n)) * 5000)
    return ans

def leerImprimirsueldodeempleado():
  v = int(input())
  i = 0
  while i < v:
    sal = int(input())
    e = int(input())
    n = int(input())
    print(sueldodeempleado(sal, e, n))
    i += 1

#######################################################################################################
#5
def hajje(x):
    if x == "Hajj":
        z = "Hajj-e-Akbar"
    elif x == "Umrah":
        z = "Hajj-e-Asghar"
    return z

def hajjeleerimprimir():
    f = 1
    y = True
    while y:
        x = input()
        if x == "*":
            y = False
        else:
            z = hajje(x)
            print("Case %d: %s" % (f, z))
            f += 1

########################################################################################################