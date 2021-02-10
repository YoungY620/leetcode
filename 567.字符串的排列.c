/*
 * @lc app=leetcode.cn id=567 lang=c
 *
 * [567] 字符串的排列
 *
 * https://leetcode-cn.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (38.31%)
 * Likes:    257
 * Dislikes: 0
 * Total Accepted:    59.7K
 * Total Submissions: 150.6K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
 * 
 * 换句话说，第一个字符串的排列之一是第二个字符串的子串。
 * 
 * 示例1:
 * 
 * 
 * 输入: s1 = "ab" s2 = "eidbaooo"
 * 输出: True
 * 解释: s2 包含 s1 的排列之一 ("ba").
 * 
 * 
 * 
 * 
 * 示例2:
 * 
 * 
 * 输入: s1= "ab" s2 = "eidboaoo"
 * 输出: False
 * 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 输入的字符串只包含小写字母
 * 两个字符串的长度都在 [1, 10,000] 之间
 * 
 * 
 */

// @lc code=start

bool checkInclusion(char * s1, char * s2){
    int truthcnt[26];
    int rec[26];
    int left = 0;
    int right = 0;
    int s1_len = 0;
    int i;

    for(i=0;i<26;i++){
        truthcnt[i] = 0;
        rec[i] = 0;
    }
    for(s1_len=0;s1[s1_len]!='\0';truthcnt[s1[s1_len]-'a']++, s1_len++);

    while(s2[right]!='\0'){
        rec[s2[right]-'a']++;
        right++;
        while(rec[s2[right-1]-'a']>truthcnt[s2[right-1]-'a']){
            rec[s2[left]-'a']--;
            left++;
        }
        if(right-left==s1_len){
            return true;
        }
    }
    return false;
}

// @lc code=end

