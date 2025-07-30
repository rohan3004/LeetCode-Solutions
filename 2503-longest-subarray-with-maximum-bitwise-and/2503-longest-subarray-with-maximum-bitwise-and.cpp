class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int maxV = 0,maxL=0,ans=0;
        for(const auto &i:nums){
            if(i>maxV){
                maxV=i;
                maxL=0;
                ans=0;
            }
            if(i==maxV) maxL++;
            else maxL=0;
            
            ans = max(maxL,ans);
        }
        return ans;
    }
};