/*------------------------------------------------------------------*/
/*      		 				 <ex7-2a.c>							*/
/*�@�@�@�@�@�@�@����n�̊K������߂�v���O�����i�ċA�R�[���j�@�@�@�@	*/
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
	if(n==1)					//n��1�̏ꍇ
		return 1;				//1��Ԃ�
	else						//n���P�łȂ��ꍇ
		return n*kaijyo(n-1);	//n*(n-1)�̊K���Ԃ�
}
