class Solution {
public:
    static int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int a=meetings[0][0], b=meetings[0][1];
        int n=meetings.size(), cnt=a-1;
        for(int i=0; i<n; i++){
            int c=meetings[i][0], d=meetings[i][1];
            if (c<=b) //merge
                b=max(b, d);
            else{// there are (c-b-1) days no meetings
                cnt+=(c-b-1);
                a=c, b=d;
            }
        }
        return cnt+(days-b);
    }
};