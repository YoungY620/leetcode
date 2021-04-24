/*
 * @lc app=leetcode.cn id=28 lang=c
 *
 * [28] 实现 strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (39.77%)
 * Likes:    874
 * Dislikes: 0
 * Total Accepted:    373.8K
 * Total Submissions: 920.3K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 实现 strStr() 函数。
 * 
 * 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0
 * 开始）。如果不存在，则返回  -1 。
 * 
 * 
 * 
 * 说明：
 * 
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf()
 * 定义相符。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：haystack = "hello", needle = "ll"
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：haystack = "aaaaa", needle = "bba"
 * 输出：-1
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：haystack = "", needle = ""
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * haystack 和 needle 仅由小写英文字符组成
 * 
 * 
 */

// @lc code=start


void get_next(int next[], char* p, int pl){
    int i=0;
    int j=-1;
    next[0] = -1;
    // printf("123\n");
    while(i<pl-1){
        // printf("%d %d  %d\n", i, j, pl);
        if(j == -1 || p[i] == p[j]){
            j++;
            i++;
            next[i] = j;
        }else{
            j = next[j];
        }
    }
}

int strStr(char * s, char * p){
    int pl = strlen(p);
    int sl = strlen(s);
    if(pl == 0){
        return 0;
    }else if(sl == 0){
        return -1;
    }
    int next[pl];
    get_next(next, p, pl);

    // printf("123\n");
    int si = 0, pi = 0;
    while(si < sl && pi < pl){
        if(pi == -1 || p[pi] == s[si]){
            pi++; si++;
        }else{
            pi = next[pi];
        }
    }
    // printf("123\n");
    if(pi == pl){
        return si-pl;
    }
    return -1;
}

// @lc code=end

