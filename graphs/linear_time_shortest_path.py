'''You are given a directed graph in which every edge weight is an integer between 1 and 5. Implement a linear time algorithm to compute the shortest path from a source node to every node of the graph.'''


n,m,s = map(int,input().split())
List=[]
path=[]
d=[float('inf')]*n
for i in range(n):
    List.append([])
    path.append([])
V={}
eweight={}
weight={}
minw=1000

for i in range(m):
    a,b,w = map(int,input().split())
    List[a-1].append(b-1)
    weight[(a-1,b-1)]=w
    if w<minw:
        minw=w
    V[(a-1,b-1)]=False
Q=[]
for edge in List[s-1]:
    Q.append((s-1,edge))
    V[(s-1,edge)]=True
    eweight[(s-1,edge)]=weight[(s-1,edge)]
    
d[s-1] = 0
#idea is to divide each edge until it is as small as minw
#Thus, BFS can be applied
#Since given range is 1 to 5, an edge will be enqueued 5 times at max and complexity will be O(5m+n)
while len(Q)!=0:
    (u,v)=Q.pop(0)
    w=eweight[(u,v)]-minw
    if w<=0:
        if d[u]+weight[(u,v)] < d[v]:
            d[v] = d[u]+weight[(u,v)]
            path[v].append(u+1)
            path[v]+=path[u]
            for x in List[v]:
                if V[(v,x)]==False:
                    if d[v]+weight[(v,x)] < d[x]:
                        Q.append((v,x))
                        V[(v,x)]=True
                        eweight[(v,x)]=weight[(v,x)]+w
                else:
                    eweight[(v,x)]=min(eweight[(v,x)],weight[(v,x)]+w)
    
    else:
        if d[u]+weight[(u,v)]<d[v]:
            Q.append((u,v))
            eweight[(u,v)]=w
            


print(d)# prints weight of path from source to each vertex
ind=1
for i in path:#prints path(if it is reachable)
    if d[ind-1]!=float('inf'):
        i.reverse()
        print(*i,sep="-->",end="")
        print("-->"+str(ind),end="")
        print()
    else:
        print(str(ind)+" is not reachable")
    ind+=1
#sample input for copy/paste
'''
6 8 4
1 2 2
2 3 4
2 4 3
3 4 2
4 5 5
6 1 3
2 5 1
5 6 2
'''
