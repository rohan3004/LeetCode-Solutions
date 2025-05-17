class Solution {
public:
    void sortColors(vector<int>& nums) {
        int f[3]={0};
        for(int i:nums){
            f[i]++;
        }
        int c=0;
        for(int i =0;i<3;i++){
            fill(nums.begin()+c,nums.begin()+c+f[i],i);
            c+=f[i];
        }
    }
};