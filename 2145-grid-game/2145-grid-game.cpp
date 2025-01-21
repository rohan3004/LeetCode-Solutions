class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {

        //First Row Sum, Second Row Sum, and Answer
        long long fRowSum=0, sRowSum=0, ans = LONG_LONG_MAX;
        for(int i=0;i<grid[0].size();i++)fRowSum+=grid[0][i];
        //Count the First Row Sum

        for(int i=0;i<grid[0].size();i++){
            fRowSum-=grid[0][i];//Points of the robot 2 depends on the column that robot 1 takes

            long long robot2Best = max(fRowSum,sRowSum); //Robot 2 playes optimally to choose its best

            sRowSum+=grid[1][i]; //Second Row Sum that robot 2 can take for the next iteration, current iteration robot 1 takes

            ans = min(ans,robot2Best); //Robot 1 takes that decision that will be lead to minimum for the robot 2 
        }
        
        return ans;
    }
};