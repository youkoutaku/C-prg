/*------------------------------------------------------------------*/
/*      		 			�@�@<ex5-4.c>	�@�@					*/
/*�@�@�@�@�@�@�@�@�@�\���̕ϐ���Ԃ��֐��̗�@�@�@�@�@�@�@�@        */
/*-----------------------------------------------------------------	*/
#include <stdio.h>

//Prog2�^�̐錾
typedef struct{
	int 	ID;
	char	name[20];
	int		final;
	double	mini;
	double	rpt;
} Prog2;

//�֐��̃v���g�^�C�v�錾
Prog2 input_data(void);

int main(void)
{
	Prog2 stdt1;	//Prog2�^�̃I�u�W�F�N�gstdt1�̐錾
	
	stdt1=input_data();
	
	//�����o�̒l����ʂɕ\��
	printf("**** Display Data ****\n");
	printf("ID Number :%d\n",stdt1.ID);
	printf("Name      :%s\n",stdt1.name);
	printf("Final Exam:%d\n",stdt1.final);
	printf("Mini Test :%.1f\n",stdt1.mini);
	printf("Report    :%.1f\n",stdt1.rpt);

	return 0;
}

Prog2 input_data(void)
{
	Prog2 obj;

	//�����o�̒l���L�[�{�[�h����̓���
	printf("**** Input Data ****\n");
	printf("ID Number :"); 	scanf("%d",&obj.ID);
	printf("Name      :"); 	scanf("%s",obj.name);
	printf("Final Exam:"); 	scanf("%d",&obj.final);
	printf("Mini Test :"); 	scanf("%lf",&obj.mini);
	printf("Report    :"); 	scanf("%lf",&obj.rpt);

	return obj;
}
