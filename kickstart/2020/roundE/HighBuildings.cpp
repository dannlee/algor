#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solve(int N,int A,int B,int C){
    string ans="";
    vector<int> lst(N);
    // C numbers of N height
    int g1,g2,g3,g4,i,second;
    g1=A-C;
    g2=B-C;
    g3=C;
    g4=N-A-B+C;
    
    if (N==2){
        second=1;    
    }
    else{
        second=2;    
    }
    
    if (N==1){
        
    }
    else if (g4<0 || g4>N-2){
        return "IMPOSSIBLE";
    }
    
    for (i=0;i<N;i++){
        if (g1>0){
            lst[i]=second;
            g1--;
        }
        else if (g4>0 && i!=0 &&i!=N-1){
            lst[i]=1;
            g4--;
        }
        else if (g3>0){
            lst[i]=N;
            g3--;
        }
        else if (g2>0){ // exception???????????????? left???
            lst[i]=second;
            g2--;
        }
        else{
            return "IMPOSSIBLE"; 
        }
    }
    ans = to_string(lst[0]);
    for(i=1;i<N;i++){
        ans = ans+" "+to_string(lst[i]);
    }
    return ans;
}

int main(){
    int T,N,i,A,B,C;
    string ans;
    cin >> T;
    
    for (i=0;i<T;i++){
        cin >> N >> A >> B >> C;
     
        ans = solve(N,A,B,C);
        
        cout << "Case #"<<i+1<<": "<<ans<< endl;
    }

    return 0;
}