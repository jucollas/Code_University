#sectorciudad
def sector(xe,ye,xc,yc):
	if(xe>xc and ye>yc):
		ans="NOr"
	elif(xe<xc and ye>yc):
		ans="NOc"
	elif(xe<xc and ye<yc):
		ans="SOc"
	elif(xe>xc and ye>yc):
		ans="SOr"
	else(xe==xc or ye==yc):
		ans= "Esp"
	return ans

def partido(pA,pB):
	if pA>pB:
		p=3
	elif pA<pB:
		p=1
	else:
		p=0
	return p

def tripartidos(pA1,pB1,pA2,pB2,pA3,pB3):
	p=(partido(pA1,pB1)+partido(pA2,pB2)+partido(pA3,pB3))
	return p

def quesignosoy(mes,dia):
	if mes=="marzo" and 







