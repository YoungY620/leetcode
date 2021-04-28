/*
 * @lc app=leetcode.cn id=76 lang=c
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode-cn.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (40.26%)
 * Likes:    964
 * Dislikes: 0
 * Total Accepted:    110.3K
 * Total Submissions: 270.7K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
 * 
 * 注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "a", t = "a"
 * 输出："a"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 和 t 由英文字母组成
 * 
 * 
 * 
 * 进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？
 */

// @lc code=start


char * minWindow(char * s, char * t){
    int left = 0;
    int right = 0;
    int texist['z'-'A'+1] = {0};
    int sexist['z'-'A'+1] = {0};
    int tlen = strlen(t);
    char *ans;
    int anslen = strlen(s);
    int cvrcntr = 0;
    int i;

    ans = (char*)malloc(sizeof(char)*(strlen(s)+1));
    strcpy(ans, s);

    for(i=0;t[i]!='\0';i++){
        texist[t[i]-'A']++;        
    }

    while(s[right]!='\0'){
        sexist[s[right]-'A']++;
        if(texist[s[right]-'A'] >= sexist[s[right]-'A']){
            cvrcntr++;
        }
        right++;
        while(left<right && texist[s[left]-'A']<sexist[s[left]-'A']){
            sexist[s[left]-'A']--;
            left++;
        }
        if(cvrcntr == tlen && right-left<anslen){
            strncpy(ans, s+left,right);
            ans[right-left] = '\0';
            anslen = right-left;
        }
    }
    
    return cvrcntr<tlen?"":ans;
}

// @lc code=end

