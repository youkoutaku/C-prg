//�ۑ�4 �A���t�@�x�b�g�̏����ɖ��O����ёւ���v���O����
//20T1126N YANG GUANGZE(�k�L��)

#include <stdio.h>
#define N 10

int main(void){
    int i,j=0;
    char *name[N+1] = 
    {"Luna", "Sarah", "Dona", "Blenda", "Kelly", "Noah",
     "Mailo", "Oliver", "Jasper", "Asher"};
    char *c;

    for(i=0; i<N; i++){
        printf("%s\n", name[i]);
    }

    for(i=0; i<N-1; i++){
        for(j=i+1; j<N; j++){
            if( name[i][0] > (name[j][0]) ){
                c = name[i];
                name[i] = name[j];
                name[j] = c;
            }
        }        
    }
    
    printf("<<Sort by name alphabetically.>>\n");
    for(i=0; i<N; i++){
        printf("%s\n", name[i]);
    }
    return 0;
}