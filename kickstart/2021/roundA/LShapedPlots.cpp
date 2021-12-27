#include <iostream>
#include <vector>

using namespace std;

int main(){
    int T,R,C;
    cin >> T;
    
    
    for (int i=0;i<T;i++){
        cin >> R >> C;
        
        int ans = 0;
        
        vector <vector<int>> v;
        
        int temp;
        for (int j=0;j<R;j++){
            vector<int> rows;
            for (int k=0;k<C;k++){
                
                cin >> temp;
                rows.push_back(temp);
            }
            v.push_back(rows);
        }
        
        // check for each cell
        for (int j=0;j<R;j++){
            for(int k=0;k<C;k++){
                
                int e=0,w=0,s=0,n=0;
                int a=j,b=k;
                // east
                while(v[a][b]!=0){
                    e++;
                    if(a+1<R){
                        a++;
                    }
                    else break;
                }
                // west
                a=j;b=k;
                while(v[a][b]!=0){
                    w++;
                    if(a-1>=0){
                        a--;
                    }
                    else break;
                }
                // south
                a=j;b=k;
                while(v[a][b]!=0){
                    s++;
                    if(b+1<C){
                        b++;
                    }
                    else break;
                }
                // north
                a=j;b=k;
                while(v[a][b]!=0){
                    n++;
                    if(b-1>=0){
                        b--;
                    }
                    else break;
                
                }
                
                //1 n w
                    for (int c=n;c>1;c--){
                        for (int d=w;d>1;d--){
                            if(2*c == d || 2*d==c) ans++;
                        }
                    }
                
                //2 s w
                for (int c=s;c>1;c--){
                        for (int d=w;d>1;d--){
                            if(2*c == d || 2*d==c) ans++;
                        }
                    }
                
                //3 e n
                for (int c=n;c>1;c--){
                        for (int d=e;d>1;d--){
                            if(2*c == d || 2*d==c) ans++;
                        }
                    }
                //4 e s
                for (int c=s;c>1;c--){
                        for (int d=e;d>1;d--){
                            if(2*c == d || 2*d==c) ans++;
                        }
                    }
                
            }
        }
        
        cout << "Case #" << i+1 << ": " << ans << endl;
    }
    return 0;
}