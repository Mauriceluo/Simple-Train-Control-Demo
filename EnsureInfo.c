/*
罗 
*/ 
#include"TrainHeadfile.h"

void EnsureInfo(TrainInfo* train) 
{
	printf("车号/轨道号:%d\n",(*train).train_num);
	printf("车的快慢:");
	if((*train).train_type==1)
	printf("快车.\n");
	else if((*train).train_type==2)
	printf("慢车.\n");
	printf("车的方向:");
	if((*train).train_direction==1)
	printf("顺时针.\n");
	else if((*train).train_direction==2)
	printf("逆时针.\n");
	printf("轨道基准点坐标:(%d,%d)\n",(*train).train_datum_point.x,(*train).train_datum_point.y);
	printf("启动位置:(%d,%d)\n",(*train).train_start_2D.x,(*train).train_start_2D.y);
	if((*train).train_num==1)
	{
//		printf("探测点1:(%d,%d) ",(*train).train_detect_2D_1.x,(*train).train_detect_2D_1.y);
		printf("探测点1一维:%d",(*train).train_detect_1D_1); 
//		printf("探测点2:(%d,%d) ",(*train).train_detect_2D_2.x,(*train).train_detect_2D_2.y);
		printf("探测点2一维:%d\n",(*train).train_detect_1D_2);
//		printf("探测点3:(%d,%d) ",(*train).train_detect_2D_3.x,(*train).train_detect_2D_3.y);
		printf("探测点3一维:%d",(*train).train_detect_1D_3);
//		printf("探测点4:(%d,%d) ",(*train).train_detect_2D_4.x,(*train).train_detect_2D_4.y); 
	    printf("探测点4一维:%d\n",(*train).train_detect_1D_4);
	}
	else
	{
//		printf("探测点1:(%d,%d)",(*train).train_detect_2D_1.x,(*train).train_detect_2D_1.y);
		printf("探测点1一维:%d\n",(*train).train_detect_1D_1);
//		printf("探测点2:(%d,%d)",(*train).train_detect_2D_2.x,(*train).train_detect_2D_2.y);
	    printf("探测点1一维:%d\n",(*train).train_detect_1D_2);
	}
	printf("启动时间:%d\n",(*train).train_start_time);
	printf("火车速度:%d(逆时针为负)\n",(*train).train_speed);
	printf("停靠时间:%d\n",(*train).train_pause_time);
	printf("所在轨道:长:%d 宽:%d\n",(*train).train_orbit_L,(*train).train_orbit_W);
	printf("初始状态:%d\n\n\n",(*train).train_state);
}
