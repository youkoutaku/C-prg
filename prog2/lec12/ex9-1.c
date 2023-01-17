/*------------------------------------------------------------------*/
/*      		 			 <ex9-1.c>			  	    			*/
/*�@�@�@�@�@�@int�^�̈ꎟ���z��𓮓I�Ɋm��              �@�@�@�@�@ */
/*-----------------------------------------------------------------	*/
#include <stdio.h>
#include <stdlib.h>	//for exit() calloc()

int main(void)
{
	int 	i,			//�J�E���^
			num,		//�z��̗v�f��
			*pm, *pc;   //�m�ۂ���̈���w�����߂̃|�C���^

	printf("�m�ۂ���z��̗v�f��:");
	scanf("%d",&num);

	pc=(int *)calloc(num, sizeof(int));	//int�^��num���I�Ɋm��
	if(pc==NULL){						//�G���[����
		printf("�z��pc�̗̈�̊m�ۂɎ��s���܂���\n");
		exit(1);
	}
	
	pm=(int *)malloc(num*sizeof(int));	//int�^��num���I�Ɋm��
	if(pm==NULL){						//�G���[����
		printf("�z��pm�̗̈�̊m�ۂɎ��s���܂���\n");
		exit(1);
	}
	
	for(i=0;i<num;i++)	printf("pc[%d]=%d\n",i,pc[i]);//�z��pc�̑S�v�f�̒l��\��
	for(i=0;i<num;i++)	printf("pm[%d]=%d\n",i,pm[i]);//�z��pm�̑S�v�f�̒l��\��

	free(pc);		//�z��pc�p�Ɋm�ۂ��Ă����̈�̊J��
	free(pm);		//�z��pm�p�Ɋm�ۂ��Ă����̈�̊J��
	
	return 0;
}
