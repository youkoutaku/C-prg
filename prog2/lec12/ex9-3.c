/*------------------------------------------------------------------*/
/*      		<ex9-3.c> 2�����z��̓��I�m�ۇA	  	    			*/
/*�@�@�@�@�s���Ɨ񐔂��ς̂Q�����z��𓮓I�Ɋm�ہicalloc�g�p)�@�@ */
/*-----------------------------------------------------------------	*/
#include <stdio.h>
#include <stdlib.h>	//for exit() calloc()

void Matrix_free(int **p, int num);

int main(void)
{
	int 	i,j,	//�J�E���^
			m,		//�s��
			n,		//��
			**pt;   //�|�C���^�ւ̃|�C���^

	printf("�s��:");	scanf("%d",&m);
	printf("��:");	scanf("%d",&n);

	pt=(int **)calloc(m, sizeof(int *));//�v�f����m��int�^�ւ̃|�C���^�z��̊m��
	if(pt==NULL){					//�G���[����
		printf("�L���̈�̊m�ۂɎ��s���܂���\n");
		exit(1);
	}

	for(i=0;i<m;i++)	pt[i]=NULL;	//�|�C���^�z��pt�̑S�v�f��NULL����
		
	for(i=0;i<m;i++){
		pt[i]=(int *)calloc(n,sizeof(int)); //�v�f����n��int�^�̔z����m�ۂ��C�m�ۂ����z��ւ̃|�C���^�� pt[i] �ɑ��
		if(pt[i]==NULL){
			printf("�L���̈�̊m�ۂɎ��s���܂���\n");
			exit(0);
		}
	}

	for(i=0;i<m;i++)		//i,j�v�f��(i+1)*10+(j+1)����
		for(j=0;j<n;j++)	pt[i][j]=(i+1)*10+(j+1);			          

	for(i=0;i<m;i++){		//�S�v�f�̒l��\��
		for(j=0;j<n;j++)	printf("%d ",pt[i][j]);
		printf("\n");
	}

	Matrix_free(pt,m);		//�m�ۂ��Ă����̈�̊J��
	
	return 0;
}

//�m�ۂ����S�̈�̊J��
void Matrix_free(int **p, int num)
{
	int i;
	
	for(i=0;i<num;i++)	free(p[i]);
	free(p);
}
