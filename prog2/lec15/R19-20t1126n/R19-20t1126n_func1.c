//�ۑ�19 ����֐��̎��̂̂����A���j���[�֐��A�����֐��i�Q�j�ƒ��o�֐��i�P�j���L�q���ꂽ����
//20t1126n YANG GUANGZE

#include "myhead\R19-20t1126n.h"

int menu(void){
    int ch;

    printf("/-----------------------------------------------------/\n");
	printf("/ 1.�S�f�[�^�̏o��                                    /\n");
	printf("/ 2.ID�i���o�[�ɂ�錟��                              /\n");
	printf("/ 3.���O�ɂ�錟��                                    /\n");
	printf("/ 4.��b��ӗ�(x)�ȏ�̒��o                           /\n");
	printf("/ 5.��b��ӗ�(x)�ȏ�̂���b��ӗʂ̍~��/�����Œ��o  /\n");
    printf("/ 6.�I��                                              /\n");
	printf("/-----------------------------------------------------/\n");

	do{
		printf("�I�����ڂ���͂��ĉ�����:"); scanf("%d", &ch);
	}while( ch<1 || ch >6);

	return ch;
}

void ID_Search(Eng *start){
	Eng 	*ip;
	int		key;

	printf("ID�i���o�[:");	scanf("%d", &key);

	for(ip=start->next; ip!=NULL; ip=ip->next){
		if(ip->ID==key){
			print_node(ip);	
			break;
		}
	}
	if(ip==NULL) printf("Not found!\n");
}

void name_Search(Eng *start){
	Eng 	*ip;
	char 	key[20];
	int		found=0;

	printf("���O:");	scanf("%s", key);

	for(ip=start->next; ip!=NULL; ip=ip->next){
		if(strcmp(ip->name,key)==0){
			print_node(ip);
			found++;
		}
	}
	if(found==0) printf("Not found!");
}

void print_Search(Eng *start){
    Eng *ip;
    int A;

    do{
		printf("��b��ӗ�(x):"); scanf("%d", &A);
	}while(A == EOF);

    for(ip=start->next; ip!=NULL; ip=ip->next){
		if( bmr(ip) >= A){
            print_node(ip);
        }
	}
}
