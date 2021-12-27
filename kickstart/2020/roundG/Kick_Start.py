T = int(input())

def solve(s) :
    cnt = 0 # num encountered with KICK
    ans = 0
    
    kcnt = 0
    scnt = 0
    prev =''
    
    for c in s :
        if prev=='K' and c=='I' :
            kcnt=1
        elif prev=='I' and c=='C' and kcnt==1:
            kcnt=2
        elif prev=='C' and c=='K' and kcnt==2:
            cnt+=1
            kcnt=0
        else :
            kcnt=0
          
            
        if prev=='S' and c=='T' :
            scnt=1
        elif prev=='T' and c=='A' and scnt==1:
            scnt=2
        elif prev=='A' and c=='R' and scnt==2:
            scnt=3
        elif prev=='R' and c=='T' and scnt==3:
            ans+=cnt
            scnt=0
        else :
            scnt=0
            
        prev = c
        
    return ans

for t in range(T):
    s = list(input())
    ans = solve(s)
    print('Case #{}: {}'.format(t+1,ans))