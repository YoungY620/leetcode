/*
 * @lc app=leetcode.cn id=208 lang=c
 *
 * [208] 实现 Trie (前缀树)
 *
 * https://leetcode-cn.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (69.59%)
 * Likes:    507
 * Dislikes: 0
 * Total Accepted:    69.4K
 * Total Submissions: 99.7K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * 实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
 * 
 * 示例:
 * 
 * Trie trie = new Trie();
 * 
 * trie.insert("apple");
 * trie.search("apple");   // 返回 true
 * trie.search("app");     // 返回 false
 * trie.startsWith("app"); // 返回 true
 * trie.insert("app");   
 * trie.search("app");     // 返回 true
 * 
 * 说明:
 * 
 * 
 * 你可以假设所有的输入都是由小写字母 a-z 构成的。
 * 保证所有输入均为非空字符串。
 * 
 * 
 */

// @lc code=start

typedef struct Trie {
    struct Trie *kids[26];
    bool is_end;
} Trie;

/** Initialize your data structure here. */

Trie* trieCreate() {
    Trie *obj = malloc(sizeof(Trie));
    obj->is_end = false;
    memset(obj->kids, 0, sizeof(obj->kids));
    return obj; 
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    int n = strlen(word);
    int i;
    for(i=0;i<n;i++){
        if(obj->kids[word[i]-'a'] == NULL){
            obj->kids[word[i]-'a'] = trieCreate();
        }
        obj = obj->kids[word[i]-'a'];
    }
    obj->is_end = true;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    int n = strlen(word);
    int i;
    for(i=0;i<n;i++){
        if(obj->kids[word[i]-'a'] == NULL){
            return false;
        }
        obj = obj->kids[word[i]-'a'];
    }
    return obj->is_end;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * word) {
    int n = strlen(word);
    int i;
    for(i=0;i<n;i++){
        if(obj->kids[word[i]-'a'] == NULL){
            return false;
        }
        obj = obj->kids[word[i]-'a'];
    }
    return true;
}

void trieFree(Trie* obj) {
    int i;
    for(i=0;i<26;i++){
        if(obj->kids[i] != NULL){
            trieFree(obj->kids[i]);
        }
    }
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/
// @lc code=end

