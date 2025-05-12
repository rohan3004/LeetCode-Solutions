public class Solution {
    public int[] FindEvenNumbers(int[] digits) {
        var ans = new List<int>();
        var d = new int[10];

        foreach(int digit in digits) 
        {
            d[digit]++;
        }
        
        for(int i = 100; i < 1000; i+=2) 
        {
            var n = new int[10];
                
            var huns = i % 1000 / 100;
            var tens = i % 100 / 10;
            var ones = i % 10;

            n[huns]++;
            n[tens]++;
            n[ones]++;

            if(n[ones] <= d[ones] && n[tens] <= d[tens] && n[huns] <= d[huns]) 
            {
                ans.Add(i);
            }
        }

        return ans.ToArray();
    }
}