/*------------------------------------------------------------------*/
/*      		 			<ex8-4.c>			  	    			*/
/*�@�@�@�Q�����z��Ɣz��ւ̃|�C���^(�������}�b�v�̕\���j �@�@�@�@�@*/
/*-----------------------------------------------------------------	*/
#include <stdio.h>

int main(void)
{
	char 	a[3][7]={"red","blue", "yellow"}; 	//�Q�����z��̐錾�Ə�����
	char	(*d)[7];							//�z��ւ̃|�C���^�̐錾
	int 	i;

	d=a;	//�z��ւ̃|�C���^d�Ɂu�Q�����z��a�v�̐擪�A�h���X����

	//�z��a�̐擪�A�h���X�ƃT�C�Y�̕\��
	printf("\na=%p sizeof(a)=%d\n",a,sizeof(a));
	//a[i]�̃A�h���X�Aa[i]���w���A�h���X�Ca[i]���w���z��̓��e�\��
	for(i=0;i<3;i++)
		printf("&a[%d]=%p a[%d]=%p %s\n",i,&a[i],i,a[i],a[i]);

	//�z��ւ̃|�C���^d�̃A�h���X�Ad���w���A�h���X�A�T�C�Y�̕\��
	printf("\n&d=%p d=%p sizeof(d)=%d\n",&d,d,sizeof(d));
	//d[i]�̃A�h���X�Ad[i]���w���A�h���X�Cd[i]���w���z��̓��e�\��
	for(i=0;i<3;i++)
		printf("&d[%d]=%p d[%d]=%p %s\n",i,&d[i],i,d[i],d[i]);	

    return 0;
}
