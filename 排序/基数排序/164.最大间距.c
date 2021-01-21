/*
 * @lc app=leetcode.cn id=164 lang=c
 *
 * [164] 最大间距
 *
 * https://leetcode-cn.com/problems/maximum-gap/description/
 *
 * algorithms
 * Hard (61.23%)
 * Likes:    334
 * Dislikes: 0
 * Total Accepted:    47.8K
 * Total Submissions: 78.1K
 * Testcase Example:  '[3,6,9,1]'
 *
 * 给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。
 * 
 * 如果数组元素个数小于 2，则返回 0。
 * 
 * 示例 1:
 * 
 * 输入: [3,6,9,1]
 * 输出: 3
 * 解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。
 * 
 * 示例 2:
 * 
 * 输入: [10]
 * 输出: 0
 * 解释: 数组元素个数小于 2，因此返回 0。
 * 
 * 说明:
 * 
 * 
 * 你可以假设数组中所有元素都是非负整数，且数值在 32 位有符号整数范围内。
 * 请尝试在线性时间复杂度和空间复杂度的条件下解决此问题。
 * 
 * 
 */

// @lc code=start

int cmp(int *i, int *j){
    return (*i)-(*j);
}

void sort(int *nums, int size){
    
}

int maximumGap(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    // printf("%d %d \n", nums[0], nums[1]);
    int max_gap = 0;
    int i;
    for(i=1;i<numsSize;i++){
        if(nums[i]-nums[i-1]>max_gap){
            max_gap = nums[i]-nums[i-1];
        }
    }
    return max_gap;
}
// @lc code=end

