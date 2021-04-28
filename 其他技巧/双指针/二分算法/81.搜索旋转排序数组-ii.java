/*
 * @lc app=leetcode.cn id=81 lang=java
 *
 * [81] 搜索旋转排序数组 II
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Medium (37.05%)
 * Likes:    410
 * Dislikes: 0
 * Total Accepted:    95.8K
 * Total Submissions: 230.9K
 * Testcase Example:  '[2,5,6,0,0,1,2]\n0'
 *
 * 已知存在一个按非降序排列的整数数组 nums ，数组中的值不必互不相同。
 * 
 * 在传递给函数之前，nums 在预先未知的某个下标 k（0 ）上进行了 旋转 ，使数组变为 [nums[k], nums[k+1], ...,
 * nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如，
 * [0,1,2,4,4,4,5,6,6,7] 在下标 5 处经旋转后可能变为 [4,5,6,6,7,0,1,2,4,4] 。
 * 
 * 给你 旋转后 的数组 nums 和一个整数 target ，请你编写一个函数来判断给定的目标值是否存在于数组中。如果 nums 中存在这个目标值
 * target ，则返回 true ，否则返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,5,6,0,0,1,2], target = 0
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,5,6,0,0,1,2], target = 3
 * 输出：false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10^4 
 * 题目数据保证 nums 在预先未知的某个下标上进行了旋转
 * -10^4 
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
 * 这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？
 * 
 * 
 */

// @lc code=start
class Solution {
    public boolean search(int[] nums, int target) {
        int n = nums.length;
        int left = 0;
        int right = n - 1;
        while (right > left && nums[left] == nums[right]) {
            right--;
        }
        while (left < right) {
            // System.out.println(left + " " + right);
            int mid = (right + left + 1) >> 1;
            if (nums[mid] >= nums[0]) {
                left = mid;
            } else {
                right = mid - 1;
            }
            // System.out.println(nums[left] + " " + nums[right]);
            // System.out.println(left + " " + right);
        }
        // System.out.println(left);
        if (target > nums[left] || target < nums[(left + 1) % n]) {
            return false;
        }
        if (target >= nums[0]) {
            left = 0;
        } else {
            right = n - 1;
            left++;
        }
        while (left < right) {
            int mid = (right + left) >> 1;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[left] == target;
    }
}
// @lc code=end
