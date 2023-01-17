/*------------------------------------------------------------------*/
/*      		 			<ex8-2.c>			  	    			*/
/*�@�@�@�@�@�@�@�@�@ �@�@1�����z��ƃ|�C���^   �@�@�@�@�@�@�@�@�@�@ */
/*-----------------------------------------------------------------	*/
#include <stdio.h>

int main(void)
{
	int 	i;

	//�ꎟ���z��̐錾�Ə�����
	char 	a[4]="red"; 
	int		b[4]={100,101,102,103};
	double	c[4]={0.00,0.01,0.02,0.03};
		
	//�|�C���^�ϐ���錾���A1�����z��擪�A�h���X����
	char	*pa=a;
	int		*pb=b;
	double	*pc=c;

	//char�^�Aint�^�Adouble�^�̃o�C�g���\��
	printf("sizeof(char)=%d\n", sizeof(char));
	printf("sizeof(int)=%d\n", sizeof(int));
	printf("sizeof(double)=%d\n", sizeof(double));
	printf("-----------------------------\n");

	for(i=0;i<4;i++)	//pa+i�̃A�h���X��*(pa+i)���o��
		printf("pa+%d=%p \t *(pa+%d)=%c\n",i,pa+i,i,*(pa+i));
	printf("-----------------------------\n");

	for(i=0;i<4;i++)	//pb+i�̃A�h���X��*(pb+i)���o��
		printf("pb+%d=%p \t *(pb+%d)=%d\n",i,pb+i,i,*(pb+i));
	printf("-----------------------------\n");
		
	for(i=0;i<4;i++)	//pc+i�̃A�h���X��*(pc+i)���o��
		printf("pc+%d=%p \t *(pc+%d)=%.2f\n",i,pc+i,i,*(pc+i));


	return 0;
}
