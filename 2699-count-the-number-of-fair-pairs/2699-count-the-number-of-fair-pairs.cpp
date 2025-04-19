class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        return f(nums,upper) - f(nums,lower-1);
    }
private:
    long f(vector<int> &nums,int s){
        long ans =0;
        for(int i=0,j=nums.size()-1;i<j;++i){
            while(i<j && nums[i]+nums[j]>s)
                --j;
                ans+=j-i;
        }
        return ans;
    }
};