def esPrimo(n):
  if n < 2: ans = False
  else:
    i, ans = 2, True
    while i * i <= n and ans:
      if n % i == 0: ans = False
      i += 1
  return ans
"""
def esPrimo(num, listprim):
	ans = True
	i = 0
	while i < len(listprim) and ans:
		if num % listprim[i] == 0:
			ans = False
		i += 1
	return ans
"""
def sumarDigitos(num):
	ans = 0
	ax1 = 0
	while num != 0:
		ax1 = num % 10
		ans += ax1
		num //= 10

	return ans

def mostrarPrimos(num):
	listprim, sumDigitosPri = [2, 3], ["2", "3"]
	char = ",\n"
	i = 5
	print("Números primos entre 1 y %d:" %(num))
	print("--> %d" %(listprim[0]), end = "")
	print("%s--> %d" %(char, listprim[1]), end = "")

	while i <= num:  
		if esPrimo(i):
			listprim.append(i)
			print("%s--> %d" %(char, i), end = "")
			if sumarDigitos(i) in listprim:
				sumDigitosPri.append(str(i))
		i += 2
	print("\n")
	print("Números entre 1 y %d con suma de dígitos con valor primo:" %(num))
	print(", ".join(sumDigitosPri))

mostrarPrimos(100000)