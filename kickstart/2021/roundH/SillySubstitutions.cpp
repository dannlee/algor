#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int T;
    
    cin >> T;
    
    for(int t=0;t<T;t++){
        long long ans = 0;
        int N;
        string S;
        vector<int> v;
        
        cin >> N;
        cin >> S;
        for(int i=0;i<N;i++){
            v.push_back(S[i]-'0');
        }
        
        bool stop = false;
        while(!stop){
            stop = true;
            
            int find = 0;
            while(find<10){
                bool keepfind = false;
                for(int i=0;i<v.size()-1;i++){
                    if((((v[i]+1)%10)==v[i+1])&&(v[i]==find)){ // found the find.
                        stop = false;
                        v[i+1]++;
                        v[i+1]%=10;
                        v.erase(v.begin()+i);
                        keepfind = true;
                        break;
                    }
                }
                
                if(!keepfind) find++;
            }
        }
        
        cout << "Case #" << t+1 <<": ";

        for(auto mem : v){
            cout << mem;
        }
        
        cout <<"\n";
    }
    
    return 0;
}