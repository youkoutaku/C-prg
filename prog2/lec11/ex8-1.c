//     <ex8-1.c>
//�|�C���^�ϐ����I�u�W�F�N�g�̃A�h���X��������ϐ��ł��邱�Ƃ�
//�m�F����v���O����

#include <stdio.h>

int main(void)
{
	int x=100;
	int *p;

	p=&x;
	
	printf("x�̃A�h���X    �F%p\n",&x);
	printf("x�̒l          �F%d\n",x);

	printf("p�̃A�h���X�@�@�F%p\n",&p);
	printf("p���w���A�h���X�F%p\n",p);
	printf("p���w���A�h���X�Ɋi�[����Ă���l�F%d\n",*p);

	return 0;
}