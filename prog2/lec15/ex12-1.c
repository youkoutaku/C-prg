/*------------------------------------------------------------------*/
/*      		 			�@<ex13-1.c> 					�@�@    */
/*             static�̕t�������[�J���ϐ����g�p�����v���O������		*/
/*------------------------------------------------------------------*/
#include <stdio.h>

int deposit(int mput);

int main(void)
{
	int money;
	
	do{
		printf("How much do you want to deposit?:"); scanf("%d", &money);
		printf("The saving amount is %d yen.\n", deposit(money));
	}while(money!=0);

	return 0;
}

int deposit(int mput)
{
	static int value=0;	//�����z�i�ÓI�ϐ��F�������͍ŏ��̌Ăяo���̂Ƃ������j

	value+=mput;
	return value;
}

