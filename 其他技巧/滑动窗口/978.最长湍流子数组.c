/*
 * @lc app=leetcode.cn id=978 lang=c
 *
 * [978] 最长湍流子数组
 *
 * https://leetcode-cn.com/problems/longest-turbulent-subarray/description/
 *
 * algorithms
 * Medium (42.57%)
 * Likes:    153
 * Dislikes: 0
 * Total Accepted:    35.5K
 * Total Submissions: 75.5K
 * Testcase Example:  '[9,4,2,10,7,8,8,1,9]'
 *
 * 当 A 的子数组 A[i], A[i+1], ..., A[j] 满足下列条件时，我们称其为湍流子数组：
 * 
 * 
 * 若 i <= k < j，当 k 为奇数时， A[k] > A[k+1]，且当 k 为偶数时，A[k] < A[k+1]；
 * 或 若 i <= k < j，当 k 为偶数时，A[k] > A[k+1] ，且当 k 为奇数时， A[k] < A[k+1]。
 * 
 * 
 * 也就是说，如果比较符号在子数组中的每个相邻元素对之间翻转，则该子数组是湍流子数组。
 * 
 * 返回 A 的最大湍流子数组的长度。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[9,4,2,10,7,8,8,1,9]
 * 输出：5
 * 解释：(A[1] > A[2] < A[3] > A[4] < A[5])
 * 
 * 
 * 示例 2：
 * 
 * 输入：[4,8,12,16]
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 输入：[100]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 40000
 * 0 <= A[i] <= 10^9
 * 
 * 
 */

// @lc code=start

// 不符合湍流
# define A ((arr[right]>=arr[right-1]&&arr[right-1]>=arr[right-2])\
    ||(arr[right]<=arr[right-1]&&arr[right-1]<=arr[right-2]))

int maxTurbulenceSize(int* arr, int arrSize){
    int left = 0;
    int right = 0;
    int len = 0;
    int maxlen = 0;

    while(right<arrSize){
        // printf("%d %d\n", left, right);
        len++;
        if(right-left>=2 && A){
            len=0;
            left = --right;
        }else if(right - left == 1 && arr[left] == arr[right]){
            len=0;
            left = right;
        }else{
            right++;
        }
        if(maxlen<len){
            maxlen = len;
        }
    }
    return maxlen;
}

// @lc code=end

