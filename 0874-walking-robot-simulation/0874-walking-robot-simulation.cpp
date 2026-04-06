class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        const long long M = 6e4+1, lb = -3e4;
        unordered_set<long long> ob;
        ob.reserve(obstacles.size());

        for(auto &i:obstacles){
            long long x = i[0]-lb, y = i[1]-lb;
            ob.insert(x*M+y);
        }

        const int dir[4][2]={{0,1},{-1,0},{0,-1},{1,0}}; //nwse
        int x=0, y=0, dx=0, dy=1, face=0, maxD2=0;

        for(int i:commands){
            switch(i){
                case -2: face=(face+1)%4; dx=dir[face][0]; dy=dir[face][1]; break;
                case -1: face=(face+3)%4; dx=dir[face][0]; dy=dir[face][1]; break;
                default:
                    for(int j=0; j<i; j++){
                        x+=dx, y+=dy;
                        if (ob.count((x-lb)*M+y-lb)) {
                            x-=dx;  // undo move
                            y-=dy;
                            break;
                        }
                        maxD2=max(maxD2, x*x+y*y);
                    }
            }
        }

        auto rohan = [](){
            ios::sync_with_stdio(false);
            cin.tie(nullptr);
        };
        return maxD2;
    }
};