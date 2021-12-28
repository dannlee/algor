class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        
        int start = -1;
        int end = -1;
        
        sort(intervals.begin(),intervals.end());
        
        for(int i=0;i<intervals.size();i++){
        
            vector<int> mem = intervals[i];
            
            if(start==-1) {
                start = mem[0];
                end = mem[1];
            }
            
            if(end < mem[0]){
                vector<int> tmp{start,end};
                ans.push_back(tmp);
                start = mem[0];
                end = mem[1];
            }
            else{
                if(end < mem[1]) end = mem[1];
    
            }
        }
        
      
        vector<int> tmp{start,end};
        ans.push_back(tmp);
        
        return ans;
    }
};
