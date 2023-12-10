#Juan Diego Collazos Mejia # ID: 8977837
###########################################################################################################
#1
from math import*
def funcion(w,x,y,z):
    g=(((x-2)**(z+1))*((4*y)**(4*z)))+ (7*((x)**(y-1)))-((sqrt(x+3))/4)-((z**(4))*(w**(y+x))*(x**3))+6
    return g
##########################################################################################################
#2
# r=Radio # h=Altura

#Cilindro (cm)
def vol_Cilindro(r,h):
    v=(pow(r,2)*pi)*h
    return v

#Cono (cm)
def vol_Cono(r,h):
    v=((1/3)*(pow(r,2)*pi)*h)
    return v 

#Esfera(cm)
def vol_Esfera(r):
    v=(4/3)*pi*pow(r,3)
    return v
##########################################################################################################
#3
def mayor(a,b,c,d,e):
    if a>=b and a>=c and a>=d and a>=e:
        m=a
    elif b>=a and b>=c and b>=d and b>=e:
        m=b
    elif c>=a and c>=b and c>=d and c>=e:
        m=c
    elif d>=a and d>=c and d>=b and d>=e:
        m=d
    elif e>=a and e>=c and e>=d and e>=b:
        m=e
    return m

def menor (a,b,c,d,e):
    if a<=b and a<=c and a<=d and a<=e:
        m=a
    elif b<=a and b<=c and b<=d and b<=e:
        m=b
    elif c<=a and c<=b and c<=d and c<=e:
        m=c
    elif d<=a and d<=c and d<=b and d<=e:
        m=d
    elif e<=a and e<=c and e<=d and e<=b:
        m=e
    return m

def sumaMayorMenor(a,b,c,d,e):
    s=mayor(a,b,c,d,e)+ menor(a,b,c,d,e)
    return s
##########################################################################################################
#4
def determinarCuadrante(x,y):
    if x>0 and y>0:
        cud=1
    elif x>0 and y<0:
        cud=4
    elif x<0 and y>0:
        cud=2
    elif x<0 and y<0:
        cud=3
    return cud
###########################################################################################################
#5
def cuantosEnCuadrante(x1,y1,x2,y2,x3,y3,x4,y4,c):
    n=0
    if (determinarCuadrante(x1,y1)==c):
        n+=1 
    if (determinarCuadrante(x2,y2)==c):
        n+=1
    if (determinarCuadrante(x3,y3)==c):
        n+=1
    if (determinarCuadrante(x4,y4)==c):
        n+=1
    return n
#############################################################################################################
#6
def tienePoker(a,b,c,d,e):
    if a==b and a==c and a==d:
        m=True
    elif a==b and a==c and a==e:
        m=True
    elif a==b and a==d and a==e:
        m=True
    elif a==c and a==d and a==e:
        m=True
    elif b==c and b==d and b==e:
        m=True
    else:
        m=False
    return m
###############################################################################################################
#7
#jugador1= nombre del jugador 1 # a1,a2,a3,a4,a5= puntaje obtenido en los respectivos sets por el jugador 1
#jugador2= nombre del jugador 2 # b1,b2,b3,b4,b5= puntaje obtenido en los respectivos sets por el jugador 2
def st(a,b):
    if (a==6 and b<=4) or (a==7 and (b==6 or b==5)):
        c=1
    elif (b==6 and a<=4) or (b==7 and (a==6 or a==5)):
        c=0
    return c

def quienGana(jugador1,a1,a2,a3,a4,a5,jugador2,b1,b2,b3,b4,b5):
    if ((st(a1,b1)+st(a2,b2)+st(a3,b3)+st(a4,b4)+st(a5,b5))>=3):
        ganador= jugador1
    else:
        ganador= jugador2
    return ganador
###############################################################################################################
#8
#prinN=nombre del principio # prinC=calorias del principio # prinP=peso del principio
#proN=nombre de la proteina # proC=calorias de la proteina # proP=peso de la proteina
#ensaN=nombre de la ensalada # ensaC=calorias de la proteina # ensaP=peso de la ensalada
#sopaN=nombre de la sopa # sopaC=calorias de la sopa # sopaP=peso de la sopa
def puedoAlmorzar(priN,prinC,prinP,proN,proC,proP,ensaN,ensaC,ensaP,sopaN,sopaC,sopaP):
    calT=prinC+proC+ensaC+sopaC
    pesoT=prinP+proP+ensaP+sopaP
    if proN=="Carne desmechada" or calT<500 or (500<=calT<700 and pesoT<325 and ensaP>=100) or ensaP>(pesoT*0.6):
        r=True
    else:
        r=False
    return r
#########################################################################################################
#9
#px,py= coordenadas del peon #rx,ry= coordenadas de la reina
def valorAbs(x):
    if x<0:
        x=x*-1
    return x
def reinaMataPeon(px,py,rx,ry):
    if px==rx or py==ry or valorAbs(px-rx)== valorAbs(py-ry):
        r= True
    else:
        r= False
    return r
#########################################################################################################
#10
#tpv=tipo de vehiculo # npl=numero en que termina la placa # d= dia # h= hora # m= minutos
def puedeSalir(tpv,npl,d,h,m):
    if tpv=="Particular":
        if (6<=h<10 or 16<=h<20) or ((h==10 or h==20) and m==0):
            if(npl== 7 or npl== 8 )and d=="Lunes":
                r= False  
            elif(npl== 9 or npl== 0 )and d=="Martes":
                r= False
            elif(npl== 1 or npl== 2 )and d=="Miercoles":
                r= False
            elif(npl== 3 or npl== 4 )and d=="Jueves":
                r= False
            elif(npl== 5 or npl== 6 )and d=="Viernes":
                r= False
            else:
                r=True
        else:
            r= True
    elif tpv=="Servicio Publico":
        if 5<=h<22 or (h==22 and m==0):
            if (npl== 6 or npl== 7 )and d=="Lunes":
                 r= False
            elif (npl== 7 or npl== 8 )and d=="Martes":
                 r= False
            elif (npl== 0 or npl== 9 )and d=="Miercoles":
                 r= False
            elif (npl== 1 or npl== 2 )and d=="Jueves":
                 r= False
            elif (npl== 3 or npl== 4 )and d=="Viernes":
                 r= False
            elif (npl== 1 or npl== 2 or npl== 3 or npl== 4 or npl== 5 )and d =="Sabado":
                 r= False
            elif (npl== 6 or npl== 7 or npl== 8 or npl== 9 or npl== 0 )and d =="Domingo":
                 r= False
            else:
                r=True
        else:
            r=True     
    else:
        r= False
    return r
#######################################################################################################
