#include <iostream>
#include <string>

using namespace std;

int main(){
    
    int T;
    cin >> T;
    for (int t=0;t<T;t++){
        int L,R,ans;
        cin >> L;
        cin >> R;
        bool flag = true;
        ans=0;
        for(int i=L;i<R+1;i++){
            string str=to_string(i);
            flag = true;
            for(int j=1;j<str.length()+1;j++){
                if(str[j-1]%2!=j%2) {
                    flag=false;
                    break;
                }
            }
            if(flag==true)ans++;
        }
        
        cout << "Case #" << t+1 << ": "<<ans<<endl;
    }
    
    return 0;
}   