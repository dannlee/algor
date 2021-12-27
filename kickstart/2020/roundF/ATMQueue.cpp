#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
string solve(vector<int> & v, int N,int limit){
    int cnt;
    //vector<pair<int,int>> vv;
    map<int,vector<int>> m;
    string ans;
    for (int i=0;i<N;i++){
        cnt = v[i]/limit;
        if (v[i]%limit > 0){
            cnt++;
        }
        //vv.push_back(make_pair(cnt,i+1));
        map<int,vector<int>>::iterator it = m.find(cnt);
        if(it != m.end()){
            (it->second).push_back(i+1);
        }
        else{
            vector<int> vvv;
            vvv.push_back(i+1);
            m.insert({cnt,vvv});
        }
    }
    
    vector<int> anslst;
    for (auto const& pairs : m){
        for(auto mem : pairs.second){
            anslst.push_back(mem);
        }
    }
    
    ans = to_string(anslst[0]);
    for (int i=1;i<N;i++){
        ans+=" ";
        ans+=to_string(anslst[i]);
    }
    return ans;
}
int main(){
    int T,N,X;
    cin >> T;
    int temp;
    for (int i=0;i<T;i++){
        cin >> N >> X;
        
        vector<int> v(N);
        for (int j=0;j<N;j++){
            cin >> temp;
            v[j]=temp;
        }
        
        string ans = solve(v,N,X);
        cout << "Case #" <<i+1<<": "<<ans<<endl;
    }
    
    return 0;
}