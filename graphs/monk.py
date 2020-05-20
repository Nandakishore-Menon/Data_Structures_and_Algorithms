#https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/monk-learning-graph-3/
#this question has a problem
# the test cases and problem statement do not match
# the given code is to satisfy the test cases
n,m,k = map(int,input().split())
val = list(map(int,input().split()))
List = []
for i in range(n):
    List.append([])
for i in range(m):
    a,b = map(int,input().split())
    List[a-1].append(b-1)
    List[b-1].append(a-1)
for i in List:
    if len(i)<k:
        print(-1)
    else:
        i.sort(key = lambda j:(-val[j],-j))
        i = [x+1 for x in i]
        print(i[k-1])
    
