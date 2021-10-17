// go brute-force

#include <iostream>
#include <vector>
#include <math.h>
#include <climits>
using namespace std;

//x -> y minimum. can overlap.

int main(){
    int T;
    int N,K;
    
    cin >> T;
    
    for(int t;t<T;t++){
        vector<vector<int>> furns;
       
        cin >> K;
        
        long long int minx = pow(10,9)+1;
        long long int miny = pow(10,9)+1;
        long long int maxx = -pow(10,9)-1;
        long long int maxy = -pow(10,9)-1;
        
        for(int i=0;i<K;i++){
            long long int a,b,c,d;
            cin >> a>>b>>c>>d;
            if(a<minx) minx=a;
            if(b<miny) miny=b;
            if(c>maxx) maxx=c;
            if(d>maxy) maxy=d;
            vector<int> tmp;
            tmp.push_back(a);
            tmp.push_back(b);
            tmp.push_back(c);
            tmp.push_back(d);
            furns.push_back(tmp);
        }
        unsigned long long mind = ULLONG_MAX;
        
        int ansx = 0;
        int ansy = 0;
        
        for(long long int x = minx;x<=maxx;x++){
            for(long long int y = miny;y<=maxy;y++){
                unsigned long long curr = 0;
                
                for(auto mem : furns){
                    unsigned long long xdis=0;
                    unsigned long long ydis=0;
                    
                    // inside? zero. you have to put it separetely.
                    if(x>=mem[0]&&x<=mem[2]) xdis =0;
                    else xdis = min(abs(mem[0]-x),abs(mem[2]-x));
                    if(y>=mem[1]&&y<=mem[3]) ydis =0;
                    else ydis = min(abs(mem[1]-y),abs(mem[3]-y));
                    
                    curr+=xdis+ydis;
                }
                
                if(curr<mind){
                    mind = curr;
                    ansx = x;
                    ansy = y;
                }
            }
        }
        
        cout << "Case #" << (t+1)<<": "<< ansx <<" "<<ansy << endl;
    }
    
}
