#include <iostream>
#include <vector>
using namespace std;

int solve(int N,vector<int> lst){
    int ans,i,prev,diff,cnt;
    ans = 0;
    prev= lst[1]-lst[0];
    cnt = 2;
    
    for (i=2;i<N;i++){
        diff = lst[i]-lst[i-1];
        if (prev == diff){
            cnt++;
        }
        else{
            if (ans<cnt){
                ans = cnt;
            }
            cnt=2;
        }
        prev = diff;
    }
    
    if (cnt>ans) ans=cnt;
    return ans;
}

int main(){
    int T,N,i,j,ans;
    cin >> T;
    
    for (i=0;i<T;i++){
        cin >> N;
        vector<int> lst(N);
        
        for (j=0;j<N;j++){
            cin >> lst[j];
        }
        
        ans = solve(N,lst);
        
        cout << "Case #"<<i+1<<": "<<ans<< endl;
    }

    return 0;
}