/*------------------------------------------------------------------*/
/*      		 			�@�@<ex4-2.c>	�@�@					*/
/*				�\���̃I�u�W�F�N�g�̏������̃v���O������@�@�@�@	*/
/*-----------------------------------------------------------------	*/
#include <stdio.h>

//struct prog2�^�̐錾
struct prog2{
	int 	ID;			//�w���ԍ�
	char	name[20];	//���O
	int		final;		//�����������_
	double	mini;		//���e�X�g���_
	double	rpt;		//���|�[�g���_
};

int main(void)
{
	//struct prog2�^�̃I�u�W�F�N�gstdt1�̐錾�Ə�����
	struct prog2 stdt1={251001,"sasaki",40,30,30};
	double score;		//�������_�p�ϐ�
	
	printf("ID Number :%d\n", stdt1.ID);
	printf("Name      :%s\n", stdt1.name);
	printf("Final Exam:%d\n", stdt1.final);
	printf("Mini Test :%.1f\n", stdt1.mini);
	printf("Report    :%.1f\n", stdt1.rpt);
	
	//�������_�̌v�Z
	score=stdt1.final+stdt1.mini+stdt1.rpt;
	
	printf("Total Score:%.1f\n",score);

	return 0;
}
