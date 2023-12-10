### Punto 4

def esPrimo(n):
  if n < 2: ans = False
  else:
    i, ans = 2, True
    while i * i <= n and ans:
      if n % i == 0: ans = False
      i += 1
  return ans

def sumarDigitos(n):
  suma = 0
  while n > 0:
    suma += n % 10
    n //= 10
  return suma

def mostrarPrimos(N):
  print("Números primos entre 1 y %d" % N)
  primos, sumPrimo = [], []
  for i in range(2, N):
    if esPrimo(i):
      primos.append(i)
      if esPrimo(sumarDigitos(i)):
        sumPrimo.append(str(i))
  for i in range(len(primos)):
    if i < len(primos) - 1:
      print("--> %d," % primos[i])
    else:
      print("--> %d" % primos[i])
  print()
  print("Números entre 1 y %d con suma de dígitos con valor primo:" % N)
  print(", ".join(sumPrimo))

# Descomentar la siguiente línea con el valor que se desea hacer la ejecución.
