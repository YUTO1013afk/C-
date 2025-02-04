#include <stdio.h>

 // ビットフィールドの宣言とメンバの初期化
//struct bits {
//    unsigned char b1 : 1; // メンバの初期化
//    unsigned char b2 : 1;
//    unsigned char b3 : 1;
//    unsigned char b4 : 1;
//    unsigned char b5 : 1;
//    unsigned char b6 : 1;
//    unsigned char b7 : 1;
//    unsigned char b8 : 1;
//    //unsigned char b9 : 1;
//};
//
//union {
//    unsigned char chr;
//    struct bits b;
//} u;
//
//int main(void) {
//    u.chr = 0xab;//255;
//    u.b.b1 = 0;
//    u.b.b1 = 1;
//    printf("u.chrの値は%dです\n", u.chr);
//    printf("u.chrのビット表示は%d%d%d%d%d%d%d%dです\n",
//        u.b.b1, u.b.b2, u.b.b3, u.b.b4, u.b.b5, u.b.b6, u.b.b7, u.b.b8);
//    printf("uのサイズは%ldバイトです\n", sizeof(u));
//
//    return 0;
//}