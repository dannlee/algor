#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
    int T;
    
    cin >> T;
    
    for(int t=0;t<T;t++){
        int N;
        string P;
        
        cin >> N;
        cin >> P;
        
        int ans = 0;
        set<char> currset;
        
        for(auto p : P){
            
            if(p=='O'){
                if (currset.find('R')==currset.end()){
                    ans++;
                }
                if (currset.find('Y')==currset.end()){
                    ans++;
                }
                currset.clear();
                currset.insert('R');
                currset.insert('Y');
            }
            else if(p=='P'){
                if (currset.find('R')==currset.end()){
                    ans++;
                }
                if (currset.find('B')==currset.end()){
                    ans++;
                }
                currset.clear();
                currset.insert('R');
                currset.insert('B');
            }
            else if(p=='G'){
                if (currset.find('Y')==currset.end()){
                    ans++;
                }
                if (currset.find('B')==currset.end()){
                    ans++;
                }
                currset.clear();
                currset.insert('Y');
                currset.insert('B');
            }
            else if(p=='A'){
                if (currset.find('R')==currset.end()){
                    ans++;
                }
                if (currset.find('Y')==currset.end()){
                    ans++;
                }
                if (currset.find('B')==currset.end()){
                    ans++;
                }
                currset.clear();
                currset.insert('R');
                currset.insert('Y');
                currset.insert('B');
            }
            
            // primary
            else if(p=='R'){
                if (currset.find('R')==currset.end()){
                    ans++;
                }
                currset.clear();
                currset.insert('R');
            }
            else if(p=='Y'){
                if (currset.find('Y')==currset.end()){
                    ans++;
                }
                currset.clear();
                currset.insert('Y');
            }
            else if(p=='B') {
                if (currset.find('B')==currset.end()){
                    ans++;
                }
                currset.clear();
                currset.insert('B');
            } 
            else if(p=='U') {
                currset.clear();
            } 
        }
        
        
        cout << "Case #" << t+1 <<": " << ans <<"\n";
    }
    
    return 0;
}