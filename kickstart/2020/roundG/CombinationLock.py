T = int(input())

def solve(w,n,lst) :
    ans = 100000000 ##
    
    for i in range(1,N+1) : # to become i..
        total = 0
        for j in range(w) :
            if i > lst[j]:
                tmp = min(i-lst[j],N-i+lst[j])
            else :
                tmp = min(lst[j]-i,N-lst[j]+i)
            
            total += tmp
            
            
        if total < ans :
            ans = total
            
    return ans

for t in range(T):
    W, N = map(int,input().split())
    
    lst = list(map(int,input().split()))
        
    ans = solve(W,N,lst)
    print('Case #{}: {}'.format(t+1,ans))