# C语言

## **取(拷贝)字符串子串** 
   
例题:[131分割回文串](../../其他技巧/回溯算法/131.分割回文串.c)，取字符串`s`在`i`到`j`(包含)之间的子串为`sub`。

```C
char* sub = malloc(sizeof(char) * (j - i + 2));
for (int k = i; k <= j; k++) {
    sub[k - i] = s[k];
}
sub[j - i + 1] = '\0';
```
- `malloc`申请,长度多留一位,如:
      
  ```C
  char* sub = malloc(sizeof(char) * (j - i + 2));
  ```
- 逐位复制
- 最后一位加`'\0'`：
  ```C
  ub[j - i + 1] = '\0';
  ```
## 数组参数函数调用
**静态声明多维数组**，形参列表中要声明每一维度长度
```C
void func(int a[10][5][4]);
```

第一维可以省略。
```C
void func(int a[][5][4]);
// 不正确的：
// void func(int a[10][][4]);
// void func(int a[][][4]);
```

**单维数组**时可以省略：
```C
void func(int a[4]);
void func(int a[]);
```
**动态声明数组**使用指针做形参：
```C
int **aa = (int**)malloc(sizeof(int*)*2);
aa[0] = (int*)malloc(sizeof(int)*2);
aa[1] = (int*)malloc(sizeof(int)*3); // aa[0]和aa[1]长度可以不一样
int func(int **a, int aSize, int *aColSize);
```