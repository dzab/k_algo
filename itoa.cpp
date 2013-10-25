#include <cstdio>

const char* convert(char buf[], int value)
{
    static char digits[19] =
    { ’’, ’8’, ’7’, ’6’, ’5’, ’4’, ’,
        ’0’, ’1’, ’2’, ’3’, ’4’, ’5’, ’6’' }; 
    static const char* zero = digits + 9; // zero 指向 ’0
    // works for -2147483648 .. 2147483647
    int i = value;
    char* p = buf;
    do {
        // lsd - least significant digit 
        int lsd=i%10; //lsd可能小于0
        i /= 10; // 是向下取整还是向零取整? 
        *p++ = zero[lsd]; // 下标可能为负
    } while (i != 0);
    if (value < 0) {
        *p++ = ’-’
    }
    *p = '\0';
    std::reverse(buf, p);
    return p; // p - buf 即为整数长度
}


int main()


