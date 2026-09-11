class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> frq(10,0);
        int ans = 0;

        for(auto i:digits){
            frq[i]++;
        }   

        for(int i=1; i<10; i++){
            if(frq[i] == 0) continue;

            frq[i]--;
            for(int j=0; j<10; j++){
                if(frq[j] ==0) continue;

                frq[j]--;
                for(int k=0; k<9; k+=2){
                    if(frq[k] == 0) continue;

                    ans++;
                }
                frq[j]++;
            }
            frq[i]++;
        }

        return ans;
    }
};