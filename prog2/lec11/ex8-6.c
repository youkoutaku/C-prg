/*------------------------------------------------------------------*/
/*      		 			<ex8-6.c>			  	    			*/
/*�@�@�@�|�C���^�z��ƃ|�C���^�ւ̃|�C���^�i�������}�b�v�̕\���j�@�@*/
/*-----------------------------------------------------------------	*/
#include <stdio.h>

int main(void)
{
	char    *b[3]={"red","blue", "yellow"};	//�|�C���^�z��̐錾�Ə�����
	char	**c;							//�|�C���^�̃|�C���^�̐錾
	int 	i;								//�J�E���^

	c=b;	//�|�C���^�̃|�C���^c�Ɂu�|�C���^�z�� b�v�̐擪�A�h���X����
	
	//�z��b�̐擪�A�h���X�ƃT�C�Y�̕\��
	printf("\nb=%p sizeof(b)=%d\n",b,sizeof(b));

	//b[i]�̃A�h���X�Ab[i]���w�������A�h���X�Ab[i]���w�������z��̓��e�\��
	for(i=0;i<3;i++)
		printf("&b[%d]=%p b[%d]=%p %s\n",i,&b[i],i,b[i],b[i]);	

	//�|�C���^�̃|�C���^c�̃A�h���X�Ac���w�������A�h���X�Ac�̃T�C�Y�̕\��
	printf("\n&c=%p c=%p sizeof(c)=%d\n",&c, c, sizeof(c));

	//c[i]�̃A�h���X�Ac[i]���w�������A�h���X�Ac[i]�����������z��̓��e�\��
	for(i=0;i<3;i++)
		printf("&c[%d]=%p c[%d]=%p %s\n",i,&c[i],i,c[i],c[i]);	

	return 0;

}