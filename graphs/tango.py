#https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/tangos-smart-visit/
import sys
sys.setrecursionlimit(10**6)

def dfs(u,List,color,V,cc):
    color[u] = cc
    V[u] = True
    for v in List[u]:
        if V[v] == False:
            dfs(v,List,color,V,cc)


n,m,k = map(int,input().split())
List = []
for i in range(n):
    List.append([])
for i in range(m):
    a,b = map(int,input().split())
    List[a-1].append(b-1)
    List[b-1].append(a-1)
color = [0]*(n)
cc = 0;
#print(List)
V = [False]*n
for i in range(n):
    if(V[i] == False):
        dfs(i,List,color,V,cc)
        cc+=1
#print(cc)

if k < cc-1:
    print(-1)
else:
    V=[False]*n
    L=[]
    for i in range(cc):
        L.append([])
    for i in range(n):
        L[color[i]].append(i)
    extra=k-cc
    prev=color[0]
    vertex=[i for i in range(n)]
    ans=[]
    while len(vertex)!=0 and extra>0:
        v=vertex.pop(0)
        V[v] = True
        if prev!=color[v]:
            extra-=1
        ans.append(v)
        prev=color[v]
        L[color[v]].remove(v)
        if not L[color[v]]:
            extra+=1
    #print(vertex)
    #print(V)
    arr=[]
    for i in L:
        if len(i)!=0:
            arr.append(i[0])
    arr.sort()
    for a in arr:
        for v in L[color[a]]:
            ans.append(v)
    
    ans=[i+1 for i in ans]
    for i in ans:
        print(i , end=" ")
    
    

