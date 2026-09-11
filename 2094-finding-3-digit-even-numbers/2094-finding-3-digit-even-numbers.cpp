class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> frq(10,0);
        vector<int> ans;
        for(int i:digits){
            frq[i]++;
        }

        for(int i = 100; i<=998; i+=2){
            int a = i/100;
            int b = (i/10)%10;
            int c = i%10;

            vector<int> req(10,0);
            req[a]++;
            req[b]++;
            req[c]++;

            bool possible = true;

            for(int i=0; i<10; i++){
                if(req[i]>frq[i]) {
                    possible = false;
                    break;
                }
            }

            if(possible){
                ans.push_back(i);
            }
        }
        return ans;
    }
};