#https://leetcode.com/problems/course-schedule/
from collections import defaultdict
def DFS(V,u,n,l,c,new,F):
        V[u]=True
        for x in l[u]:
            if V[x]==False:
                if DFS(V,x,n,l,c,new,F)==False:
                    return False
                for y in new:
                    if u in l[y]:
                        new=[]
                        return False
        new.insert(0,u)
        c+=1
        return True
        



class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        new=[]
        if prerequisites==[]:
            for i in range(0,numCourses):
                new.append(i)
            return new
        V=[False]*numCourses
        adj_list = defaultdict(list)
        for x, y in prerequisites:
            adj_list[y].append(x)


        for i in range(numCourses):
            if V[i]==False:
                if DFS(V,i,numCourses,adj_list,0,new,1)==False:
                    return False
                if len(new)==numCourses:
                    break
        return True
        


