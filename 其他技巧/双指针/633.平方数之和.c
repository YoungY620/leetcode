/*
 * @lc app=leetcode.cn id=633 lang=c
 *
 * [633] 平方数之和
 *
 * https://leetcode-cn.com/problems/sum-of-square-numbers/description/
 *
 * algorithms
 * Medium (35.13%)
 * Likes:    206
 * Dislikes: 0
 * Total Accepted:    54.6K
 * Total Submissions: 145.8K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a^2 + b^2 = c 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：c = 5
 * 输出：true
 * 解释：1 * 1 + 2 * 2 = 5
 * 
 * 
 * 示例 2：
 * 
 * 输入：c = 3
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 输入：c = 4
 * 输出：true
 * 
 * 
 * 示例 4：
 * 
 * 输入：c = 2
 * 输出：true
 * 
 * 
 * 示例 5：
 * 
 * 输入：c = 1
 * 输出：true
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= c <= 2^31 - 1
 * 
 * 
 */

// @lc code=start


bool judgeSquareSum(int c){
    int i;
    for(i=0;(unsigned long long)i*i<=c;i++){
        int left = 0;
        int right = c-i;
        while(left<right){
            int mid = (right+left)>>1;
            unsigned long long cc = (unsigned long long)mid*mid+(unsigned long long)i*i;
            // printf("%d %d\n",left,right);
            if(cc >= c){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        // printf("%d %d\n",left,right);
        if((unsigned long long)left*left+(unsigned long long)i*i == c){
            return true;
        }
    }
    return false;
}
// @lc code=end

