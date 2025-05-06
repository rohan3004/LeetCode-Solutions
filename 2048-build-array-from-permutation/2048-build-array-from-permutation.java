class Solution {
    public int[] buildArray(int[] nums) {
        int[] r = new int[nums.length];
        int k = 0;
        for(int i:nums)
            r[k++]=nums[i];
        return r;
    }
}