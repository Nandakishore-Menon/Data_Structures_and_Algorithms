#https://leetcode.com/problems/course-schedule-ii/

def DFSvertex(u, numCourses, adjacencyList, array, flag, Visit, recurssionStack):
    Visit[u] = 1
    if u in recurssionStack:
        flag = 0
    else:
            recurssionStack.append(u)
    for v in adjacencyList[u]:
        if(Visit[v] == 0):
            flag = DFSvertex(v, numCourses, adjacencyList, array, flag, Visit, recurssionStack)
        elif (Visit[v] == 1):
            if v in recurssionStack:
                flag = 0
    recurssionStack.remove(u)
    array.append(u)
    return flag
        
def DFS(numCourses, adjacencyList, array, flag):
    Visit = []
    for i in range(numCourses):
        Visit.append(0)
    recurssionStack = []
    for u in range(numCourses):
        if(Visit[u] == 0 and flag == 1):
            flag = DFSvertex(u, numCourses, adjacencyList, array, flag, Visit, recurssionStack)
    return flag
                
class Solution:
    
    def findOrder(self, numCourses, prerequisites):
        array = []
        empty = []
        adjacencyList = []
        for i in range(numCourses):
            adjacencyList.append([])
        #print (adjacencyList)
        for l in prerequisites:
            adjacencyList[l[1]].append(l[0])
        flag = 1
        flag = DFS(numCourses, adjacencyList, array, flag)
        array.reverse()
        if (flag == 1):
            return array
        else:
            return empty
