import math	
import json
from PIL import Image, ImageDraw

data = open('data','r')

try:
	image = Image.open('img.png')
except FileNotFoundError:
	image = Image.new('RGB',(100,100))

draw = ImageDraw.Draw(image)

curr = 0

for line in data:
	try:	
		val = len(json.loads(line)[1])
	except TypeError:
		val = -1
	x = curr%100
	y = math.floor(curr/100)
	
	if val==-1:
		color='#000000'
	elif val==1:
		color='#ff0000'
	elif val==2:
		color='#ff8000'
	elif val==3:
		color='#ffff00'
	elif val==4:
		color='#80ff00'
	elif val==5:
		color='#00ff00'
	elif val==6:
		color='#00ff80'
	elif val==7:
		color='#00ffff'
	
	draw.point((x,y),color)
	curr+=1

image.save('img.png')
