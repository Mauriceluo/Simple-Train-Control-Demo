/*
�� 
*/ 
#include"TrainHeadfile.h"

void EnsureInfo(TrainInfo* train) 
{
	printf("����/�����:%d\n",(*train).train_num);
	printf("���Ŀ���:");
	if((*train).train_type==1)
	printf("�쳵.\n");
	else if((*train).train_type==2)
	printf("����.\n");
	printf("���ķ���:");
	if((*train).train_direction==1)
	printf("˳ʱ��.\n");
	else if((*train).train_direction==2)
	printf("��ʱ��.\n");
	printf("�����׼������:(%d,%d)\n",(*train).train_datum_point.x,(*train).train_datum_point.y);
	printf("����λ��:(%d,%d)\n",(*train).train_start_2D.x,(*train).train_start_2D.y);
	if((*train).train_num==1)
	{
//		printf("̽���1:(%d,%d) ",(*train).train_detect_2D_1.x,(*train).train_detect_2D_1.y);
		printf("̽���1һά:%d",(*train).train_detect_1D_1); 
//		printf("̽���2:(%d,%d) ",(*train).train_detect_2D_2.x,(*train).train_detect_2D_2.y);
		printf("̽���2һά:%d\n",(*train).train_detect_1D_2);
//		printf("̽���3:(%d,%d) ",(*train).train_detect_2D_3.x,(*train).train_detect_2D_3.y);
		printf("̽���3һά:%d",(*train).train_detect_1D_3);
//		printf("̽���4:(%d,%d) ",(*train).train_detect_2D_4.x,(*train).train_detect_2D_4.y); 
	    printf("̽���4һά:%d\n",(*train).train_detect_1D_4);
	}
	else
	{
//		printf("̽���1:(%d,%d)",(*train).train_detect_2D_1.x,(*train).train_detect_2D_1.y);
		printf("̽���1һά:%d\n",(*train).train_detect_1D_1);
//		printf("̽���2:(%d,%d)",(*train).train_detect_2D_2.x,(*train).train_detect_2D_2.y);
	    printf("̽���1һά:%d\n",(*train).train_detect_1D_2);
	}
	printf("����ʱ��:%d\n",(*train).train_start_time);
	printf("���ٶ�:%d(��ʱ��Ϊ��)\n",(*train).train_speed);
	printf("ͣ��ʱ��:%d\n",(*train).train_pause_time);
	printf("���ڹ��:��:%d ��:%d\n",(*train).train_orbit_L,(*train).train_orbit_W);
	printf("��ʼ״̬:%d\n\n\n",(*train).train_state);
}
