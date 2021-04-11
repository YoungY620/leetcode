/*
 * @lc app=leetcode.cn id=120 lang=java
 *
 * [120] 三角形最小路径和
 *
 * https://leetcode-cn.com/problems/triangle/description/
 *
 * algorithms
 * Medium (67.18%)
 * Likes:    730
 * Dislikes: 0
 * Total Accepted:    140.1K
 * Total Submissions: 208.1K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * 给定一个三角形 triangle ，找出自顶向下的最小路径和。
 * 
 * 每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1
 * 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
 * 输出：11
 * 解释：如下面简图所示：
 * ⁠  2
 * ⁠ 3 4
 * ⁠6 5 7
 * 4 1 8 3
 * 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：triangle = [[-10]]
 * 输出：-10
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * triangle[0].length == 1
 * triangle[i].length == triangle[i - 1].length + 1
 * -10^4 
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题吗？
 * 
 * 
 */

// @lc code=start
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int lines = triangle.size();
        int cols = 1;
        int ans;
        for(int i=1;i<lines;i++){
            cols++;
            for(int j=0;j<cols;j++){
                int tmp;
                if(j==0){
                    tmp = triangle.get(i).get(j) + triangle.get(i-1).get(0);
                }else if(j==cols-1){
                    tmp = triangle.get(i).get(j) + triangle.get(i-1).get(j-1);
                }else{
                    tmp = triangle.get(i).get(j) + Math.min(triangle.get(i-1).get(j),
                                                        triangle.get(i-1).get(j-1));
                }
                triangle.get(i).set(j,tmp);
            }
        }
        ans = triangle.get(lines-1).get(0);
        for(int i=1;i<cols;i++){
            if(triangle.get(lines-1).get(i)<ans){
                ans = triangle.get(lines-1).get(i);
            }
        }
        return ans;
    }
}
// @lc code=end

