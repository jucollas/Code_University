def esPrimo(n):
  if n < 2: ans = False              # 1
  else:
    i, ans = 2, True                 # 2
    while i * i <= n and ans:        # raiz2(n)
      if n % i == 0: ans = False     # raiz2(n) - 1
      i += 1                         # raiz2(n) - 1
  return ans