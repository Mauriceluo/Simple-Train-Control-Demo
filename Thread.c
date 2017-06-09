/*
谢
*/
#include"TrainHeadfile.h"
#include"egg.h"
HANDLE TrianRunMutex1;
int btkey=0;
int KeyofTrain1=2,KeyofTrain2=2,KeyofTrain3=2,caidan=0;
int TAB,TBB,TCB;
int sumofrun=0;
DWORD WINAPI TRAIN1RUN(LPVOID lpParam) {
	TrainInfo *train =(TrainInfo *)lpParam;
	int a=1;
	if((*train).train_start_time!=0) {
		state_temp1=(*train).train_state;
		(*train).train_state=5;
		Sleep(1000*(*train).train_start_time);
		(*train).train_state=state_temp1;
	}
	while(1) {
		
			WaitForSingleObject(TrianRunMutex1,INFINITE);
		TAB=(*train).train_distance_1D;
		if(KeyofTrain1==1) {
			if((*train).train_state!=5) {
				state_temp1=(*train).train_state;
				//	printf("hehehe%d",state_temp1);
			}
			(*train).train_state=5;
			a=0;
			ReleaseMutex(TrianRunMutex1);
			continue;
		}
		if(KeyofTrain1==2&&a==0) {
			(*train).train_state=state_temp1;
			a=1;
		}
		if(KeyofTrain1==2&&a==1) {
			state_temp1=(*train).train_state;
		}
		clock_t start,finish;
		long long duration;
		start=clock();
		ControlTrain(train);
//		printf("A车距离：%d ",(*train).train_distance_1D);
		finish=clock();
		duration=finish-start;
		ReleaseMutex(TrianRunMutex1);
		Sleep(100-duration);
		}
	return 0;
}
DWORD WINAPI TRAIN2RUN(LPVOID lpParam) {
	TrainInfo *train =(TrainInfo *)lpParam;
	int a=1;
	if((*train).train_start_time!=0) {
		state_temp2=(*train).train_state;
		(*train).train_state=5;
		Sleep(1000*(*train).train_start_time);
		(*train).train_state=state_temp2;
	}
	while(1) {
		
			WaitForSingleObject(TrianRunMutex1,INFINITE);
		if(KeyofTrain2==1) {
			if((*train).train_state!=5) {
				state_temp2=(*train).train_state;
				a=0;
			}

			(*train).train_state=5;
			ReleaseMutex(TrianRunMutex1);
			continue;
		}
		if(KeyofTrain2==2&&a==0) {
			(*train).train_state=state_temp2;
			a=1;
		}
		if(KeyofTrain2==2&&a==1) {
			state_temp2=(*train).train_state;
		}
		clock_t start,finish;
		long long duration;
		start=clock();
//		printf("B车距离：%d ",(*train).train_distance_1D);
		ControlTrain(train);                                         /*一秒一次*/
		finish=clock();
		duration=finish-start;
		ReleaseMutex(TrianRunMutex1);
		Sleep(100-duration);
		
	}
	return 0;
}
DWORD WINAPI TRAIN3RUN(LPVOID lpParam) {
	TrainInfo *train =(TrainInfo *)lpParam;
	int a=1;
	if((*train).train_start_time!=0) {
		state_temp3=(*train).train_state;
		(*train).train_state=5;
		Sleep(1000*(*train).train_start_time);
		(*train).train_state=state_temp3;
	}
	while(1) {
	
			WaitForSingleObject(TrianRunMutex1,INFINITE);
		if(KeyofTrain3==1) {
			if((*train).train_state!=5) {
				state_temp3=(*train).train_state;
				a=0;
			}

			(*train).train_state=5;
			ReleaseMutex(TrianRunMutex1);
			continue;
		}
		if(KeyofTrain3==2&&a==0) {
			(*train).train_state=state_temp3;
			a=1;
		}
		if(KeyofTrain3==2&&a==1) {
			state_temp3=(*train).train_state;
		}
		clock_t start,finish;
		long long duration;
		start=clock();
//		printf("C车距离：%d ",(*train).train_distance_1D);
		ControlTrain(train);                                         /*一秒一次*/
		finish=clock();
		duration=finish-start;
		ReleaseMutex(TrianRunMutex1);
		Sleep(100-duration);
		
	}
}
/*DWORD WINAPI TRAINCONTROL(LPVOID lpParam) {
	TrainInfo *train =(TrainInfo *)lpParam;
	char ControlRun[999];
	while(1) {
		gets(ControlRun);
		int a=ControlRun[0],b=ControlRun[1];
		if(a==80&&b==65) {
			KeyofTrain1=1;
		}
		if(a==67&&b==65) {
			if((*train).train_distance_1D>=0&&(*train).train_distance_1D<=((*train).train_orbit_L+(*train).train_orbit_W)) {
				if(IsInPubluic((*(train+1)))==1) {
					printf("继续运行A可能与B车发生PY交易");
				} else
					KeyofTrain1=2;
			} else {
				if(IsInPubluic((*(train+2)))==1) {
					printf("继续运行A可能与C车发生PY交易");
				} else
					KeyofTrain1=2;
			}
		}
		if(a==80&&b==66) {
			KeyofTrain2=1;
		}
		if(a==67&&b==66) {
			if(IsInPubluic((*(train)))==1) {
				printf("继续运行B可能与A车发生PY交易");
			} else
				KeyofTrain2=2;

		}
		if(a==80&&b==67) {
			KeyofTrain3=1;
		}
		if(a==67&&b==67) {
			if(IsInPubluic((*(train)))==1) {
				printf("继续运行B可能与A车发生PY交易");
			} else
				KeyofTrain3=2;
		}
		if(a==80&&b=='Y') {
			caidan=1;
		}
	}
}*/
DWORD WINAPI OutPutFILENCMD(LPVOID lpParam) {
	int OutputTime=1;
	TrainInfo *train =(TrainInfo *)lpParam;
	while(1) {
		WaitForSingleObject(TrianRunMutex1,INFINITE);
		clock_t start,finish;
		long long duration;
		start=clock();
		PrintTrainInfo(train,OutputTime,caidan);
		finish=clock();
		duration=finish-start;
		OutputTime++;
		ReleaseMutex(TrianRunMutex1);
		Sleep(1000-duration);
	}
}
DWORD WINAPI ModDit(LPVOID lpParam) {
	TrainInfo *train =(TrainInfo *)lpParam;
	while(1) {
		WaitForSingleObject(TrianRunMutex1,INFINITE);
		clock_t start,finish;
		long long duration;
		start=clock();
		(*train).train_distance_1D=((*train).train_distance_1D)%(2*((*train).train_orbit_L+(*train).train_orbit_W));
		(*(train+1)).train_distance_1D=((*(train+1)).train_distance_1D)%(2*((*(train+1)).train_orbit_L+(*(train+1)).train_orbit_W));
		(*(train+2)).train_distance_1D=((*(train+2)).train_distance_1D)%(2*((*(train+2)).train_orbit_L+(*(train+2)).train_orbit_W));
		finish=clock();
		duration=finish-start;
		ReleaseMutex(TrianRunMutex1);
	}
}
DWORD WINAPI CreatCartoon(LPVOID lpParam){
    TrainInfo *train =(TrainInfo *)lpParam;
	clock_t start,finish;
	long long duration;
//	double tempx,tempy;
//	double TANX=0,TANY=900,TBNX=0,TBNY=0,TCNX=0,TCNY=0;
//	int SA=0,SB=0,SC=0;
//	int crrun=0,drrun=0;
	char timep[10];
	while(1)
	{	start=clock();
		btkey=1;
		itoa((*train).time/10,timep,10);
		SetActiveEgg(rail);
		SetPenColor(WHITE);
	//	printf("%d",sumofrun);
		if (run_method==1)
		{
			MovePen(570,180);
			DrawString("快车优先");
		} 
		else 
		{
			MovePen(570,180);
			DrawString("交替策略");
		}
		MovePen(570,120);
		DrawString(timep);
		SetActiveEgg(TA);
		if ((*train).train_direction==1)
		{	MoveEgg((*train).train_distance_2D.x*1.5,900-(*train).train_distance_2D.y*1.5);
/*			if((*train).train_distance_1D<=(*train).train_orbit_L){
	//			printf("%d",(*train).train_distance_1D);
				if((*train).train_distance_1D<(*train).train_orbit_L-1)
		        OffsetEgg((*train).train_speed*1.5,0);
		        if((*train).train_distance_1D==(*train).train_orbit_L-1&&crrun<5){
        			OffsetEgg((*train).train_speed*1.5,0);
        			crrun++;
        		}
				
			}
		
		//	printf("1");
			if(((*train).train_distance_1D<=(*train).train_orbit_L+(*train).train_orbit_W&&(*train).train_distance_1D>(*train).train_orbit_L)||(*train).train_distance_1D<=(*train).train_orbit_L-1){
//				printf("%d ",(*train).train_distance_1D);
			if(crrun==5)
			OffsetEgg(0,-(*train).train_speed*1.5);
			
			}
		//	OffsetEgg(0,-(*train).train_speed*1.5);
			if((*train).train_distance_1D>(*train).train_orbit_L+(*train).train_orbit_W&&(*train).train_distance_1D<=2*(*train).train_orbit_L+(*train).train_orbit_W){
				if((*train).train_distance_1D<(*train).train_orbit_W+(*train).train_orbit_L-1)
				OffsetEgg(-(*train).train_speed*1.5,0);
				if((*train).train_distance_1D==(*train).train_orbit_W+(*train).train_orbit_L-1&&drrun<5){
        			OffsetEgg(-(*train).train_speed*1.5,0);
        			drrun++;
        		}
			}
			
			if((*train).train_distance_1D<=((*train).train_orbit_L+(*train).train_orbit_W)*2&&(*train).train_distance_1D>2*(*train).train_orbit_L+(*train).train_orbit_W){
				if(drrun==5)
				OffsetEgg(0,(*train).train_speed*1.5);
			}
			*/
			SetActiveEgg(backdrop);
		} 
	else {
		;
	}
			SetActiveEgg(TB);
		if ((*(train+1)).train_direction==1)
		
		{//	printf("%f哈%f ",(*(train+1)).train_distance_2D.x*1.5,975-(*(train+1)).train_distance_2D.y*1.5);
			MoveEgg((*(train+1)).train_distance_2D.x*1.5-150-(*(train+1)).train_orbit_L*1.5,975-(*(train+1)).train_distance_2D.y*1.5);
		/*printf("%d ",(*(train+1)).train_distance_1D);
			if((*(train+1)).train_distance_1D<(*(train+1)).train_orbit_L){
//				printf("%d",sumofrun);
				
				OffsetEgg((*(train+1)).train_speed*1.5,0);
				//OffsetEgg((*train).train_speed*1.5,0);
			}
		
		//	printf("1");
			if((*(train+1)).train_distance_1D<(*(train+1)).train_orbit_L+(*(train+1)).train_orbit_W&&(*(train+1)).train_distance_1D>=(*(train+1)).train_orbit_L){
//				printf("%d ",(*(train+1)).train_distance_1D);
			OffsetEgg(0,-(*(train+1)).train_speed*1.5);
			
			}
		//	OffsetEgg(0,-(*train).train_speed*1.5);
			if((*(train+1)).train_distance_1D>=(*(train+1)).train_orbit_L+(*(train+1)).train_orbit_W&&(*(train+1)).train_distance_1D<2*(*(train+1)).train_orbit_L+(*(train+1)).train_orbit_W)
			OffsetEgg(-(*(train+1)).train_speed*1.5,0);
			if((*(train+1)).train_distance_1D<((*(train+1)).train_orbit_L+(*(train+1)).train_orbit_W)*2&&(*(train+1)).train_distance_1D>=2*(*(train+1)).train_orbit_L+(*(train+1)).train_orbit_W)
			OffsetEgg(0,(*(train+1)).train_speed*1.5);*/
			SetActiveEgg(backdrop);
		} 
	else {
		;
	}
			SetActiveEgg(TC);
		if ((*(train+2)).train_direction==1)
		{	
			MoveEgg((*(train+2)).train_distance_2D.x*1.5-75,1050-(*(train+2)).train_distance_2D.y*1.5+(*(train+2)).train_orbit_W*1.5);
		/* 
			if((*(train+2)).train_distance_1D<=(*(train+2)).train_orbit_L){
//				printf("%d",sumofrun);
				
				OffsetEgg((*(train+2)).train_speed*1.5,0);
				//OffsetEgg((*(train+2)).train_speed*1.5,0);
			}
		
		//	printf("1");
			if((*(train+2)).train_distance_1D<=(*(train+2)).train_orbit_L+(*(train+2)).train_orbit_W&&(*(train+2)).train_distance_1D>(*(train+2)).train_orbit_L){
//				printf("%d ",(*(train+2)).train_distance_1D);
			OffsetEgg(0,-(*(train+2)).train_speed*1.5);
			
			}
		//	OffsetEgg(0,-(*(train+2)).train_speed*1.5);
			if((*(train+2)).train_distance_1D>(*(train+2)).train_orbit_L+(*(train+2)).train_orbit_W&&(*(train+2)).train_distance_1D<=2*(*(train+2)).train_orbit_L+(*(train+2)).train_orbit_W)
			OffsetEgg(-(*(train+2)).train_speed*1.5,0);
			if((*(train+2)).train_distance_1D<=((*(train+2)).train_orbit_L+(*(train+2)).train_orbit_W)*2&&(*(train+2)).train_distance_1D>2*(*(train+2)).train_orbit_L+(*(train+2)).train_orbit_W)
			OffsetEgg(0,(*(train+2)).train_speed*1.5);*/
			SetActiveEgg(backdrop);
		} 
	else {
		;
	}
		if(IsInPubluic(*train)==0&&IsInPubluic(*(train+1))==0&&IsInPubluic(*(train+2))==0){
				MovePen(180,180);
				DrawString("无人占用");
				MovePen(180,100);
				DrawString("无人占用");
		}
	else {
		if(IsInPubluic(*train)==1){
				if((*train).train_distance_1D<=(*train).train_orbit_W+(*train).train_orbit_L){
					MovePen(180,180);
					DrawString("A车占用");
					if(IsInPubluic(*(train+1))==0){
					MovePen(180,180);
				DrawString("无人占用");
				}	
				} 
			else{
				MovePen(180,100);
				DrawString("A车占用");
				if(IsInPubluic(*(train+2))==0){
					MovePen(180,100);
				DrawString("无人占用");
				}
			}
		}
			
		if(IsInPubluic(*(train+1))==1)
			{
				MovePen(180,180);
					DrawString("B车占用");
					if(IsInPubluic(*(train+2))==0){
					MovePen(180,100);
				DrawString("无人占用");
				}
		}
		if(IsInPubluic(*(train+2))==1)
			{
				if(IsInPubluic(*(train+1))==0){
					MovePen(180,180);
				DrawString("无人占用");
				}
				
			MovePen(180,100);
				DrawString("C车占用");
		}
	}
		MovePen(850,180);
		char pauseA[10];
		itoa((*train).timeofkey,pauseA,10);
		DrawString(pauseA);
		MovePen(850,140);
		char pauseB[10];
		itoa((*(train+1)).timeofkey,pauseB,10);
		DrawString(pauseB);
		MovePen(850,100);
		char pauseC[10];
		itoa((*(train+2)).timeofkey,pauseC,10);
		DrawString(pauseC);
		finish=clock();
		duration=finish-start;
		Update();
		Sleep(100-duration);
	}
}
DWORD WINAPI TRAINCONTROL(LPVOID lpParam) 
{
	int t1;
	int t2;
	int t3;
	double Xk,Yk;
	EVENT_TYPE event; 
	TrainInfo *train =(TrainInfo *)lpParam;
	while (event=WaitForEvent()!=EXIT) 
	{
	    if (IsKeyDown(VK_LBUTTON)) 
	    {	
			Xk=GetMouseX(), 
			Yk=GetMouseY();
			if ((Xk>=1200)&&(Xk<=1300)&&(Yk>=670)&&(Yk<=750))
			{		KeyofTrain1=1;
					printf("A车被用户暂停\n");
			}
			else if ((Xk>=1320)&&(Xk<=1420)&&(Yk>=670)&&(Yk<=750))
			{				
					KeyofTrain1=2;
					printf("A车重新启动\n");
			}
			else if ((Xk>=1200)&&(Xk<=1300)&&(Yk>=580)&&(Yk<=660))
			{
				KeyofTrain2=1;
				printf("B车被用户暂停\n");
			}
			else if ((Xk>=1320)&&(Xk<=1420)&&(Yk>=580)&&(Yk<=660))
			{
					KeyofTrain2=2;
					printf("B车重新启动\n");
			}
			else if ((Xk>=1200)&&(Xk<=1300)&&(Yk>=490)&&(Yk<=570))
			{
				KeyofTrain3=1;
				printf("C车被用户暂停\n");
			}
			else if ((Xk>=1320)&&(Xk<=1420)&&(Yk>=490)&&(Yk<=570))
			{
					KeyofTrain3=2;
					printf("C车重新启动\n");
			}
			else if ((Xk>=1200)&&(Xk<=1300)&&(Yk>=400)&&(Yk<=480))
			{
				run_method=1; 
				printf("控制策略切换为快车优先策略。\n");
			}
			else if ((Xk>=1320)&&(Xk<=1420)&&(Yk>=400)&&(Yk<=480))
			{
				run_method=2; 
				printf("控制策略切换为交替策略。\n");
			}
			
		}
	}
	printf("用户已退出!"); 
	_exit(0);
}
void AllControl(TrainInfo train[4]) {
	HANDLE Thread1,Thread2,Thread3,Thread4,Thread5,Thread6,Thread7;
	TrianRunMutex1=CreateMutex(NULL,FALSE,"KeyofTrain1");
	SetAutoUpdate(0);
	Thread5=CreateThread(NULL,0,CreatCartoon,&train[1],0,0);
	Sleep(3);
	Thread6=CreateThread(NULL,0,ModDit,&train[1],0,0);
	Sleep(3);
	Thread1=CreateThread(NULL,0,TRAIN1RUN,&train[1],0,0);
	Sleep(3);
	Thread2=CreateThread(NULL,0,TRAIN2RUN,&train[2],0,0);
	Sleep(3);
	Thread3=CreateThread(NULL,0,TRAIN3RUN,&train[3],0,0);
	Sleep(3);
	Thread4=CreateThread(NULL,0,TRAINCONTROL,&train[1],0,0);
	Sleep(5);	
	Thread7=CreateThread(NULL,0,OutPutFILENCMD,&train[1],0,0);
	CloseHandle(Thread1);
	CloseHandle(Thread2);
	CloseHandle(Thread3);
	CloseHandle(Thread4);
	CloseHandle(Thread5);
	Sleep(10000000);

}

