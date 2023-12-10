## Punto 3
def encontrarRobot(tab):
  i = 0
  ans = None
  while i < len(tab) and ans == None:
    j = 0
    while j < len(tab[i]) and ans == None:
      if tab[i][j] == 1:
        ans = (i, j)
      j+=1
    i += 1
  return ans


def moverRobot(tab, vert, hor):
  fini, cini = encontrarRobot(tab)
  #t = encontrarRobot(tab)
  #fini, cini = t[0], t[1]

  if vert < 0:
    mult = -1
  else:
    mult = 1

  k, flag = 0, True
  while k < abs(vert) and flag:
    r = fini + mult
    if r >= 0 and r < len(tab) and tab[r][cini] != -1:
      if tab[r][cini] == 0:
        tab[r][cini] = 1
      tab[fini][cini] = 0
      fini = r
      #print("Tablero movimiento vertical")
      #imprimirTablero(tab)
    else:
      flag = False
    k += 1

  if hor < 0:
    mult = -1
  else:
    mult = 1

  k, flag = 0, True
  while k < abs(hor) and flag:
    c = cini + mult
    if c >= 0 and c < len(tab[0]) and tab[fini][c] != -1:
      if tab[fini][c] == 0:
        tab[fini][c] = 1
      tab[fini][cini] = 0
      cini = c
      #print("Tablero movimiento horizontal")
      #imprimirTablero(tab)
    else:
      flag = False
    k += 1

def imprimirTablero(tab):
  for fila in tab:
    print(fila)