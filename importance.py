#https://leetcode.com/problems/employee-importance/

"""
# Definition for Employee.
class Employee(object):
    def __init__(self, id, importance, subordinates):
        #################
        :type id: int
        :type importance: int
        :type subordinates: List[int]
        #################
        self.id = id
        self.importance = importance
        self.subordinates = subordinates
"""
def dfs(emp_id, sub):
    emp=sub[emp_id]
    return (emp.importance+ sum(dfs(emp_id,sub) for emp_id in emp.subordinates))
class Solution(object):
    def getImportance(self, employees, id):
        """
        :type employees: List[Employee]
        :type id: int
        :rtype: int
        """
        sub={emp.id: emp for emp in employees}
        return dfs(id,sub)
        

