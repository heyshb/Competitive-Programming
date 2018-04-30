from PIL import Image
import random
import math

img = Image.open('large.png')
img.convert('L').save('large_2.png')