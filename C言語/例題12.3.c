#include <stdio.h>
//typedef struct{	/* �\���̐錾 */
//	int rank;
//	char *country;
//	double point;
//}ranking;
//
//int main(void)
//{
//	int i;
//	ranking s[3]; /* �ϐ��錾 */
//	s->rank = 8;		/* �Ԑڃ����o���Z�q�ɂ��\�� */
//	s->country = "Yugoslavia";
//	s->point = 59.36;
//	(s+1)->rank = 14;
//	(s+1)->country = "Italy";
//	(s+1)->point = 56.71;
//	(s+2)->rank = 17;
//	(s+2)->country = "France";
//	(s+2)->point = 56.08;
//	for(i = 0; i < 3; i++) {
//		printf("rank=%d, country=%s, point=%f\n",
//		(s+i)->rank, (s+i)->country, (s+i)->point);
//	}
//	return 0;
//}