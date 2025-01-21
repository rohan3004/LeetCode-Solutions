class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long fRowSum=0, sRowSum=0, ans = LONG_LONG_MAX;
        for(int i=0;i<grid[0].size();i++)fRowSum+=grid[0][i];

        for(int i=0;i<grid[0].size();i++){
            fRowSum-=grid[0][i];

            long long robot2Best = max(fRowSum,sRowSum);

            sRowSum+=grid[1][i];

            ans = min(ans,robot2Best);
        }
        
        return ans;
    }
};