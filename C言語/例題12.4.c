#include <stdio.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
//typedef struct{ /* �\���̐錾 */
//	double x;  /* x���W */
//	double y;  /* y���W */
//}point;
//double kyori(point p[2]);
//int main(void)
//{
//	int i;
//	double d;
//	point p[2];
//	for (i = 0; i < 2; i++) { /* �f�[�^�̓��� */
//		printf("x%d = ", i);
//		scanf_s("%lf", &p[i].x);
//		printf("y%d = ", i);
//		scanf_s("%lf", &p[i].y);
//	}
//	d = kyori(p);
//	printf("kyori = %f\n", d);
//	return 0;
//
//double kyori(point p[2]) /* �\���̈��� */
//{
//	double seki, nagasa;
//	seki = (p[1].x - p[0].x) * (p[1].x - p[0].x) + (p[1].y - p[0].y) * (p[1].y - p[0].y);
//	nagasa = sqrt(seki);
//	return nagasa;
//}