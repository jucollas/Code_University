#Juan Diego Collazos Mejia # ID:8977837 #01/09/2022
######################################################
from math import*
######################################################
#2
def f(x,y,w,z):
	if x>0:
		ans= ((3+z)**(x+y))*w
	elif x<0:
		ans= (x**(3*z))*(y**(w+3))
	else:
		ans= ((x**3)/(sqrt(z+5)))+(3*x*y*w)+((y+2)**(w+1))
	return ans

########################################################
#3
def sector(xe,ye,xc,yc):
	if(xe>xc and ye>yc):
		ans="NOr"
	elif(xe<xc and ye>yc):
		ans="NOc"
	elif(xe<xc and ye<yc):
		ans="SOc"
	elif(xe>xc and ye>yc):
		ans="SOr"
	elif(xe==xc or ye==yc):
		ans= "Esp"
	return ans
########################################################
#4
def calcularCantidadMinutos(h1,m1,h2,m2):
	minT1=(h1*60)+m1
	minT2=(h2*60)+m2
	if minT1<=minT2:
		ans=minT2-minT1
	else:
		ans=(1440-minT1)+minT2	
	return ans
########################################################
#5
def determinarComprarComputador(memMar,memCap,memPre,disMar,disCap,disPre,proMar,proCap,proPre,pantMar,pantPul,pantEst,pantPre):
	Pretotal=memPre+disPre+proPre+pantPre
	ans=False
	if (memMar==proMar==disMar==pantMar=='Pintel') or ((memCap>4 and disCap>500 and proCap>3) and (pantEst=="Usada") and (Pretotal<=1500000 and proMar=='Intel')) or (memCap>=8 and disCap>1000 and (proCap>4 and (pantEst=='Nueva')) and Pretotal<=3000000):
		ans=True
	return ans

#print(determinarComprarComputador("Pinte",5,5,"Pintel",5,5,"Pintel",5,5,"Pintel",5,5,5))

########################################################
#6
def canal(ni,nf,m1):
	ans =0
	if nf < m1 <ni:
		ans=1
	return ans

def canal2(ni,nf,m):
	ans=0
	if (0<=m<ni) or (nf<m<=99):
		ans=1
	return ans

def contarCanales(ni,nf,m1,m2,m3,m4,m5):
	ans = 0
	if ni>nf:
		ans =canal(ni,nf,m1)+canal(ni,nf,m2)+canal(ni,nf,m3)+canal(ni,nf,m4)+canal(ni,nf,m5)
	elif ni<nf:
		ans = canal2(ni,nf,m1)+canal2(ni,nf,m2)+canal2(ni,nf,m3)+canal2(ni,nf,m4)+canal2(ni,nf,m5)
	return ans

##print(contarCanales(1,15,16,17,18,19,20))







