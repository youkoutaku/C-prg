/*------------------------------------------------------------------*/
/*      		 			�@�@<ex5-1.c>	�@�@					*/
/*�@�@�@�@�@�@�@�@�\���̃I�u�W�F�N�g�ւ̃|�C���^�̎g�p��@�@�@�@�@�@*/
/*-----------------------------------------------------------------	*/
#include <stdio.h>

//Prog2�^�̐錾
typedef struct {
	int		ID;
	char	name[20];
	int		final;
	double	mini;
	double	rpt;
} Prog2;


int main(void)
{
	//Prog2�^�̃I�u�W�F�N�g�̐錾�Ə�����
	Prog2 stdt1={251001,"sasaki",40,30,30};
	Prog2 *pt=&stdt1;
	
	printf("ID Number :%d\n",pt->ID);
	printf("Name      :%s\n",pt->name);
	printf("Final Exam:%d\n",pt->final);
	printf("Mini Test :%.1f\n",pt->mini);
	printf("Report    :%.1f\n",pt->rpt);
	
	return 0;
}