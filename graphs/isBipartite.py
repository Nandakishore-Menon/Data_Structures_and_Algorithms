#https://leetcode.com/problems/is-graph-bipartite/submissions/
class Solution(object):
    def isBipartite(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: bool
        """
        Length=[-1]*(len(graph))
        Q=[]
        V=[False]*(len(graph))
        for i in range((len(graph))):
            if(V[i]==False):
                Q.append(i)
                V[i]=True
                Length[0]=0
                while len(Q)!=0:
                    u=Q.pop(0)
                    for v in graph[u]:
                        if Length[v]<0:
                            Q.append(v)
                            V[v]=True
                            Length[v]=Length[u]+1
        
        
        for x in range(0,len(graph)):
            for v in graph[x]:
                if Length[v]%2==Length[x]%2:
                    return False
        return True
            
