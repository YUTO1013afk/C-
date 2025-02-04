#include <stdio.h>

//union book {
//    char name[16];
//    int price;
//};
//
//int main(void) {
//    union book bk = { "桃太郎" }; // 宣言と初期化
//    printf("本の名前は%sです\n", bk.name);
//    printf("共用体のサイズは%dバイトです\n", sizeof(bk));
//
//    bk.price = 500; // 別のメンバへの値の代入
//    printf("本の名前は%sです\n", bk.name);
//    printf("本の価格は%d円です\n", bk.price);
//
//    return 0;
//}