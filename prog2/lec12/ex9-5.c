/*------------------------------------------------------------------*/
/*      		  <ex9-5.c> 2�����z��̓��I�m�ۇC  	    		*/
/*�@�@1�����z��𓮓I�Ɋm�ۂ��āA2�����z��Ƃ��Ĉ����icalloc�g�p)�@ */
/*-----------------------------------------------------------------	*/
#include <stdio.h>
#include <stdlib.h>	//for exit() calloc()

int main(void)
{
	int 	i,j,	//�J�E���^
			m,		//�s��
			n,		//��
			*p;   	//�|�C���^

	printf("�s��:");	scanf("%d",&m);
	printf("��:");	scanf("%d",&n);

	p=(int *)calloc(m*n, sizeof(int));	//int�^��m*n�m��
	if(p==NULL){					//�G���[����
		printf("�L���̈�̊m�ۂɎ��s���܂���\n");
		exit(1);
	}

	for(i=0;i<m;i++)			//i,j�v�f��(i+1)*10+(j+1)����
		for(j=0;j<n;j++)	p[i*n+j]=(i+1)*10+(j+1);			          

	for(i=0;i<m;i++){			//�S�v�f�̒l��\��
		for(j=0;j<n;j++)	printf("%d ",p[i*n+j]);
		printf("\n");
	}

	free(p);		//�m�ۂ��Ă����̈�̊J��
	
	return 0;
}