#https://leetcode.com/problems/time-needed-to-inform-all-employees/

def dfs(manager,maxt,informTime,sub):
    stack = []
    stack.append([manager, informTime[manager]])
    while(stack):
        mgr,time= stack.pop()
        maxt= max(maxt,time)
        for s in sub[mgr]:
            stack.append([s,time+informTime[s]])
    return maxt

class Solution(object):
    def numOfMinutes(self, n, headID, manager, informTime):
        """
        :type n: int
        :type headID: int
        :type manager: List[int]
        :type informTime: List[int]
        :rtype: int
        """
        sub= [[] for i in range(n)]
        maxt= -100000000000
        for s, m in enumerate(manager):
            if m != -1:
                sub[m].append(s)
        return dfs(headID,maxt,informTime,sub)
