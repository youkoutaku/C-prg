/*------------------------------------------------------------------*/
/*      		 			�@�@<ex6-1.c>	�@�@					*/
/*�@      ����q�\���̍\���̃I�u�W�F�N�g�̏������̃v���O������@    */
/*-----------------------------------------------------------------	*/
#include <stdio.h>

//Seiseki�^�̐錾
typedef struct{
	int		final;
	double	mini;
	double	rpt;
} Seiseki;

//Prog2�^�̐錾
typedef struct {
	int		ID;
	char	name[20];
	Seiseki	sc;
} Prog2;

int main(void)
{
	//Prog2�^�̃I�u�W�F�N�g�̐錾�Ə�����
	Prog2 stdt1={251001,"sasaki",{40,30,30}};
	
	//�����o�̒l����ʂɕ\��
	printf("ID Number :%d\n", stdt1.ID);
	printf("Name      :%s\n", stdt1.name);
	printf("Final Exam:%d\n", stdt1.sc.final);
	printf("Mini Test :%.1f\n", stdt1.sc.mini);
	printf("Report    :%.1f\n", stdt1.sc.rpt);
	
	return 0;
}