def sucesion(n):
	print("* ", end = "")
	for x in range(1, n + 1):
		a = ( -1 ** (x-1)) * (2 ** x)
		if x < n:
			print("%d # " % (a), end = "")
		else:
			print("%d" % (a), end = "")
	print(" *", end = "")


def sucesion2(n):
	for i in range(1, n + 1):
		suma = i
		for m in range (1, n + 1):
		 	if 1 < n:
		 		print("%d " % (suma), end = "")
		 	else:
		 		print(suma)

		 	suma+=n