#include <stdio.h>

 // �r�b�g�t�B�[���h�̐錾�ƃ����o�̏�����
//struct bits {
//    unsigned char b1 : 1; // �����o�̏�����
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
//    printf("u.chr�̒l��%d�ł�\n", u.chr);
//    printf("u.chr�̃r�b�g�\����%d%d%d%d%d%d%d%d�ł�\n",
//        u.b.b1, u.b.b2, u.b.b3, u.b.b4, u.b.b5, u.b.b6, u.b.b7, u.b.b8);
//    printf("u�̃T�C�Y��%ld�o�C�g�ł�\n", sizeof(u));
//
//    return 0;
//}