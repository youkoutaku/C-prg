/*------------------------------------------------------------------*/
/*      		 		  	  <ex11-2.c>	  		  				*/
/*�@�@�@�@�@�@�@�֐��`���}�N���̗�(#���Z�q��##���Z�q�j�@�@�@�@�@�@�@*/
/*                       �@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@ */
/*-----------------------------------------------------------------	*/
#include <stdio.h>

#define mctst0(dt) "������dt�ł�"
#define mctst1(dt) "������" #dt "�ł�"

#define mctst2(dt) my##dt##size

#define dataout(dt) printf(#dt "=%d\n",dt)

int main(void)
{
	int dt=1,sum=0,ary[3]={10,20,30};
	int myHsize=170,myFsize=25;

	// #���Z�q-�����̕�����
	printf(mctst0(aaa)); printf("\n");
	printf(mctst1(aaa)); printf("\n");

	dataout(sum);
	dataout(ary[0]);
	dataout(dt+10);

	// ##���Z�q-�g�[�N���̌���
	dataout(mctst2(H));
	dataout(mctst2(F));

	return 0;
}