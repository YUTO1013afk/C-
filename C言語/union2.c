#include <stdio.h>

//union book {
//    char name[16];
//    int price;
//};
//
//int main(void) {
//    union book bk = {"�����Y"}; // �錾�Ə�����
//    printf("�{�̖��O��%s�ł�\n", bk.name);
//
//    union book *p; // ���p�̂̃|�C���^�̐錾
//    p = &bk; // �|�C���^��union�^�̕ϐ��̃A�h���X����
//    p->price = 500; // �|�C���^���g���ĕʂ̃����o�ւ̒l�̑��
//    printf("�{�̉��i��%d�~�ł�\n", p->price);
//
//    return 0;
//}