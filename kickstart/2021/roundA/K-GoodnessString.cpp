#include <iostream>
#include <string>

using namespace std;

int main(){
    int T,K,N;
    string S;
    
    cin >> T;
    
    
    for (int i=0;i<T;i++){
        cin >> N >> K;
        cin >> S;
        
        int good = 0;
        int ans = 0;
        
        for (int j=0;j<N/2;j++){
            if (S[j]!=S[N-j-1]){
                good++;
            }
        }
        
        if (K>good){
            ans = K - good;
        }
        else if (K<good) {
            ans = good -K;
        }
        
        cout << "Case #" << i+1 << ": " << ans << endl;
    }
    return 0;
}