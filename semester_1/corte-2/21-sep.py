def estaElementoPOsicion2(l):
	i=0
	ans=False

	while i < len(l) and not(ans):
		if l[i] == i:
			ans = True
		i += 1

	return ans
#print(estaElementoPOsicion2([1,2,6,4,4,7,8,8,6,3,5]))

def multiplosN(n, m):
	ac=0
	t=[]

	for x in range(1,m+1):
		ac+=n*x
		t.append(ac)
		
	return t

#print(multiplosN(4,100))

def posiconesOcurrencias(l, v):
  i=0
  ans=[]
  while i < len(l):
    if l[i] == v:
      ans.append(i)
    i+=1
  return ans

#print(posiconesOcurrencias([1,3,4,15,4,3,7,8,3,4,5,6,3,5,3,9,7,5,9,3,96,5,3,3],15))