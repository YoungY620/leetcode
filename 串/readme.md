# 串

## KMP

- 预定义
  - 模式串 `p`
  - 匹配串 `s`
  - 问题: 在 `s` 中找 `p` 出现的首坐标
  - `next` 数组: 
    - `next[i] = j` 表示 `p[i]` 失配时, `p` 上的指针赋值为 `j` 继续匹配
    - 即, **`p` 上, `i` 之前的前缀, 与 `j` 之前子串等长的后缀完全相同 (不包括 `p[i]`, `p[j]`)**
- **next数组**

    ```c
    void get_next(int next[], char* p, int pl){
        int i=0;            // i 表示, 失配位的前一位
        int j=-1;           // j 表示, 失配后跳转位置的前一位
        next[i] = -1;       // 默认, 第一位失配时的特殊标记
        while(i<pl-1){      
            if(j == -1 || p[i] == p[j]){
                            // 第一位(上一个循环j==0时)
                            // 就失配, 或这一位相等
                j++;        // 注意:是将i的下一位的next值
                i++;        //      赋值为j的下一位
                next[i] = j;
            }else{
                j = next[j];
            }
        }
    }
    ```

- 匹配

    ```c
    int strStr(char * s, char * p){
        int pl = strlen(p);
        int sl = strlen(s);
        if(pl == 0){return 0;}
        else if(sl == 0){return -1;}
        
        int next[pl];
        get_next(next, p, pl);

        int si = 0, pi = 0;     // 从第一位开始遍历
        while(si < sl && pi < pl){  
            if(pi == -1 || p[pi] == s[si]){
                pi++; si++;     // 第一位失配(上一轮循环)或匹配
            }else{
                pi = next[pi];
            }
        }
        if(pi == pl){
            return si-pl;
        }
        return -1;
    }
    ```