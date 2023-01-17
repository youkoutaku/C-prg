/*  fgets(����)��fputs(�o��)�̎g����                             */
/*  �t�@�C���̃R�s�[���s�� (���ȏ��� p.225�����ȒP�ɂ�������)  */
#include <stdio.h>
#include <stdlib.h> /* exit() */

int main( void ){

  char ss[256];    /* �ǂݍ��񂾕�������i�[����ϐ�(�ő�256����)��錾 */

  FILE *fpin, *fpout;                 /* �t�@�C���|�C���^�ϐ��̐錾 */
  fpin = fopen( "ex3-4_in.txt","r" );    /* ����(read)�p�t�@�C�����I�[�v�� */
  fpout = fopen( "ex3-4_out.txt", "a" );  /* �o��(write)�p�t�@�C�����I�[�v�� */

  if (fpin == NULL)  {                /* ���S�΍�F���͗p�t�@�C���̃I�[�v���Ɏ��s�����Ƃ��̏��u */
    printf("���̓t�@�C���̃I�[�v���Ɏ��s���܂���\n");
    exit(1);                         /* �r���Ńv���O�������I�������� */
  }

  if (fpout == NULL)  {              /* ���S�΍�F�o�͗p�t�@�C���̃I�[�v���Ɏ��s�����Ƃ��̏��u */
    printf("�o�̓t�@�C���̃I�[�v���Ɏ��s���܂���\n");
    exit(1);                         /* �r���Ńv���O�������I�������� */
  }

  /* ���̓t�@�C���̓ǂݍ��݂Ɏ��s����(�I���R�[�hNULL)�܂ŁA��s���f�[�^��ǂݍ��� */
  while (fgets(ss, 256, fpin) != NULL)  {  /* �ǂݍ��񂾍s�̒��g�𕶎���ss�Ɋi�[ */
    fputs(ss, fpout);                      /* ������ss(�ǂݍ��񂾃f�[�^)���o�͗p�t�@�C���֏o�� */
  }

  fputs("���̍s�����ǉ����܂���", fpout);

  fclose(fpin);   /* ���͗p�t�@�C�����N���[�Y */
  fclose(fpout);  /* �o�͗p�t�@�C�����N���[�Y */

  return 0;
}
