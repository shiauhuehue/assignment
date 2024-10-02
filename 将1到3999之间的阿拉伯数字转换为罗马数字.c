#include <stdio.h>    
#include <string.h>    
    
char* intToRoman(int num) {    
    const char* c[4][10] = {    
        {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},    
        {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},    
        {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},    
        {"", "M", "MM", "MMM"}    
    };    
    char roman[20]; // 分配足够的空间来存储罗马数字。    
    strcpy(roman, c[3][num / 1000 % 10]);    
    strcat(roman, c[2][num / 100 % 10]);    
    strcat(roman, c[1][num / 10 % 10]);    
    strcat(roman, c[0][num % 10]);    
        
    return strdup(roman); // 使用 strdup 复制 roman 字符串，因为 roman 是一个局部变量。    
}    
    
int main() {    
    int num;    
    printf("请输入阿拉伯数字（1-3999）：");    
    scanf("%d", &num);    
        
    if (num < 1 || num > 3999) {    
        printf("输入的数字超出了允许的范围。\n");    
        return 1;    
    }    
        
    char* roman = intToRoman(num);    
    printf("阿拉伯数字 %d 对应的罗马数字是：%s\n", num, roman);    
    free(roman); // 释放 strdup 分配的内存。    
        
    return 0;    
}