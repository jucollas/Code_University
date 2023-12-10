def devuelta(x):
	diezmil = 50
	cincomil = 50
	dosmil = 50
	mil = 50
	quinientos = 50
	doscientos = 50
	cien = 50
	
	if x >= 10000:
		r = (x // 10000):
			pass
		x -= r * 10000
		diezmil -= r

	if  x >= 5000:
		r = (x // 5000)
		x -= r  * 5000
		cincomil -= r

	if  x >= 2000:
		r = (x // 2000)
		x -= r * 2000
		dosmil -= r

	if  x >= 1000:
		r = (x // 1000) 
		x -= r * 1000
		mil -= r

	if  x >= 500:
		r = (x // 500) 
		x -= r * 500
		quinientos -= r

	if  x >= 200:
		r = (x // 200)
		x -= r * 200
		doscientos -= r

	if  x >= 100:
		r = (x // 100) 
		x -= r * 100
		cien -= r

	if x == 0:
		ans=[cien,doscientos,quinientos,mil,dosmil,cincomil,diezmil]
		print(ans)
	else:
		print("No tengo cambio asi que paila")

devuelta(102800)


