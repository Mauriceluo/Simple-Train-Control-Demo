#include"TrainHeadfile.h"
//文件输入
void FileWrite(TrainInfo set[],FILE *fp,int temp) {
	fprintf(fp,"火车车号:%d\n火车类型:%d\n火车方向:%d\n轨道基准点坐标:(%d,%d)\n启动位置:(%d,%d)\n",set[temp].train_num,set[temp].train_type,set[temp].train_direction,set[temp].train_datum_point.x,set[temp].train_datum_point.y,set[temp].train_start_2D.x,set[temp].train_start_2D.y);
	if(set[temp].train_num==1) {
//		fprintf(fp,"探测点1:(%d,%d) ",set[temp].train_detect_2D_1.x,set[temp].train_detect_2D_1.y);
		fprintf(fp,"探测点1一维:%d",set[temp].train_detect_1D_1);
//		fprintf(fp,"探测点2:(%d,%d) ",set[temp].train_detect_2D_2.x,set[temp].train_detect_2D_2.y);
		fprintf(fp,"探测点2一维:%d\n",set[temp].train_detect_1D_2);
//		fprintf(fp,"探测点3:(%d,%d) ",set[temp].train_detect_2D_3.x,set[temp].train_detect_2D_3.y);
		fprintf(fp,"探测点3一维:%d",set[temp].train_detect_1D_3);
//		fprintf(fp,"探测点4:(%d,%d) ",set[temp].train_detect_2D_4.x,set[temp].train_detect_2D_4.y);
		fprintf(fp,"探测点4一维:%d\n",set[temp].train_detect_1D_4);
	} else {
//		fprintf(fp,"探测点1:(%d,%d)",set[temp].train_detect_2D_1.x,set[temp].train_detect_2D_1.y);
		fprintf(fp,"探测点1一维:%d\n",set[temp].train_detect_1D_1);
//		fprintf(fp,"探测点2:(%d,%d)",set[temp].train_detect_2D_2.x,set[temp].train_detect_2D_2.y);
		fprintf(fp,"探测点2一维:%d\n",set[temp].train_detect_1D_2);
	}
	fprintf(fp,"启动时间:%d\n火车速度:%d(逆时针为负)\n停靠时间:%d\n所在轨道:长:%d 宽:%d\n\n\n",set[temp].train_start_time,set[temp].train_speed,set[temp].train_pause_time,set[temp].train_orbit_L,set[temp].train_orbit_W);
}
void FileWriteOut(TrainInfo* train,FILE *fp,int OutputTime) {
	if(run_method==1){
		fprintf(fp,"当前策略：快车先行\n");
	}
	else
	 fprintf(fp,"当前策略：交替策略\n");
	/*A*/
	fprintf(fp,"当前时间：%d\n",OutputTime);
	fprintf(fp,"[A车]\n");
	fprintf(fp,"运行方向:");
	if(train[0].train_direction==1)
		fprintf(fp,"顺时针\n");
	else
		fprintf(fp,"逆时针\n");

	fprintf(fp,"运行状态:");
	if(train[0].train_state==0)
		fprintf(fp,"运行-非公共轨道\n");
	else if(train[0].train_state==1)
		fprintf(fp,"暂停-等待公共轨道\n");
	else if(train[0].train_state==2)
		fprintf(fp,"停靠-占用公共轨道(还需等待%ds)\n",train[0].train_pause_time);
	else if(train[0].train_state==3)
		fprintf(fp,"运行-公共轨道\n");
	else if(train[0].train_state==4)
		fprintf(fp,"运行-公共轨道\n");
	else if(train[0].train_state==5)
		fprintf(fp,"接受命令暂停等状态\n");

	fprintf(fp,"当前位置:(%d,%d)\n",train[0].train_distance_2D.x,train[0].train_distance_2D.y);

	/*B*/
	fprintf(fp,"[B车]\n");
	fprintf(fp,"运行方向:");
	if(train[1].train_direction==1)
		fprintf(fp,"顺时针\n");
	else
		fprintf(fp,"逆时针\n");

	fprintf(fp,"运行状态:");
	if(train[1].train_state==0)
		fprintf(fp,"运行-非公共轨道\n");
	else if(train[1].train_state==1)
		fprintf(fp,"暂停-等待公共轨道\n");
	else if(train[1].train_state==2)
		fprintf(fp,"停靠-占用公共轨道(还需等待%ds)\n",train[1].train_pause_time);
	else if(train[1].train_state==3)
		fprintf(fp,"运行-公共轨道\n");
	else if(train[1].train_state==4)
		fprintf(fp,"运行-公共轨道\n");
	else if(train[1].train_state==5)
		fprintf(fp,"接受命令暂停等状态\n");

	fprintf(fp,"当前位置:(%d,%d)\n",train[1].train_distance_2D.x,train[1].train_distance_2D.y);

	/*C*/
	fprintf(fp,"[C车]\n");
	fprintf(fp,"运行方向:");
	if(train[2].train_direction==1)
		fprintf(fp,"顺时针\n");
	else
		fprintf(fp,"逆时针\n");

	fprintf(fp,"运行状态:");
	if(train[2].train_state==0)
		fprintf(fp,"运行-非公共轨道\n");
	else if(train[2].train_state==1)
		fprintf(fp,"暂停-等待公共轨道\n");
	else if(train[2].train_state==2)
		fprintf(fp,"停靠-占用公共轨道(还需等待%ds)\n",train[2].train_pause_time);
	else if(train[2].train_state==3)
		fprintf(fp,"运行-公共轨道\n");
	else if(train[2].train_state==4)
		fprintf(fp,"运行-公共轨道\n");
	else if(train[2].train_state==5)
		fprintf(fp,"接受命令暂停等状态\n");

	fprintf(fp,"当前位置:(%d,%d)\n",train[2].train_distance_2D.x,train[2].train_distance_2D.y);

	/*是否占用公共轨道*/
	fprintf(fp,"[公共轨道状态]:");

	if(IsInPubluic(train[0])==0&&IsInPubluic(train[1])==0&&IsInPubluic(train[2])==0)
		fprintf(fp,"空闲\n\n\n");
	else {
		if(IsInPubluic(train[0])==1)
			fprintf(fp,"被A车占用 ");
		if(IsInPubluic(train[1])==1)
			fprintf(fp,"被B车占用 ");
		if(IsInPubluic(train[2])==1)
			fprintf(fp,"被C车占用 ");
		fprintf(fp,"\n\n\n");
	}
}
