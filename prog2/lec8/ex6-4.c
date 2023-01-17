/*------------------------------------------------------------------*/
/*      		 			�@�@<ex6-4.c>	�@�@					*/
/*�@����q�\���̍\���̂̔z��̐錾�E�������E�Q�Ƃ̃v���O������@�@�@*/
/*-----------------------------------------------------------------	*/
#include <stdio.h>
#define SNUM 5

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
void print_data(Prog2 *obj);

int main(void)
{
	//Prog2�^�̔z��Mech[SNUM]�̐錾�Ə�����
	Prog2 Mech[SNUM]={		
				{251001,"sasaki",{40,30,30}},	//Mech[0]�̏������q
				{251002,"sato",{35,25,25}},		//Mech[1]�̏������q
				{251003,"kato",{30,20,20}},		//Mech[2]�̏������q
	};
	
	print_data(Mech);	//�������_�̌v�Z�ƕ\��
	
	return 0;
}

void print_data(Prog2 *obj)
{
	int	i;			//�J�E���^
	double 	score;	//�������_�p�ϐ�

	//�w���ԍ��A���ڕʓ��_�A�������_�̕\��
	printf("%-10s%-10s%10s%10s%10s%10s\n", 
      "ID","Name","Mini","Report","Final","Total");
	for(i=0;i<SNUM;i++){
		score=obj[i].sc.final+obj[i].sc.mini+obj[i].sc.rpt;
		printf("%-10d%-10s%10.1f%10.1f%10d%10.1f\n", obj[i].ID,
				obj[i].name, obj[i].sc.mini, obj[i].sc.rpt,
				obj[i].sc.final, score);
	}
}
