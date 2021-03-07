/*
 * @lc app=leetcode.cn id=131 lang=c
 *
 * [131] 分割回文串
 *
 * https://leetcode-cn.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (70.42%)
 * Likes:    586
 * Dislikes: 0
 * Total Accepted:    79.3K
 * Total Submissions: 110.1K
 * Testcase Example:  '"aab"'
 *
 * 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
 * 
 * 返回 s 所有可能的分割方案。
 * 
 * 示例:
 * 
 * 输入: "aab"
 * 输出:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 * 
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int tab = 0;
void printtab(){
    int i;
    for(i=0;i<tab;i++){
        printf("    ");
    }
}
void dfs(char *s, int slen, char **path, int pathlen, int i,\
        char ***res, int * returnSize, int ** returnColumnSizes, int dp[16][16]){
    int j;
    if(i == slen){
        res[(*returnSize)] = (char**)malloc(sizeof(char*)*pathlen);
        for(j = 0;j<pathlen;j++){
            res[(*returnSize)][j] = (char*)malloc(sizeof(char)*(strlen(path[j])+1));//!!
            strcpy(res[(*returnSize)][j], path[j]);
        }
        (*returnColumnSizes)[(*returnSize)++] = pathlen;
    }
    for(j=i;j<slen;j++){
        if(dp[i][j] == 1){
            // printtab();
            // printf("%d %d %d 123\n",i,j,slen);

            path[pathlen] = (char*)malloc(sizeof(char)*(j-i+2));
            int p;
            for(p=i;p<=j;p++){
                path[pathlen][p-i]=s[p];
            }
            path[pathlen][j-i+1] = '\0';
            // printtab();
            // printf("%s\n", path[pathlen]);
            // tab++;
            dfs(s,slen,path, pathlen+1, j+1, res, returnSize, returnColumnSizes, dp);
            // tab--;
            free(path[pathlen]);
        }
    }
}

char *** partition(char * s, int* returnSize, int** returnColumnSizes){
    int n = strlen(s);
    int dp[16][16] = {0};
    int i;
    for(i=0;i<n;i++){
        dp[i][i] = 1;
    }
    for(i=0;i<n-1;i++){
        if(s[i] == s[i+1]) dp[i][i+1] = 1;
        else dp[i][i+1] = 0;
    }
    for(i=2;i<n;i++){
        int j;
        for(j=0;j<n-i;j++){
            dp[j][j+i] = dp[j+1][j+i-1] && (s[j] == s[j+i]);
        }
    }
    char ***res;
    int maxResSize = n*(1<<n);
    res = (char***)malloc(sizeof(char**)*maxResSize);
    (*returnSize) = 0;
    (*returnColumnSizes) = (int*)malloc(sizeof(int)*maxResSize);
    char** path = (char**)malloc(sizeof(char*)*n);
    int pathlen = 0;
    dfs(s, n, path, pathlen, 0, res, returnSize, returnColumnSizes, dp);
    return res;
}
// @lc code=end

