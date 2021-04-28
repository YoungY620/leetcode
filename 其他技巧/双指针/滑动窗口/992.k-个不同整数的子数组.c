/*
 * @lc app=leetcode.cn id=992 lang=c
 *
 * [992] K 个不同整数的子数组
 *
 * https://leetcode-cn.com/problems/subarrays-with-k-different-integers/description/
 *
 * algorithms
 * Hard (32.82%)
 * Likes:    262
 * Dislikes: 0
 * Total Accepted:    18.9K
 * Total Submissions: 43K
 * Testcase Example:  '[1,2,1,2,3]\n2'
 *
 * 给定一个正整数数组 A，如果 A 的某个子数组中不同整数的个数恰好为 K，则称 A 的这个连续、不一定不同的子数组为好子数组。
 * 
 * （例如，[1,2,3,1,2] 中有 3 个不同的整数：1，2，以及 3。）
 * 
 * 返回 A 中好子数组的数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：A = [1,2,1,2,3], K = 2
 * 输出：7
 * 解释：恰好由 2 个不同整数组成的子数组：[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2],
 * [1,2,1,2].
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：A = [1,2,1,3,4], K = 3
 * 输出：3
 * 解释：恰好由 3 个不同整数组成的子数组：[1,2,1,3], [2,1,3], [1,3,4].
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 1 
 * 
 * 
 */

// @lc code=start

int func(int *A, int ASize, int K){
    int left = 0, right = 0;
    int rec[ASize+1];
    int i;
    int unique = 0;
    int ans = 0;

    for(i=0;i<ASize+1;i++){
        rec[i] = 0;
    }
    while(right<ASize){
        if(rec[A[right]] == 0){
            unique ++;
        }
        rec[A[right]]++;
        right++;
        while(unique>K){
            rec[A[left]]--;
            if(rec[A[left]] == 0){
                unique--;
            }
            left++;
        }
        ans += right-left;
    }
    return ans;
}

int subarraysWithKDistinct(int* A, int ASize, int K){
    return func(A, ASize, K)-func(A, ASize, K-1);
}

// @lc code=end

