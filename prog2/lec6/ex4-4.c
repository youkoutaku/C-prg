/*------------------------------------------------------------------*/
/*      		 			�@�@<ex4-4.c>	�@�@					*/
/*�@�@�@�@�@�\���̂̔z��̐錾�E�������E�Q�Ƃ̃v���O������@�@�@�@�@*/
/*-----------------------------------------------------------------	*/
#include <stdio.h>
#define SNUM 5

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
	int		i;			//�J�E���^
	double 	score;		//�������_�p�ϐ�
	//struct prog2�^�̔z��prog2[SNUM]�̐錾�Ə�����
	struct prog2 Mech[SNUM]={		
				{251001, "sasaki", 40, 30, 30},	//Mech[0]�̏������q
				{251002, "kato", 35, 25 ,25},	//Mech[1]�̏������q
				{251003, "sato", 30, 20, 20},	//Mech[2]�̏������q
	};
	
	//�w���ԍ��A���ڕʓ��_�A�������_�̕\��
	printf("%-10s%-10s%10s%10s%10s%10s\n", 
      "ID","Name","Mini","Report","Final","Total");

	for(i=0;i<SNUM;i++){
		score=Mech[i].final+Mech[i].mini+Mech[i].rpt;
	   	printf("%-10d%-10s%10.1f%10.1f%10d%10.1f\n", Mech[i].ID,
        	Mech[i].name, Mech[i].mini, Mech[i].rpt, Mech[i].final,score);
	}

	return 0;
}
