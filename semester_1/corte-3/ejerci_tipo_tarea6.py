def contarOcurrencias(s):
	ans = {}
	for i in s:
		if not i in ans:
			ans[i] = 1
		else:
			ans[i] += 1

	return ans		
#print(contarOcurrencias("asdfghjasdfghjjk"))

def  obetenercosto(cad, d):
	ans = 0
	for i in cad:
		if i in d:
			ans += d[i]

	return ans

def verificarCercania(x, y, d):
	ans = False
	p = sqrt((x[0]-y[0])**2 + (x[1]- y[1]) ** 2)
	if p >= d:
		ans = True
	return ans

#print(verificarCercania((0,0),(0,1),2))

"""

def cercanos(l, d):
	ans = {}
	for i in range(len(l)):
		for j in range(i + 1, len(l)):
			if verificarCercania(l[i], l[j], d):
				ans[l[i]].append(l[j])
				ans[l[j]].append(l[i])
	return ans

cercanos([(1 , 1), (0, 1)], 1)
"""

#  print(obetenercosto("aaaaaassssssddddddfffff", {"a" : 1 , "s" : 1 , "d" : 1}))
def multlicarDiagonales(m, a):
	l = len(m)
	for i in range(l):
		m[i][i] *= a
		m[i][l - i - 1] *= a

	if l % 2 != 0:
		m[l // 2][l // 2] //= a

	return m

#print(multlicarDiagonales([[1, 1, 1], [1, 1, 1], [1, 1, 1]] , 2))

def rotar90(m):
	m2 = list(m)
	n = len(m)
	for i in range(n):
		for j in range(n):
			m[j][n-i-1] = m2[i][j]
	print(m)
rotar90([[1, 3, 1], [4, 2, 3], [9, 5, 2]])