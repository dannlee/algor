#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
    int T;
    
    cin >> T;
    
    for(int t=0;t<T;t++){
        string S,F;
        int ans=0;
        
        cin >> S;
        cin >> F;
        
        set<char> fset;
        
        for(auto f : F){
            fset.insert(f);
        }
        
        for(auto s : S){
            if(fset.find(s)==fset.end()){ // Do not exist in fset
                int mindiff = 987654321;
                for(auto f : F){
                    int diff = 987654321;
                    diff = min(abs((int)s-(int)f),26-abs((int)s-(int)f));
                    if(diff < mindiff){
                        mindiff = diff;
                        
                    }
                }
                ans+=mindiff;
            }
        }
        
        cout << "Case #" << t+1 <<": " << ans <<"\n";
    }
    
    return 0;
}