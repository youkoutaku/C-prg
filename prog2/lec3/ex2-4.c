/* ���K4�F������̌���[���ȏ��V�j�A��p.178] */
#include <stdio.h>
#include <string.h>  /* strcpy�֐����g�����߂ɕK�v�ȃw�b�_�t�@�C������荞�� */

int main( void ){
  int i;

  char s1[4]= "abc"; /* char�^�z��ɂ�镶����̐錾�Ə����� */
  char s2[4]= "xyz"; /* char�^�z��ɂ�镶����̐錾�Ə����� */
  char *p1= "ABC"; /* �|�C���^�ɂ�镶����̐錾�Ə����� */
  char *p2= "XYZ"; /* �|�C���^�ɂ�镶����̐錾�Ə����� */
  
  char wks[4];
  char *wkp;

  printf("s1 = %s   s2 = %s\n", s1, s2);  /* ������̏o�� */
  printf("--char�^�z��̕�����s1��s2�����ւ���--\n  char�^�z��̕�����̏ꍇ�Asrtcpy�֐����g���K�v������\n");
  strcpy(wks, s1);  /* �z�񖼁us1�v��us2�v�̓|�C���^(�z��̐擪�v�f�̃A�h���X)��\�� */
  strcpy(s1, s2);
  strcpy(s2, wks);
  printf("s1 = %s   s2 = %s\n", s1, s2);  /* ������̏o�� */

  printf("\n"); 
  printf("p1 = %s   p2 = %s\n", p1, p2);  /* ������̏o�� */
  printf("--�|�C���^������p1��p2�����ւ���--\n  �|�C���^�̏ꍇ�A�A�h���X����������΂悢\n");
  wkp = p1;  /* ���ȏ��V�j�A�� p.180�̉��̃v���O�������Q�l */
  p1 = p2;
  p2 = wkp;
  printf("p1 = %s   p2 = %s\n", p1, p2); /* ������̏o�� */

  return 0;
}

