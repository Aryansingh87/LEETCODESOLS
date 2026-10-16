class Solution {
public:
    int minFlips(string target) {
        int flip=0 ,check='0';
        int n= target.length();
        for(int i=0;i<n;i++){
            if(check != target[i]){
                flip++;
                check = check== '0' ? '1' : '0';
            }
        }
        return flip;
    }
};