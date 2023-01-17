//�ۑ�5 ��b��ӗʂ��v�Z����v���O����
//20T1126N YANG GUANGZE(�k�L��)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 15

void port1(FILE *fpin, int *ID, char name[][12], char *gender, int *age, double *weight){
    int n=0;
    while (fscanf(fpin, "%d   %s %c  %d  %lf", &ID[n], name[n], &gender[n], &age[n], &weight[n]) != EOF)  {
        printf("%d   %-8s %c  %d  %0.1lf\n", ID[n], name[n], gender[n], age[n], weight[n]); 
        n++;
    }
}
//�֐����ɁA�f�[�^����͂��鎞�ɁA*�܂��ꎟ�z��̏ꍇ�Ƀ|�C���g�����́A�����K�v�ł���B���ʂȓ񎟔z��̏ꍇ�Ɂ����K�v�Ȃ��B

void port2(char *gender, int *age, double *weight, double *BMR){
    int i;
    for(i=0; i<N; i++){
        if(gender[i] == 'M'){
            if(age[i] >= 15 && age[i] <= 17){
                BMR[i] = 27.0*weight[i];
            }else if(age[i] >= 18 && age[i] <= 29){
                BMR[i] = 24.0*weight[i];
            }else if(age[i] >= 30 && age[i] <= 49){
                BMR[i] = 22.3*weight[i];
            }else if(age[i] >= 50 && age[i] <= 69){
                BMR[i] = 21.5*weight[i];
            }else{
                BMR[i] = 0.0;
            }
        }
        if(gender[i]=='F'){
           if(age[i] >= 15 && age[i] <= 17){
                BMR[i] = 25.3*weight[i];
            }else if(age[i] >= 18 && age[i] <= 29){
                BMR[i] = 23.6*weight[i];
            }else if(age[i] >= 30 && age[i] <= 49){
                BMR[i] = 21.7*weight[i];
            }else if(age[i] >= 50 && age[i] <= 69){
                BMR[i] = 20.7*weight[i];
            }else{
                BMR[i] = 0.0;
            }
        }
    }
}

void port3(int *ID, char name[][12], char *gender, int *age, double *weight, double *BMR){
    int i,j;
    int a;
    char b, c[12];
    double d;

    for (i=0; i<N-1; i++){
        for (j=i+1; j<N; j++){
            if (BMR[i] < BMR[j]){
                a = ID[i];
                ID[i] = ID[j];
                ID[j] = a;

                strcpy(c, name[i]);  
                strcpy(name[i], name[j]);
                strcpy(name[j], c);
                //�����̔z���char�^�ł���A������𒼐ڑ���ł��Ȃ��B

                b = gender[i];
                gender[i] = gender[j];
                gender[j] = b;
                //������gender��char*�^�ł���

                a = age[i];
                age[i] = age[j];
                age[j] = a;

                d = weight[i];
                weight[i] = weight[j];
                weight[j] = d;

                d = BMR[i];
                BMR[i] = BMR[j];
                BMR[j] = d;
            }
        }
    }
}

void port4(FILE *fpout,int *ID, char name[][12], char *gender, int *age, double *weight, double *BMR){
    int i;
    for(i=0; i<N; i++){
        fprintf(fpout, "%d   %-8s  %c  %d  %0.1lf  %0.1lf\n", ID[i], name[i], gender[i], age[i], weight[i], BMR[i]);
    }
}
//�|�C���g������������ɁA*���K�v�A�܂��z��Ƃ���[]���g���Ă��悢�B

int main( void ){
    char name[N][12], gender[N];
    int ID[N],age[N];
    double weight[N],BMR[N]={0.0};

    FILE *fpin, *fpout;
    fpin = fopen("R5_in.txt","r");  
    fpout = fopen("R5_out.txt","w");
    //���̓t�@�C���Əo�̓t�@�C���������A�錾����B

    if (fpin == NULL)  {                
        printf("���̓t�@�C���̃I�[�v���Ɏ��s���܂���");
        return 0;                        
    }
    if (fpout == NULL)  {              
        printf("�o�̓t�@�C���̃I�[�v���Ɏ��s���܂���");
        return 0;                       
    }
    //���͂Əo�͂��m�F����B

    port1(fpin, ID, name, gender, age, weight);
    port2(gender, age, weight, BMR);
    port3(ID, name, gender, age, weight, BMR);
    port4(fpout, ID, name, gender, age, weight, BMR);
    //�R�����g�F�֐��ɓn�������͂��ׂĔz��ł���̂ŁA���̂܂ܖ�����͂��Ă����܂�Ȃ����A���ʂ̑㐔�̏ꍇ�ɁA�����K�v�ł���B


    fclose(fpin);  
    fclose(fpout);

    return 0;
}