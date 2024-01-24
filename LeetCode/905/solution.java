// 905. Sort Array By Parity
class Solution {
    public int[] sortArrayByParity(int[] nums) {
        int i=0, j=nums.length-1;
        while(i<j){
            while(i<j && nums[i]%2==0) i++;
            while(i<j && nums[j]%2!=0) j--;
            if(i<j) {
              int tmp = nums[i];
              nums[i] = nums[j];
              nums[j] = tmp;
            }
        }
        return nums;
    }
}