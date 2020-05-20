#https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/successful-marathon-0691ec04/
import heapq as h
def dijkstra(List,d,u,n):
    q=[]
    h.heappush(q,(0,u))
    d[u]=0
    V=[False]*n
    while len(q)!=0:
        #l=q[0]
        l=h.heappop(q)
        if V[l[1]]==False:
            V[l[1]]=True
            for v in List[l[1]]:
                if V[v[1]] == False:
                    if d[l[1]]+v[0]<d[v[1]]:
                        d[v[1]]=d[l[1]]+v[0]
                        h.heappush(q,(d[v[1]],v[1]))
            
n,m,k,x = map(int,input().split())
List = []
chocity=list(map(int,input().split()))
chocity=[i-1 for i in chocity]
for i in range(n):
    List.append([])
for i in range(m):
    a,b,c = map(int,input().split())
    List[a-1].append((c,b-1))
    List[b-1].append((c,a-1))

s,d = map(int,input().split())
sd=[1000000000]*n
dd=[1000000000]*n
dijkstra(List,sd,s-1,n)#shortest distances from source vertex
dijkstra(List,dd,d-1,n)#shortest distances from destination

min=1000000000
for city in chocity:
    if sd[city]<1000000000:
        if x>dd[city] :
            if min>sd[city]+dd[city]:
                min=sd[city]+dd[city]

if min==1000000000:
    print(-1)
else:
    print(min)


