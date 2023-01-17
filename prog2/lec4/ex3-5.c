/*  ���K5�F�f�[�^�t�@�C�����疼�O�A�N���ǂݎ��A�N��̒Ⴂ���ɕ��ёւ��� */
#include <stdio.h>
#include <string.h> /* strcpy�֐����g�p���邽�߂ɕK�v */

int main( void ){

  char ss[12], name[100][12];  /* 11�����܂ł̖��O��100�l�܂ŏ����\ */
  int a, age[100];             /* 100�l�܂ł̔N��������\ */
  int i, j,n;

  FILE *fpin, *fpout;                  /* �t�@�C���|�C���^�ϐ��̐錾 */
  fpin = fopen("ex3-5_in.txt", "r");    /* ����(read)�p�t�@�C�����I�[�v�� */
  fpout = fopen("ex3-5_out.txt", "w");  /* �o��(write)�p�t�@�C�����I�[�v�� */

  if (fpin == NULL)  {                /* ���S�΍�F���͗p�t�@�C���̃I�[�v���Ɏ��s�����Ƃ��̏��u */
    printf("���̓t�@�C���̃I�[�v���Ɏ��s���܂���");
    return 0;                         /* �r���Ńv���O�������I�������� */
  }

  if (fpout == NULL)  {              /* ���S�΍�F�o�͗p�t�@�C���̃I�[�v���Ɏ��s�����Ƃ��̏��u */
    printf("�o�̓t�@�C���̃I�[�v���Ɏ��s���܂���");
    return 0;                         /* �r���Ńv���O�������I�������� */
  }

  /* ���̓t�@�C������EOF(End of File)�������܂ŁA�`���ɏ]���ăf�[�^�����ɓǂݍ��� */
  n=0;
  while (fscanf(fpin, "%s %d", name[n], &age[n]) != EOF)  {
    printf("%-8s %d\n", name[n], age[n]);  /* �m�F�̂��߁A�ǂݍ��񂾃f�[�^����ʂ֏o�� */
    n++;
  }
  printf("%d�l���̃f�[�^������܂�\n", n);

  for (i=0; i<n-1; i++)  {
    for (j=i+1; j<n; j++)  {
      if (age[i] > age[j])  {  /* ����age[i]��age[j]���傫����΁A���O�ƔN������ւ��� */
        a = age[i];                /* age[i]��age[j]�̒��g�����ւ��� */
        age[i] = age[j];
        age[j] = a;

        strcpy(ss, name[i]);       /* name[i][]��name[j][]�̒��g�����ւ��� */
        strcpy(name[i], name[j]);
        strcpy(name[j], ss);
      }
    }
  }

  for (i=0; i<n; i++)  {
    fprintf(fpout, "%-8s %d\n", name[i], age[i]);  /* ���ʂ��o�̓t�@�C���֏o�� */
  }

  fclose(fpin);   /* ���͗p�t�@�C�����N���[�Y */
  fclose(fpout);  /* �o�͗p�t�@�C�����N���[�Y */

  return 0;
}