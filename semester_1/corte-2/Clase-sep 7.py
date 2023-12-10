
"""
n = 10
i = 0
j = 1

while i < n:
  print("Valor i = " + str(i))
  print("otra linea")
  print("cantidad de veces " + str(j))
  j += 1
  i += 1

print("después del while")


def factorial(n):
  ans = 1
  i = 1
  while i <= n:
    ans *= i
    i += 1
  return ans




def leerImprimir():
  # leer cuántas veces se quiere hacer la ejecución
  veces = int(input())
  i = 0
  while i < veces:
    n = int(input())
    res = factorial(n)
    print(res)
    i += 1

leerImprimir()
exit()


def leerImprimirEstudiantes():
  ests = int(input())
  i = 0
  while i < ests:
    np1 = float(input())
    np2 = float(input())
    np3 = float(input())
    npr = float(input())
    nt = float(input())
    nota = calcularNotaFinal(np1, np2, np3, npr, nt)
    print("La nota final del estudiante es " + str(nota))
    i += 1
"""
def contarhasta():
  n=1
  while n<100000000:
    print(n)
    n*=2

def tabladelmultiplicar(c,e):
  i=1
  while not(i==(e+1)):
    res=c*i
    print("%d x %d = %d" %(i,c,res))
    i+=1

tabladelmultiplicar(73,55)

"""
  pass
#ciclo for
def factorial3(n):
  x=1
 for x in range(10):


   pass
"""
for x in range(10):
  pass

