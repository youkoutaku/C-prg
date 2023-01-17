/*------------------------------------------------------------------*/
/*      		 			�@<ex10-1.c> 					�@�@    */
/*�@�@�@			�@�@�@�@�@���`���X�g �@�@�@�@�@�@�@�@�@ �@�@�@�@*/
/*                �w���ԍ��̏����Ƀ`�F�[�����q���ς���@�@			*/
/*-----------------------------------------------------------------	*/
#include <stdio.h>
#include <stdlib.h>	//for exit(), calloc()

//Seiseki�^�̐錾
typedef struct{
	int		final;
	double	mini;
	double	rpt;
} Seiseki;

//Prog2�^�̐錾
typedef struct prog2{
	struct prog2	*next;		//���̃m�[�h�ւ̃|�C���^
	int				ID; 		//�w���ԍ�
	char			name[20];	//���O
	Seiseki			sc;			//���уf�[�^
} Prog2;

//�֐��̃v���g�^�C�v�錾
Prog2 *Alloc_Node(void);
void print_list(Prog2 *start);
void make_list(Prog2 *start);

int main(void)
{
	Prog2 	dmy={NULL};		//NULL�ŏ��������ďI�[�}�[�N�ɂ���
	Prog2	*start=&dmy;	//�擪�Ǘ��p�̍\����

	make_list(start);		//���`���X�g�̐���

	print_list(start);		//���`���X�g�̃f�[�^�\��

	return 0;
}

//���`���X�g�̐����֐�
void make_list(Prog2 *start)
{
		Prog2	*ip,		//for���[�v����p
				*node,		//�}���m�[�h���w���|�C���^
				wk={NULL};	//�ꎞ�ۑ��p

		while(1){

			//�L�[�{�[�h����̃f�[�^����
			printf("ID Number :"); 	scanf("%d",&wk.ID);
									if(wk.ID==EOF) break; //�w���ԍ���EOF(-1)�����͂��ꂽ��I��
			printf("Name      :"); 	scanf("%s", wk.name);
			printf("Final Exam:"); 	scanf("%d", &wk.sc.final);
			printf("Mini Test :"); 	scanf("%lf", &wk.sc.mini);
			printf("Report    :"); 	scanf("%lf", &wk.sc.rpt);

			//�m�[�h1���̃������̈���m��
			node=Alloc_Node();
	
			//�m�[�h�Ƀf�[�^��ݒ肷��
			*node=wk;

			//���������m�[�h���`�F�[���ɂ͂ߍ���(�w���ԍ��̏���)
			for(ip=start;ip->next!=NULL;ip=ip->next){
				if( node->ID < ip->next->ID){ 
					node->next=ip->next;
					ip->next=node;
					break;
				}
			}
			
			//�w���ԍ����ő�̏ꍇ�`�F�[���̍Ō�ɂȂ�
			if(ip->next==NULL){	//�`�F�[����NULL�ɍs��������
				ip->next=node;		//�Ō����node����������
				node->next=NULL;	//�V���ɍŌ���̃}�[�N(NULL)
			}
		}
}

//���`���X�g�̑S�f�[�^��\������֐�
void print_list(Prog2 *start)
{
	Prog2 *ip;

	//�`�F�[�������ǂ��ăm�[�h�̓��e��\������
	for(ip=start->next; ip!=NULL; ip=ip->next){
		printf("%-10d%-10s%10.1f%10.1f%10d\n",
			ip->ID,ip->name, ip->sc.mini, ip->sc.rpt, ip->sc.final);
	}
}

//�m�[�h�����֐�
Prog2 *Alloc_Node(void)
{
	Prog2 *pt;

	pt=(Prog2 *)calloc(1, sizeof(Prog2));	//Prog2�^1�����I�Ɋm��
	if(pt==NULL){
		printf("�L���̈�̊m�ۂɎ��s���܂���\n");
		exit(1);
	}

	return pt;
}