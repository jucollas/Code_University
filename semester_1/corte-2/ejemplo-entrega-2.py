#Juan Diego Collazos Mejia # ID: 8977837 # October 18st 2022
####################################################################################################################################################################################
def leerImprimir489():
  case = int(input())
  while case != -1:
    cadRes = input()
    advs = input()

    print("Datos leídos")
    print("Número caso: %d" % (case))
    print("Cadena a adivinar: %s" % (cadRes))
    print("Intentos: %s" % (advs))
    
    """
    ans = resolver(cadRes, advs)
    # ... imprimir la respuesta
    """
    
    case = int(input())

leerImprimir489()


def leerImprimir647():
  line = input().split()
  dados = []
  for i in range(len(line) - 1):
    dados.append(int(line[i]))
  jugadores = int(input())
  while jugadores > 0:
    escTob = []
    line = input().split()
    while line[0] != "0" and line[1] != "0":
      escTob.append((int(line[0]), int(line[1])))
      line = input().split()
    ganaTurno, pierdeTurno = [], []
    v = int(input())
    while v != 0:
      if v > 0: ganaTurno.append(v)
      else: pierdeTurno.append(v)

    print("Datos leídos")
    impDados = []
    for dado in dados:
      impDados.append(str(dado))
    print("Cantidad Jugadores: %d" % (jugadores))
    print("Dados: %s" % " ".join(impDados))
    print("Escaleras y toboganes" + str(escTob))
    print("Pierde Turno: " + str(pierdeTurno))
    print("Gana Turno: " + str(ganaTurno))
    
    """
    ans = resolver(jugadores, escTob, pierdeTurno, ganaTurno)
    # ... imprimir la respuesta
    """
    
    jugadores = int(input())

leerImprimir647()