class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> frq(10,0);
        vector<int> ans;

        for(int i:digits){
            frq[i]++;
        }
        //we are using the freeq to generate the number 
        for(int i=1; i<=9; i++){ //start can't be 0
            if(frq[i] == 0) continue;  // hundered place

            frq[i]--;

            for(int j=0; j<=9; j++){
                if(frq[j] == 0) continue; // tens place

                frq[j]--;

                for(int k=0; k<=8; k+=2){
                    if(frq[k] == 0) continue;//unit place

                    int num = i*100 + j*10 + k;
                    ans.push_back(num);
                }

                frq[j]++;
            }
            frq[i]++;
        }
        return ans;
    }
};