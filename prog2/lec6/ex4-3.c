/*------------------------------------------------------------------*/
/*      		 			�@�@<ex4-3.c>	�@�@					*/
/*�@�@�@�@�\���̃I�u�W�F�N�g�̃����o�̃A�h���X�̎��o����@�@�@�@�@*/
/*-----------------------------------------------------------------	*/
#include <stdio.h>

//struct prog2�^�̐錾
struct prog2{
	int 	ID;
	char	name[20];
	int		final;
	double	mini;
	double	rpt;
};

int main(void)
{
	struct prog2 stdt1;	//struct prog2�^�̃I�u�W�F�N�gstdt1�̐錾
	double score;		//�������_�p�ϐ�

	//�����o�̒l���L�[�{�[�h����̓���
	printf("**** Input Data ****\n");
	printf("ID Number :"); 	scanf("%d", &stdt1.ID);
	printf("Name      :");	scanf("%s", stdt1.name);
	printf("Final Exam:"); 	scanf("%d", &stdt1.final);
	printf("Mini Test :"); 	scanf("%lf", &stdt1.mini);
	printf("Report    :"); 	scanf("%lf", &stdt1.rpt);

	//�������_�̌v�Z
	score=stdt1.final+stdt1.mini+stdt1.rpt;
	
	//�����o�̒l�Ƒ������_����ʂɕ\��
	printf("**** Display Data ****\n");
    printf("ID Number :%d\n",stdt1.ID);
    printf("Name      :%s\n",stdt1.name);
	printf("Final Exam:%d\n",stdt1.final);
	printf("Mini Test :%.1f\n",stdt1.mini);
	printf("Report    :%.1f\n",stdt1.rpt);
	printf("Total Score:%.1f\n",score);

	return 0;
}
