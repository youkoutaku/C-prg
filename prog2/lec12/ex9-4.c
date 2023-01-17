/*------------------------------------------------------------------*/
/*      		 			 <ex9-4.c>			  	    			*/
/*                     2�����z��̓��I�m�ۇB�@�@�@�@�@�@�@�@�@�@�@�@*/
/*�@�@�@�@�@�s�ɂ���ė�̑傫���̈Ⴄ2�����z��𓮓I�Ɋm�� �@�@�@�@*/
/*                         �icalloc�g�p)  �@                        */
/*-----------------------------------------------------------------	*/
#include <stdio.h>
#include <stdlib.h>	//for exit() calloc()
#include <string.h>

void Matrix_free(char **p, int num);

int main(void)
{
	int 	i,	//�J�E���^
			n;	//������
	char	**c,
			buf[80];

	printf("������:");	scanf("%d",&n);

	c=(char **)calloc(n, sizeof(char *));//char�^�ւ̗v�f��n�̃|�C���^�z����m��
	if(c==NULL){								//�G���[����
		printf("�L���̈�̊m�ۂɎ��s���܂���\n");
		exit(1);
	}

	for(i=0;i<n;i++)	c[i]=NULL;		//�|�C���^�z��c�̑S�v�f��NULL����
		
	for(i=0;i<n;i++){
		printf("������%d:",i+1);	scanf("%s",buf);
		c[i]=(char *)calloc(strlen(buf)+1,sizeof(char));
		if(c[i]==NULL){
			printf("������%d�̋L���̈�̊m�ۂɎ��s���܂���\n", i+1);
			exit(0);
		}
		strcpy(c[i],buf);
	}

	for(i=0;i<n;i++)					//�S�v�f�̒l��\��
		printf("c[%d]=%s\n",i,c[i]);	

	Matrix_free(c,n);					//�m�ۂ��Ă����̈�̊J��
	
	return 0;
}

//�m�ۂ����S�̈�̊J��
void Matrix_free(char **p, int num)
{
	int i;
	
	for(i=0;i<num;i++)	free(p[i]);
	free(p);
}
