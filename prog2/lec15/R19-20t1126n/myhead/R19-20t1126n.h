//�ۑ�19 ����\���̂̐錾�⎩��֐��̒�`���L�q���ꂽ����
//20t1126n YANG GUANGZE

#ifndef R19_20t1126n_H_INCLUDE
#define R19_20t1126n_H_INCLUDE

#include <stdio.h>
#include <stdlib.h>	
#include <string.h>

typedef struct{
	char    gender;         //����                    
    int     age;            //�N��
    double  weight;         //�̏d
} Data;

typedef struct Eng{
	struct Eng	*next;      //�|�C���^
	int			ID;         //ID�i���o�[
	char		name[20];   //���O
	Data		data;       //����q
} Eng;

Eng *Alloc_Node(void);
int menu(void);
double bmr(Eng *ip);                    //��b��ӗʂ��v�Z����
void print_note(Eng *ip);               //��b��ӗʂ��܂߂ăf�[�^�̏o��

void load_data(Eng *start);             //�f�[�^���́A���X�g�̍쐬
void print_list(Eng *start);            //�f�[�^�\��(��b��ӗʂ��Ȃ�)
void ID_Search(Eng *start);             //ID�i���o�[����
void name_Search(Eng *start);           //���O����
void print_Search(Eng *start);          //��b��ӗ�(x)�ȏ�̌���
void print_Search_up_down(Eng *start);  //��b��ӗ�(x)�ȏ�̂��������A�~��/�����ŕ\������

#endif