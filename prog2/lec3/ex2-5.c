/* ���K5�F�|�C���^�̔z��[���ȏ��V�j�A��p.181] */
#include <stdio.h>
#include <string.h>  /* strcpy�֐����g�����߂ɕK�v�ȃw�b�_�t�@�C������荞�� */

int main( void ){
  int i;
  /* char�^�z��ɂ�鑽����������̐錾�Ə����� */
  /* �|�C���^�z��ɂ�鑽����������̐錾�Ə����� */
  char *wkp;
  char wk[10];

  printf("===<< �����������z��̏��� >>===\n");
  for (i=0; i<3; i++)  {
    printf("ss[%d][] = %s\n", i, ss[i]);   /* ������ss�̏o��(ss[i]�̓|�C���^��\��) */
  }

  printf("--char�^�z��̕�����ss[0][]��ss[1][]�����ւ���--\n  char�^�z��̕�����̏ꍇ�Asrtcpy�֐����g���K�v������\n");
  strcpy(wk, ss[0]);  /* �z�񖼁uss[0]�v��uss[1]�v�̓|�C���^(�z��̐擪�v�f�̃A�h���X)��\�� */
  strcpy(ss[0], ss[1]);
  strcpy(ss[1], wk);
  for (i=0; i<3; i++)  {
    printf("ss[%d][] = %s\n", i, ss[i]);  /* ������ss[i][]�̏o�� */
  }

  printf("\n");
  printf("===<< �|�C���^�z��̏��� >>===\n");
  for (i=0; i<3; i++)  {
    printf("ssp[%d] = %s\n", i, ssp[i]);   /* �|�C���^�ɂ�镶����ssp�̏o�� */
  }

  printf("--�|�C���^�z��ssp[0]��ssp[1]�����ւ���--\n  �|�C���^�̏ꍇ�A�A�h���X����������΂悢\n");
  wkp = ssp[0];
  ssp[0] = ssp[1];
  ssp[1] = wkp;
  for (i=0; i<3; i++)  {
    printf("ssp[%d] = %s\n", i, ssp[i]);  /* �|�C���^�ɂ�镶����ssp�̏o�� */
  }

  return 0;
}

