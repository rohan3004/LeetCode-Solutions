class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        const int n=nums.size();
        //Boyer–Moore majority vote algo
        int cnt=0, xM=0;
        for(int x: nums){
            if (cnt==0) xM=x;
            cnt+=(x==xM)?1:-1;
        }

        // find the valid split
        int cntL=0, cntR=0, i;
        for(i=0; i<n && cntL*2<=i; i++)
            cntL+=nums[i]==xM;
        i--;
        for (int j=i+1; j<n; j++)
            cntR+=nums[j]==xM;
        return cntR*2>(n-i-1)?i:-1;
    }
};