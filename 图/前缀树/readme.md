# 前缀树

不难, 主要是要知道

例如对于英文单词的前缀树:

- 粒度: 每个字母作为节点
- 每个节点标记是否为一个单词的结尾
- 即可

模板题: [实现前缀树](208.实现-trie-前缀树.c)

```C
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
```