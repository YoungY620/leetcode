/*
 * @lc app=leetcode.cn id=152 lang=c
 *
 * [152] 乘积最大子数组
 *
 * https://leetcode-cn.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (41.04%)
 * Likes:    964
 * Dislikes: 0
 * Total Accepted:    120.4K
 * Total Submissions: 293K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * 给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [2,3,-2,4]
 * 输出: 6
 * 解释: 子数组 [2,3] 有最大乘积 6。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-2,0,-1]
 * 输出: 0
 * 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 * 
 */

// @lc code=start


int maxProduct(int* nums, int numsSize){
    int i;
    int max = nums[0];
    int mindp[numsSize];
    int maxdp[numsSize];
    if(numsSize==1) return nums[0];
    mindp[0] = nums[0];
    maxdp[0] = nums[0];

    for(i=1;i<numsSize;i++){
        if(nums[i]<=0){
            maxdp[i] = fmax(mindp[i-1]*nums[i],nums[i]);
            mindp[i] = fmin(maxdp[i-1]*nums[i],nums[i]);
        }else{
            mindp[i] = fmin(mindp[i-1]*nums[i],nums[i]);
            maxdp[i] = fmax(maxdp[i-1]*nums[i],nums[i]);
        }
        if(max<maxdp[i]){
            max = maxdp[i];
        }
    }
    return max;
}

// @lc code=end

