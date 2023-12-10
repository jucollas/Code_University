#Juan Diego Collazos Mejia #05/09/2022 
##############################################
from math import*
#1
"""
ventana de obsevacion: 24 horas

componetes:
-residentes
-casas
-porteria
-guardia de seguridad
-camaras de seguridad

datos:
 por componetes:

	 constantes:
	 	-direccion de casa o nomenclatura (casas)
	 	-color de las casas(casas)
	 	-esta habitadad la casa (casa) False/True
	 	-nombre de los recidentes (residentes)
	 	-edad de los residentes (recidentes)
	 	-color de la porteria (porteria)
	 Variables
	 	-nombre del guardia de turno (guardia) (cambian cada turno)
	 	-porteria abierta (porteria) Flase/ True
	 	-residente esta detro del conjunto? (residente) False/True
	 	-hay algien dentro de la casa en este momento (casas) False/True
	 	-guardia de seguridad se quedo dormido? (guardia) False/ True
	 	-camara de seguridad activa (camara de seguridad) False /True
	 	-
"""
 ###########################################################################################################################################
 #2
def determinarPuntoMasLejano(x1,y1,x2,y2,x3,y3,x4,y4):
	d1= sqrt((x1**2)+(y1**2))
	d2= sqrt((x2**2)+(y2**2))
	d3= sqrt((x3**2)+(y3**2))
	d4= sqrt((x4**2)+(y4**2))
	if d1>=d2 and d1>=d3 and d1>=d4:
		ans=1 
	elif d2>=d1 and d2>=d3 and d2>=d4:
		ans=2
	elif d3>=d1 and d3>=d2 and d3>=d4:
		ans=3
	elif d4>=d1 and d4>=d2 and d4>=d3:
		ans=4
	return ans
###################################################################################################################################################
#3
def maxh(a,b,c,d,e):
	if a>=b and a>=c and a>=d and a>=e:
		ans=a
	elif b>=a and b>=c and b>=d and b>=e:
		ans=b
	elif c>=a and c>=b and c>=d and c>=e:
		ans=c
	elif d>=a and d>=b and d>=c and d>=e:
		ans=d
	elif e>=a and e>=b and e>=c and e>=d:
		ans=e
	return ans

def minh(a,b,c,d,e):
	if a<=b and a<=c and a<=d and a<=e:
		ans=a
	elif b<=a and b<=c and b<=d and b<=e:
		ans=b
	elif c<=a and c<=b and c<=d and c<=e:
		ans=c
	elif d<=a and d<=b and d<=c and d<=e:
		ans=d
	elif e<=a and e<=b and e<=c and e<=d:
		ans=e
	return ans

def sumarMayorMenor(a,b,c,d,e):
	ans= maxh(a,b,c,d,e)+minh(a,b,c,d,e)
	return ans

####################################################################################################################################################
#4 
def f(x,y,z,w):
	if w<1:
		ans=((x+(2*z))**y)+(x**2)
	elif w==1:
		ans=(((3*y)/(2*x))**(-2))+(y**(x+3))-4
	elif w>1:
		ans=(((x+y)**3)/(sqrt(5*z)))+(2*y*(z**(x+1)))
	return ans

###############################################################################################################################################
#5
def tieneEscaleritaPaArriba(a,b,c):
	if (a==b+1 and a==c-1) or (a==c+1 and a==b-1) or (b==a+1 and b==c-1) or (b==c+1 and b==a-1) or (c==a+1 and c==b-1) or (c==b+1 and c==a-1):
		ans= True
	else:
		ans= False
	return ans
###############################################################################################################################################
#6
#nEd= nivel educativo # vig=¿esta vinculado a un grupo de investigacion? # npi= numero de proyectos de investigacion en los que participa
#nAD= numero de años trascurridos desde que finalizo el doctorado #nArtI=Número de artículos en revistas internacionales # nArtN= número de artículos en revistas nacionales # nArtC=número de artículos en conferencias
#nTP= Número de trabajos de grado de pregrado dirigidos # nTssM= número de tesis de maestría dirigidas # nTssD = número de tesis de doctorado dirigidas
def determinarCategoriaDeProfesor(nEd,vig,npi,nAD,nArtI,nArtN,nArtC,nTP,nTssM,nTssD):
	tolTesisOTrabajos=nTP+nTssM+nTssD
	tolPubl= nArtI+nArtN+nArtC
	if vig==False:
		ans="Sin Categoria"
	elif nEd=="doctorado":
		if (tolTesisOTrabajos>=5 and nArtI>3 and tolPubl>6) or (npi>=4 and tolPubl>8):
			ans="investigador senior" 
		elif npi>=2 and tolTesisOTrabajos>=3 and tolPubl>6:
			ans="investigador asociando"
		elif npi>=1 and tolPubl>4:
			ans="investigador junior"
		elif nAD<=3:
			ans="investigador con doctorado"
	else:
		ans="investigador sin doctorado"

	return ans
###################################################################################################################################################


