from PIL import Image,ImageDraw

b = 10

image = Image.new('RGB',(b*120,b*120),(255,255,255))
N = int(input())
draw = ImageDraw.Draw(image)
for i in range(N):
	(x,y) = map(int,input().split())
	draw.point([(b*x,b*100-b*y)],(255,0,0))
	s = '(' + str(x) + ',' + str(y) + ')'
	draw.text((b*x-5,b*(100-y)-10),s,fill = 'black')
x = 21.136
y = 27.136
draw.point([(b*x,b*100-b*y)],(0,0,0))
R = 1
draw.arc((b*(x-R),b*(100-y-R),b*(x+R),b*(100-y+R)),0,360,fill = 'blue')

x = 20.5
y = 10.75
draw.point([(b*x,b*100-b*y)],(0,255,0))

def ok(x):
	return x>-1000 and x<1000

for i in range(63):
	(x1,y1) = map(float,input().split())
	(x2,y2) = map(float,input().split())
	(x3,y3) = map(float,input().split())

	if (ok(x1) and ok(x2) and ok(y1) and ok(y2)):
		draw.line([(b*x1,b*100-b*y1),(b*x2,b*100-b*y2)],fill = (255,0,0),width = 1)
	if (ok(x1) and ok(x3) and ok(y1) and ok(y3)):
		draw.line([(b*x1,b*100-b*y1),(b*x3,b*100-b*y3)],fill = (255,0,0),width = 1)
	if (ok(x3) and ok(x2) and ok(y3) and ok(y2)):
		draw.line([(b*x3,b*100-b*y3),(b*x2,b*100-b*y2)],fill = (255,0,0),width = 1)

for i in range(145):
	(x1,y1) = map(float,input().split())
	(x2,y2) = map(float,input().split())
	draw.line([(b*x1,b*100-b*y1),(b*x2,b*100-b*y2)],fill = (0,255,0),width = 1)
image.save('1.png','png')
