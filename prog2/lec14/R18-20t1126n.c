//�ۑ�18 ����\���̂̐錾�Ǝ��� �֐��̒�`�i�v���g�^�C�v�錾�j���L�q���ꂽ����
//20t1126n YANG GUANGZE
//gcc -Wall -o R18-20t1126n R18-20t1126n.c
//���̓t�@�C���Feng.txt

#include "myhead\R18-20t1126n.h"
#include "R18-20t1126n_func.c"

int main(void)
{
    Eng dmy={NULL};
    Eng *start=&dmy;
    int select;

    load_data(start);
    do{
		select=menu();
		switch(select){
			case 1:
				print_list(start);
				break;
			case 2:
				ID_Search(start);
				break;
			case 3:
                name_Search(start);
				break;
			case 4:
                print_Search(start);
				break;
            case 5:
                print_Search_up_down(start);
                break;
		}
	}while(select!=6); 	

    return 0;
}