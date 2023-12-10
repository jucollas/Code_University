#problema de clase
def nombreDelDia(dia):
    if(dia==1):
        nombre="Lunes"
    elif(dia==2):
        nombre="martes"
    elif(dia==3):
        nombre="miercioles"
    elif(dia==4):
        nombre="jueves"
    elif(dia==5):
        nombre="viernes"
    elif(dia==6):
        nombre="sabado"
    elif(dia==7):
        nombre="domingo"
    else:
        nombre="el numero no puede ser asociando a ningun dia de la semana"
    return nombre
    


print(nombreDelDia(1))

###############################
def fechavalida(dia,mes,año):
    ans = False
    if (año>=0)and(1<=mes<=12)and (1<=dia<=31):
        if(mes==1 or mes==3 or mes==5 or mes==7 or mes==8 or mes ==10 or mes==12):
            ans= True
        elif(mes==2):
            if año % 4 ==0 and dia<=29:
                if (año % 100 ==0)and(año %400 ==0):
                    ans = True
            
            else:
                ans= False
        else:
            if (dia<=30):
                ans= True
            else:
                ans= False
    return ans
##################################
        
    
    
    

        
    

print(fechavalida(29,2,2600))
