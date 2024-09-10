vector<vector<string>> groupAnagrams(vector<string>& strs) {
       
        vector<string> copy_strs;
        for(auto x: strs){
            copy_strs.push_back(x);
        }

        for(int i=0;i<strs.size();i++){
            sort(strs[i].begin(),strs[i].end());
        }
        
        vector<int> groups(strs.size(),-1);
        vector<vector<string>> ans;
        for(int i=0;i<strs.size();i++){
            if(groups[i]==-1){
                groups[i]=i;
            }
            else{
                continue;
            }//this is used for optimization
            vector<string> same_strings;
            for(int j=i;j<strs.size();j++){
                if(strs[j]==strs[i]){
                    groups[j]=i;
                    same_strings.push_back(copy_strs[j]);
                }
            }
            ans.push_back(same_strings);
        }
        
        return ans;
    }