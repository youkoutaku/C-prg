/*------------------------------------------------------------------*/
/*      		 			�@�@<ex4-1.c>	�@�@					*/
/*�\���̂̐錾�ƃI�u�W�F�N�g�̎g�p�錾����у����o�Q�Ƃ̃v���O�����@*/
/*-----------------------------------------------------------------	*/
#include <stdio.h>
#include <string.h>

//struct prog2�^�̐錾
struct prog2{
	int 	ID;			//�w���ԍ�
	char    name[20];	//���O
	int		final;		//�����������_
	double	mini;		//���e�X�g���_
	double	rpt;		//���|�[�g���_
};

int main(void)
{
	struct prog2 stdt1;				//struct prog2�^�̃I�u�W�F�N�gstdt1�̐錾
	double score;					//�������_�p�ϐ�
	
	stdt1.ID=251001;				//�w���ԍ��̑��
	strcpy(stdt1.name, "sasaki"); 	/* ������"sasaki"��ϐ�stdt1�̃����o��
                                       �z��name�ɃR�s�[ */
	stdt1.final=40;					//���������̓��_�̑��
	stdt1.mini=30;					//���e�X�g�̓��_�̑��
	stdt1.rpt=30;					//���|�[�g�̓��_�̑��

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
