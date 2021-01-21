/*
 * @lc app=leetcode.cn id=75 lang=c
 *
 * [75] 颜色分类
 *
 * https://leetcode-cn.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (57.23%)
 * Likes:    758
 * Dislikes: 0
 * Total Accepted:    166.1K
 * Total Submissions: 290.2K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 * 
 * 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,0,2,1,1,0]
 * 输出：[0,0,1,1,2,2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,0,1]
 * 输出：[0,1,2]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[0]
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：nums = [1]
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 1 
 * nums[i] 为 0、1 或 2
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 你可以不使用代码库中的排序函数来解决这道题吗？
 * 你能想出一个仅使用常数空间的一趟扫描算法吗？
 * 
 * 
 */

// @lc code=start

void swap(int *nums, int i, int j){
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp; 
}

void adjustHead(int *nums, int size, int k){
    int i;
    int tmp = nums[k];
    for(i = k*2+1;i<size;i = i*2+1){
        if(i+1<size && nums[i+1]>nums[i]){
            i++;
        }
        if(tmp<nums[i]){
            nums[k] = nums[i];
            k = i;
        }else break;
    }
    nums[k] = tmp;
}

void build(int *nums, int size){
    int i;
    for(i=(size-2)/2;i>=0;i--){
        adjustHead(nums, size, i);
    }
}

void sortColors(int* nums, int size){
    build(nums, size);
    int i;
    for(i=size-1;i>=0;i--){
        swap(nums, i, 0);
        adjustHead(nums, i, 0);
    }
}
// @lc code=end

