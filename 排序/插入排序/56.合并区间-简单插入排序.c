/*
 * @lc app=leetcode.cn id=56 lang=c
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (44.04%)
 * Likes:    769
 * Dislikes: 0
 * Total Accepted:    182K
 * Total Submissions: 413.2K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 给出一个区间的集合，请合并所有重叠的区间。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: intervals = [[1,3],[2,6],[8,10],[15,18]]
 * 输出: [[1,6],[8,10],[15,18]]
 * 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2:
 * 
 * 输入: intervals = [[1,4],[4,5]]
 * 输出: [[1,5]]
 * 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 * 注意：输入类型已于2019年4月15日更改。 请重置默认代码定义以获取新方法签名。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * intervals[i][0] <= intervals[i][1]
 * 
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(int **i, int **j){
    return (*i)[0]-(*j)[0];
}

void simple_insert_sort(int **intervals, int size){
    int i;
    for(i=1;i<size;i++){
        if(cmp(&intervals[i],&intervals[i-1])<0){
            int j;
            int *tmp = intervals[i];
            for(j=i;j>0 && cmp(&intervals[j-1], &tmp)>0;j--){
                intervals[j] = intervals[j-1];
            }
            intervals[j] = tmp;
        }
    }
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int **returned = (int**)malloc(sizeof(int*)*intervalsSize);
    int i;
    int start = 0;
    int max_up;
    
    simple_insert_sort(intervals, intervalsSize);

    max_up = intervals[0][1];
    (*returnSize) = 0;
    for(i=1;i<intervalsSize;i++){
        if(intervals[i][0]>max_up){
            returned[(*returnSize)] = (int*)malloc(sizeof(int)*2);
            returned[(*returnSize)][0] = intervals[start][0];
            returned[(*returnSize)++][1] = max_up;
            start = i;
            max_up = intervals[i][1];
        }else {
            max_up = max_up<intervals[i][1]?intervals[i][1]:max_up;
        }
    }
    returned[(*returnSize)] = (int*)malloc(sizeof(int)*2);
    returned[(*returnSize)][0] = intervals[start][0];
    returned[(*returnSize)++][1] = max_up;

    (*returnColumnSizes) = (int*)malloc(sizeof(int)*(*returnSize));
    for(i=0;i<(*returnSize);i++){
        (*returnColumnSizes)[i] = 2;
    }
    return returned;
}
// @lc code=end

