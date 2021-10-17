// brute-force version.

#include <iostream>
#include <vector>
using namespace std;

int help(int N,int K,vector<int>&B){
    int minnum = N+1;
    
    long long int sum;
    // one consecutive
    for(int i =0;i<N;i++){
        sum = 0;
        for(int j=i;j<N;j++){
            sum+=B[j];
            if(sum==K) {
                if( j-i+1<minnum) minnum = j-i+1;
            }
            if(sum>K) break;
        }
    }
    
    bool skip=false;
    // two consecutive
    for(int i =0;i<N;i++){ // where to start 1st
        sum = 0;
        skip = false;
        for(int j=i;j<N;j++){ // where to stop 1st
            int midsum = 0;
            for(int temp=i;temp<j+1;temp++){
                midsum+=B[temp];
            }
            
            if(midsum>K) {
                skip = true;
                continue;
            }
            
            for(int k=j+2;k<N;k++){ // where to start 2nd
                int secsum = 0;
                for(int l=k;l<N;l++){
                    secsum+=B[l];
                    if(secsum+midsum==K) {
                        if(l-k+1+j-i+1 < minnum) minnum = l-k+1+j-i+1;
                    }
                    if(secsum+midsum>K) break;
                }
            }
            
            if(skip) break;
        }
    }
    
    if(minnum==N+1) return -1;
    return minnum;
}
int main(){
    int T;
    int N,K;
    
    cin >> T;
    
    for(int t;t<T;t++){
        vector<int> B;
        
        int ans;
        cin >> N >>K;
        
        for(int i=0;i<N;i++){
            int temp;
            cin >> temp;
            B.push_back(temp);
        }
        
        ans = help(N,K,B);
        cout << "Case #" << (t+1)<<": "<< ans << endl;
    }
    
}
