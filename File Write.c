#include"TrainHeadfile.h"
//�ļ�����
void FileWrite(TrainInfo set[],FILE *fp,int temp) {
	fprintf(fp,"�𳵳���:%d\n������:%d\n�𳵷���:%d\n�����׼������:(%d,%d)\n����λ��:(%d,%d)\n",set[temp].train_num,set[temp].train_type,set[temp].train_direction,set[temp].train_datum_point.x,set[temp].train_datum_point.y,set[temp].train_start_2D.x,set[temp].train_start_2D.y);
	if(set[temp].train_num==1) {
//		fprintf(fp,"̽���1:(%d,%d) ",set[temp].train_detect_2D_1.x,set[temp].train_detect_2D_1.y);
		fprintf(fp,"̽���1һά:%d",set[temp].train_detect_1D_1);
//		fprintf(fp,"̽���2:(%d,%d) ",set[temp].train_detect_2D_2.x,set[temp].train_detect_2D_2.y);
		fprintf(fp,"̽���2һά:%d\n",set[temp].train_detect_1D_2);
//		fprintf(fp,"̽���3:(%d,%d) ",set[temp].train_detect_2D_3.x,set[temp].train_detect_2D_3.y);
		fprintf(fp,"̽���3һά:%d",set[temp].train_detect_1D_3);
//		fprintf(fp,"̽���4:(%d,%d) ",set[temp].train_detect_2D_4.x,set[temp].train_detect_2D_4.y);
		fprintf(fp,"̽���4һά:%d\n",set[temp].train_detect_1D_4);
	} else {
//		fprintf(fp,"̽���1:(%d,%d)",set[temp].train_detect_2D_1.x,set[temp].train_detect_2D_1.y);
		fprintf(fp,"̽���1һά:%d\n",set[temp].train_detect_1D_1);
//		fprintf(fp,"̽���2:(%d,%d)",set[temp].train_detect_2D_2.x,set[temp].train_detect_2D_2.y);
		fprintf(fp,"̽���2һά:%d\n",set[temp].train_detect_1D_2);
	}
	fprintf(fp,"����ʱ��:%d\n���ٶ�:%d(��ʱ��Ϊ��)\nͣ��ʱ��:%d\n���ڹ��:��:%d ��:%d\n\n\n",set[temp].train_start_time,set[temp].train_speed,set[temp].train_pause_time,set[temp].train_orbit_L,set[temp].train_orbit_W);
}
void FileWriteOut(TrainInfo* train,FILE *fp,int OutputTime) {
	if(run_method==1){
		fprintf(fp,"��ǰ���ԣ��쳵����\n");
	}
	else
	 fprintf(fp,"��ǰ���ԣ��������\n");
	/*A*/
	fprintf(fp,"��ǰʱ�䣺%d\n",OutputTime);
	fprintf(fp,"[A��]\n");
	fprintf(fp,"���з���:");
	if(train[0].train_direction==1)
		fprintf(fp,"˳ʱ��\n");
	else
		fprintf(fp,"��ʱ��\n");

	fprintf(fp,"����״̬:");
	if(train[0].train_state==0)
		fprintf(fp,"����-�ǹ������\n");
	else if(train[0].train_state==1)
		fprintf(fp,"��ͣ-�ȴ��������\n");
	else if(train[0].train_state==2)
		fprintf(fp,"ͣ��-ռ�ù������(����ȴ�%ds)\n",train[0].train_pause_time);
	else if(train[0].train_state==3)
		fprintf(fp,"����-�������\n");
	else if(train[0].train_state==4)
		fprintf(fp,"����-�������\n");
	else if(train[0].train_state==5)
		fprintf(fp,"����������ͣ��״̬\n");

	fprintf(fp,"��ǰλ��:(%d,%d)\n",train[0].train_distance_2D.x,train[0].train_distance_2D.y);

	/*B*/
	fprintf(fp,"[B��]\n");
	fprintf(fp,"���з���:");
	if(train[1].train_direction==1)
		fprintf(fp,"˳ʱ��\n");
	else
		fprintf(fp,"��ʱ��\n");

	fprintf(fp,"����״̬:");
	if(train[1].train_state==0)
		fprintf(fp,"����-�ǹ������\n");
	else if(train[1].train_state==1)
		fprintf(fp,"��ͣ-�ȴ��������\n");
	else if(train[1].train_state==2)
		fprintf(fp,"ͣ��-ռ�ù������(����ȴ�%ds)\n",train[1].train_pause_time);
	else if(train[1].train_state==3)
		fprintf(fp,"����-�������\n");
	else if(train[1].train_state==4)
		fprintf(fp,"����-�������\n");
	else if(train[1].train_state==5)
		fprintf(fp,"����������ͣ��״̬\n");

	fprintf(fp,"��ǰλ��:(%d,%d)\n",train[1].train_distance_2D.x,train[1].train_distance_2D.y);

	/*C*/
	fprintf(fp,"[C��]\n");
	fprintf(fp,"���з���:");
	if(train[2].train_direction==1)
		fprintf(fp,"˳ʱ��\n");
	else
		fprintf(fp,"��ʱ��\n");

	fprintf(fp,"����״̬:");
	if(train[2].train_state==0)
		fprintf(fp,"����-�ǹ������\n");
	else if(train[2].train_state==1)
		fprintf(fp,"��ͣ-�ȴ��������\n");
	else if(train[2].train_state==2)
		fprintf(fp,"ͣ��-ռ�ù������(����ȴ�%ds)\n",train[2].train_pause_time);
	else if(train[2].train_state==3)
		fprintf(fp,"����-�������\n");
	else if(train[2].train_state==4)
		fprintf(fp,"����-�������\n");
	else if(train[2].train_state==5)
		fprintf(fp,"����������ͣ��״̬\n");

	fprintf(fp,"��ǰλ��:(%d,%d)\n",train[2].train_distance_2D.x,train[2].train_distance_2D.y);

	/*�Ƿ�ռ�ù������*/
	fprintf(fp,"[�������״̬]:");

	if(IsInPubluic(train[0])==0&&IsInPubluic(train[1])==0&&IsInPubluic(train[2])==0)
		fprintf(fp,"����\n\n\n");
	else {
		if(IsInPubluic(train[0])==1)
			fprintf(fp,"��A��ռ�� ");
		if(IsInPubluic(train[1])==1)
			fprintf(fp,"��B��ռ�� ");
		if(IsInPubluic(train[2])==1)
			fprintf(fp,"��C��ռ�� ");
		fprintf(fp,"\n\n\n");
	}
}
