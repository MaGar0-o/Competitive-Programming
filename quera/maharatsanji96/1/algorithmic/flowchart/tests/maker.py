from PIL import Image
from sys import stdout, argv
address = argv[1]
im = Image.open(address) #Can be many different formats.
im = im.convert('RGB')
pix = im.load()
a = (im.size) #Get the width and hight of the image for iterating over
print(im.size[1], im.size[0])
for i in range(im.size[1]):
	for j in range(im.size[0]):
		if pix[j, i][0] + pix[j, i][1] + pix[j, i][2] > 300:
			print ('.', end = "")
		else:
			print ('#', end = "")
#		print (pix[j, i], end = " ")
#		stdout.write(i+' ')
	print ()
	
