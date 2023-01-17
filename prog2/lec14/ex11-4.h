/*------------------------------------------------------------------*/
/*      		 		     <ex11-1.h> 			�@�@            */
/*  �@�@�@�@�@�@����\���̂̐錾�Ǝ���֐��̒�`���L�q      �@�@�@�@*/
/*     �@�@�@�@ ex11-4.c��ex11-4_func.c�ɓǂݍ��܂��				*/
/*-----------------------------------------------------------------	*/
#ifndef EX11_4_H_INCLUDED
#define EX11_4_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>	
#include <string.h>

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
void print_node(Prog2 *node);
void load_data(Prog2 *start);
void name_Search(Prog2 *start);
void ID_Search(Prog2 *start);
int menu(void);

#endif