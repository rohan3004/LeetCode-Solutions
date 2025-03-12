class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int nc=0,pc=0;
        for(auto const &i:nums){
            if(i>0)pc++;
            else if(i<0)nc++;
        }
        return std::max(pc,nc);
    }
};