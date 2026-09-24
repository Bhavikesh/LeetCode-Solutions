class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        string prev = "";
        for(int i= 0; i<words.size(); i++){
            string temp = words[i];
            sort(temp.begin(), temp.end());

            if(prev != temp){
                ans.push_back(words[i]);
                prev = temp;
            }
        }

        return ans;
    }
};