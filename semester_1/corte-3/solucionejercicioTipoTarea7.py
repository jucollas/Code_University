def operationA(dic, s1, s2)
	if s1 in d and s2 in dic[s1]:
		dic[s1].append(s2)
	elif s1 not in dic:
		dic[s2].append(s1)

#def operationD(dic, s1, s2)
	
def operationR(d, s1, s2):
	if s1 in d and s2 in d[s1]:
		print("%s is synonym of %s" %(s1, s2))
	if s2 in d and s1 in d[s2]:
		print("%s is synonym of %s" %(s2, s2))
	if (not s1 in d and s2 in d[s1]) and (not s2 in d and s1 in d[s2]):
		print("not found")

def main():
	n = input()
	line = input().split()
	d = {}
	for palabra in line:
		d[palabra] = []
	numberOperation = input()
	for i in range(numberOperation):
		operation = input().split()
		if line[0] == "A":
			operationA(d, line[1], line[2])
		if line[0] == "D":
			operationD(d, line[1], line[2])
		if line[0] == "S":
			operationS(d, line[1], line[2],line[3])
		if line[0] == "R":
			operationR(d, line[1], line[2])
		if line[0] == "P":
			operationP(d, line[1])
		if line[0] == "E":
			operationE(d, line[1])

#############################################################################
def jugadoreequipos(jugEq):
	ans = {}
	for tupla in jugEq:
		ans[tupla[0]] = tupla[1]
	return ans 

def acumularGoles(jugEq, jugGol):
	ans = {}
	dicJugadorEq = jugadoreequipos(jugEq)
	for t in jugGol:
		if dicJugadorEq[jug] not in ans:
			ans[dicJugadorEq[t[0]]] = 0
		ans[dicJugadorEq[t[0]]] = t[2]