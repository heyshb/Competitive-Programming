import csv
from PIL import Image
import numpy as np

def paint(x, y, theta):
    theta = np.pi - theta
    L = 50
    step = 0.5
    C = np.cos(theta)
    S = np.sin(theta)
    tx = x
    ty = y
    for i in range(L):
        tx += C * step
        ty += S * step
        ix = int(tx)
        iy = int(ty)
        if (ix < x - 15 or ix > x + 15 or iy < y - 15 or iy > y + 15):
            break
        ret[ix][iy] = 255


with open('large.csv') as f:
    f_csv = csv.reader(f)
    val = []
    for row in f_csv:
        tmp = []
        for ele in row:
            tmp.append(int(ele))
        val.append(tmp)
    val = np.array(val)
    print(val.shape)
    print(val[0][0])
    N, M = val.shape
    SZ = 31
    ret = np.zeros((N * SZ, M * SZ))
    pi = np.pi
    for i in range(N):
        for j in range(M):
            x = i * SZ + SZ // 2
            y = j * SZ + SZ // 2
            h = (val[i][j] % 43200) / 3600
            m = (val[i][j] % 3600) / 60
            if (val[i][j] == 69662):
                print(h, m)
            thetah = 2 * pi * h / 12 
            thetam = 2 * pi * m / 60 
            if (i == 0 and j == 0):
                print(val[i][j], h,m,thetah,thetam)
            paint(x, y, thetah)
            paint(x, y, thetam)
    print(ret.shape)
    new_im = Image.fromarray(np.matrix(ret))
    print(new_im.mode)
    new_im.show()
    new_im.convert('1').save('fuck.bmp')