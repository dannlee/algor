#include <iostream>
#include <string>
using namespace std;

string help(long long int N, long long int D, long long int C,long long int M, string S){
    bool nofood = false;
    
    for(int i=0;i<N;i++){
        if(nofood){
            if(S[i]=='D') return "NO";
            continue;
        }
        if(S[i]=='D') {
            if(D<=0) {
                return "NO";
            }
            D--; 
            C+=M;
        }
        else if(S[i]=='C') {
            if(C<=0) {
                nofood=true;
                continue;
            }
            C--;
        }
    }
    
    return "YES";
}

int main(){
    int T;
    long long int N,D,C,M;
    string S;
    
    cin >> T;
    
    for(int t;t<T;t++){
        string ans;
        cin >> N >> D >> C >> M;
        cin >> S;
        ans = help(N,D,C,M,S);        
        cout << "Case #" << (t+1)<<": "<< ans << endl;
    }
    
}
