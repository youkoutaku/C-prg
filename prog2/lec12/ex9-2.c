/*------------------------------------------------------------------*/
/*      		 	<ex9-2.c>  2�����z��̓��I�m�ۇ@    			*/
/*�@�@�@�@�@�񐔂��萔��int�^�̂Q�����z��𓮓I�Ɋm�ہicalloc�g�p)  */
/*-----------------------------------------------------------------	*/
#include <stdio.h>
#include <stdlib.h>	//for exit() calloc()

int main(void)
{
	int 	i,j,	//�J�E���^
			m,		//�s��
			(*pt)[3];	//�񐔂͒萔�i�����ł͂R�j

	printf("�s��:");
	scanf("%d",&m);

	pt=(int (*)[3])calloc(m*3, sizeof(int));	//int�^��m*3���I�Ɋm��
	if(pt==NULL){								//�G���[����
		printf("�L���̈�̊m�ۂɎ��s���܂���\n");
		exit(1);
	}
		
	for(i=0;i<m;i++)		//i,j�v�f��(i+1)*10+(j+1)����
		for(j=0;j<3;j++)	pt[i][j]=(i+1)*10+(j+1);

	for(i=0;i<m;i++){		//�S�v�f�̒l��\��
		for(j=0;j<3;j++)	printf("%d ", pt[i][j]);
		printf("\n");
	}

	free(pt);	//�m�ۂ��Ă����̈�̊J��
	
	return 0;
}
