class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;

        for(int i=0; i<m-1; i++){
            string s = "";
            s.push_back('.');
            for(int j=1;j <n; j++){
                s.push_back('#');
            }

            ans.push_back(s);
        }
        string a="";
        for(int i=0; i<n; i++){
            a.push_back('.');
        }

        ans.push_back(a);

        return ans;
    }
};