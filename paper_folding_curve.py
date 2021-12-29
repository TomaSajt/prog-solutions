def rr(s):return"".join("10"[int(x)] for x in path[::-1])
n=int(input())
s,e=map(int,input().split())
path=""
for i in range(n):
    path+="1"+rr(path)
print(path[s:e+1])
