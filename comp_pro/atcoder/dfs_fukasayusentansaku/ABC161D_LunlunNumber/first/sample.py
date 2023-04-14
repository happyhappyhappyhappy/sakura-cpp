import sys
sys.setrecursionlimit(10 ** 9) #再帰回数の限界を変更

K = int(input())
MAX = 3234566667 # 100000番目の値
Lun = []
def dfs(n):
    global Lun
    if n > MAX:
        # 100000番目まで調べればよいためreturn
        return
    Lun.append(n)
    ichi = n%10


    dfs(n*10+ichi)
    if ichi>0:
        dfs(n*10+ichi-1)
    if ichi<9:
        dfs(n*10+ichi+1)


for i in range(1,10):
    dfs(i)
Lun.sort()
print(Lun[K-1])
