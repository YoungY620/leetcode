#include<stdio.h>
/**
    深度优先的搜索，在每一天的每种情况中搜索下一天的所有情况
    没有用递归，栈是数组实现的
*/
void solve(int thred, int *least_dur, int *res){
    if(thred == 1){
        (*least_dur) = 0;
        return;
    }else if(thred == 0){
        (*least_dur) = -1;
        return;
    }
    
    int stack[(thred+1)*((thred+1)/2)][4];
    int stk_ptr = 0;
    int dayptr = 0;
    int day = 0;
    
    stack[stk_ptr][0] = 0;
    stack[stk_ptr][1] = 1;
    stack[stk_ptr][2] = 1;
    stack[stk_ptr++][3] = 0;
    stack[stk_ptr][0] = 0;
    stack[stk_ptr][1] = 1;
    stack[stk_ptr][2] = 1;
    stack[stk_ptr++][3] = 1;
    while(stk_ptr != 0){
        int bodies = stack[--stk_ptr][1];
        int power = stack[stk_ptr][2];
        int opt = stack[stk_ptr][3];
        day = stack[stk_ptr][0];
        
        bodies += opt;
        power += bodies;
        res[day++] = opt;
        if(power == thred){
            (*least_dur) = day;
            return;
        }else if(power > thred){
            continue;
        }
        
        for(opt=0;opt<=bodies;opt++){
            stack[stk_ptr][0] = day;
            stack[stk_ptr][1] = bodies;
            stack[stk_ptr][2] = power;
            stack[stk_ptr++][3] = opt;
        }
    }
}

int validate(int thred, int *opts, int optsize, int pred_day){
    int true_day = 0;
    int power = 1;
    int bodies = 1;
    for(true_day=0;true_day<optsize;true_day++){
        bodies += opts[true_day];
        power += bodies;
    }
    return (pred_day == true_day && power == thred);
}

int main(void) {
    int n;
    int returnsize;
    int *returned;
    int *res;
    
    while(EOF!=scanf("%d", &n)){
        int day;
        int i;
        res = (int *)malloc(sizeof(int)*n);
        solve(n, &day, res);
        printf("%d\n", day);
        if(day>0) printf("%d", res[0]);
        for(i=1;i<day;i++){
            printf(" %d", res[i]);
        }
        printf("\n");
        free(res);
    }
    return 0;
}