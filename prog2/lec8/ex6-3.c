/*------------------------------------------------------------------*/
/*      		 			�@�@<ex6-3.c>	�@�@					*/
/*	����q�\���̍\���̃I�u�W�F�N�g�̃A�h���X���o���̃v���O������@*/
/*�@�@�@�@�@�@�@�@�@ �i�\���̕ϐ���Ԃ��֐��j �@�@�@�@�@�@�@        */
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

//�֐��̃v���g�^�C�v�錾
Prog2 input_data(void);

int main(void)
{
	Prog2 stdt1;	//Prog2�^�̃I�u�W�F�N�gstdt1�̐錾
	
	stdt1=input_data();
	
	//�����o�̒l����ʂɕ\��
	printf("**** Input Data ****\n");
    printf("ID Number :%d\n", stdt1.ID);
	printf("Name      :%s\n", stdt1.name);
	printf("Final Exam:%d\n", stdt1.sc.final);
	printf("Mini Test :%.1f\n", stdt1.sc.mini);
	printf("Report    :%.1f\n", stdt1.sc.rpt);

	return 0;
}

Prog2 input_data(void)
{
	Prog2 obj;

	//�����o�̒l���L�[�{�[�h����̓���
	printf("**** Diplay Data ****\n");
	printf("ID Number :"); 	scanf("%d", &obj.ID);
	printf("Name      :"); 	scanf("%s", obj.name);
	printf("Final Exam:"); 	scanf("%d", &obj.sc.final);
	printf("Mini Test :"); 	scanf("%lf", &obj.sc.mini);
	printf("Report    :"); 	scanf("%lf", &obj.sc.rpt);

	return obj;
}
