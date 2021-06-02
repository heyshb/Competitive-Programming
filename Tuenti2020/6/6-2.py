from socket import *
import time
import socks

def response():
    return str(s.recv(100), encoding = 'utf-8')

block = [[False for j in range(250)] for i in range(250)]
vis = [[False for j in range(250)] for i in range(250)]
dx = [2, 2, -2, -2, 1, 1, -1, -1]
dy = [1, -1, 1, -1, 2, -2, 2, -2]
sx = ['2D', '2D', '2U', '2U', '1D', '1D', '1U', '1U']
sy = ['1R', '1L', '1R', '1L', '2R', '2L', '2R', '2L']
rv = [3, 2, 1, 0, 7, 6, 5, 4]
bias = 120

# s.send(bytes('2D1L', encoding = 'utf-8'))
def mv(d):
    #print(sx[d] + sy[d])
    s.send(bytes(sx[d] + sy[d], encoding = 'utf-8'))

def dfs(x, y):
    print(x, y)
    vis[x][y] = True
    res = response()
    for i in range(5):
        for j in range(5):
            if (res[i * 6 + j] == '#'):
                block[x - 2 + i][y - 2 + j] = True
    for d in range(8):
        nx = x + dx[d]
        ny = y + dy[d]
        if (nx == bias and ny == bias + 1):
            mv(d)
            print(response())
            return True
        if ((not vis[nx][ny]) and (not block[nx][ny])):
            mv(d)
            if (dfs(nx, ny)):
                return True
            mv(rv[d])
            response()
    #vis[x][y] = False
    return False


#s = socket()
s = socks.socksocket() 
s.set_proxy(socks.SOCKS5, "localhost", 1080)
s.connect(('52.49.91.111', 2003))
dfs(bias, bias)