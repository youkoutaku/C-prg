/*------------------------------------------------------------------*/
/*      		 				 <7-2b.c>							*/
/*�@�@�@�@�@�@�@�@�@����n�̊K������߂�v���O�����@�@�@�@�@�@�@�@�@	*/
/*                        for���g�p									*/
/*-----------------------------------------------------------------	*/
#include <stdio.h>

//�֐��̃v���g�^�C�v�錾
int kaijyo(int n);

int main(void)
{
	int num;
	
	printf("��������͂��Ă��������F");
	scanf("%d",&num);

	printf("%d�̊K���%d�ł�\n",num,kaijyo(num));

	return 0;
}

int kaijyo(int n)
{
	int i,value=1;

	for(i=n;i>0;i--){
		value*=i;
	}
	
	return value;
}