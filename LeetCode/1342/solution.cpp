// 1342. Number of Steps to Reduce a Number to Zero
class Solution {
  public:
    int numberOfSteps(int num) {
      int cnt = 0;
      while(num){
        num = (num%2 == 0) ? num/2 : num-1;
        cnt++;
      }
      return cnt;
    }
};