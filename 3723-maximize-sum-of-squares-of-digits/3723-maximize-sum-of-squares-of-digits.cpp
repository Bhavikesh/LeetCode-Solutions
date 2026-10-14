class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > 9*num) return "";

        int nau = sum/9;
        int rahilaKiti = sum%9;

        string uttar = "";

        while(nau--){
            uttar.push_back('9');
            num--;
        }
        if(num>0){

            uttar.push_back('0'+rahilaKiti);
            num--;

            while(num--){
                uttar.push_back('0');
            }
        }

        return uttar;
    }
};