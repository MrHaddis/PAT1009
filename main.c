#include <stdio.h>
//MrHaddis

int main() {
    //定义一个二维数组 其实不用定义到80 80  定义个80 10 的就够用了
    char input[80][80] = {};
    char str;
    //这个记录的是二维的下标
    int index = 0;
    //这个记录的是单次的个数一维的下标
    int number = 0;
    while ((str = getchar()) != '\n') {
        //这里获取到的空格是ASCII中的32
        if (str != ' ') {
            input[number][index++] = str;
        } else {
            //取到空格的时候需要把一维的下标+1,
            //需要把二维的下标归0
            number++;
            index = 0;
        }
    }
    //对数组进行遍历
    //要倒序输出
    for (int j = number; j >= 0; j--) {
        for (int i = 0; i < 80; ++i) {
            //这里为什么是和 NULL 比较而不是' '比较
            //因为存在数组的时候 这个没存的位置，取值的时候就变成 NULL 了
            //所以是和 NULL 对比，不是NULL的就输出
            if (input[j][i] != NULL) {
                printf("%c", input[j][i]);
            }
        }
        //输出空格
        //在最后一个时不用输出
        if (j > 0) {
            printf(" ");
        }
    }
    return 0;
}
