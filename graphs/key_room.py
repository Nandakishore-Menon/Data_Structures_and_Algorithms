#https://leetcode.com/problems/keys-and-rooms/submissions/

def dfs(rooms,u,V):
    V[u]=True
    for room in rooms[u]:
        if V[room]==False:
            dfs(rooms,room,V)


class Solution(object):
    

    def canVisitAllRooms(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: bool
        """
        V=[False]*len(rooms)
        dfs(rooms,0,V)
        return all(V)
        
        

            
