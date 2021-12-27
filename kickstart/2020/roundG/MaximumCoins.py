T = int(input())

def solve(lst,n) :
    ans = 0
    
    for i in range(n):
        #from (i,0) to Boundaries
        total = 0
        a = i
        b = 0
        
        while(a<N and b<N):
            total+=lst[a][b]
            a+=1
            b+=1
        
        if total>ans:
            ans = total
            
    for i in range(n):
        #from (0,i) to Boundaries
        total = 0
        a = 0
        b = i
        while(a<N and b<N):
            total+=lst[a][b]
            a+=1
            b+=1
        if total>ans:
            ans = total
            
    return ans

for t in range(T):
    N = int(input())
    lst = [[] for _ in range(N)]
    for n in range(N) :
        tlst = list(map(int,input().split()))
        lst[n]=tlst
        
    ans = solve(lst,N)
    print('Case #{}: {}'.format(t+1,ans))