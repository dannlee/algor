

#include <iostream>

using namespace std;

int main(){
    
    int T;
    cin >> T;
    for (int t=0;t<T;t++){
        int N,K,S,ans;
        cin >> N;
        cin >> K;
        cin >> S;
        
        int a,b;
        a = K+N;
        b = 2*K-2*S+N;
        if (a<b) ans = a;
        else ans = b;
        
        cout << "Case #" << t+1 << ": "<<ans<<endl;
    }
    
    return 0;
}   