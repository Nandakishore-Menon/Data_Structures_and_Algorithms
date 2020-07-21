'''You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].'''


#nums=[7,3,2,4,1,6,5]
nums=list(map(int,input().split()))
n=len(nums)
index=[i for i in range(1,n+1)]
#print(index)
index.sort(key=lambda i: nums[i-1])
#print(index)
order={index[i-1]:i for i in range(1,n+1)}
#print(order)
index=[0]*(n+1)
def update(i):
    while i<n+1:
        index[i]+=1
        i+=(i&(-i))
def sum(i):
    count=0
    while i>0:
        count+=index[i]
        i-=(i&(-i))
    return count


counts=[0]*(n)
for i in range(n-1,-1,-1):
    counts[i]=sum(order[i+1])
    update(order[i+1])
print(*counts,sep=" ")
