def solve(N,lst):
    cnt = 0
    largest = -1
    for i in range(N):
        if (lst[i]>largest):
            if (i==N-1):
                cnt+=1
            elif (lst[i]>lst[i+1]):
                cnt+=1
            
        if lst[i]>largest:
            largest = lst[i]
    
    return cnt

T = int(input())
for t in range(T):
    N = int(input())
    tmp = list(input().split())
    lst = [int(x) for x in tmp]
    print("Case #{}: {}".format(t+1,solve(N,lst)))
    