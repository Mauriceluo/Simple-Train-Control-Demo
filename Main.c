/*
罗、谢 
*/
#include"TrainHeadfile.h"
int main()
{
	printf("///*欢迎进入小火车的世界*///\n"); 
	printf("\n*只考虑:\n1.三辆小火车\n2.轨道2宽和轨道3长都比轨道1小且分别在轨道1右侧和下侧的情况*\n\n");

	/*定义变量区*/
    TrainInfo train[5];//train[0]没有用,为了好考虑.
	int i; 
	FILE *setting;
	int temp;	
	if((setting=fopen("默认数据.ini","r"))==NULL)
		 {
			printf("Cannot open the file!");
			exit(0);
		 }
 	else for(temp=0; temp<5; temp++)
	{
		fread(&train[temp],sizeof(TrainInfo),1,setting);
	}
	fclose(setting);
	/*火车参数*/
	SetDefaultSet(train);
	char tempinput;
	LoadInfo(&train[1],&train[2],&train[3],0);  //制图 
	for(temp=1; temp<4; temp++)
	{
		OutputSet(train,temp);
	}
	printf("是否载入默认设置?(Y/N)\n");
//	getchar();
	scanf("%c",&tempinput);
	if(tempinput!='Y') 
	{
		LoadInfo(&train[1],&train[2],&train[3],1);
		for(temp=1; temp<4; temp++)
		{
	//		InputSet(train,temp);
	;
		}
	}
	
	/*完善参数*/
	CompleteInfo(&train[1],&train[2],&train[3]); 
	
	/*确认信息*/
	EnsureInfo(&train[1]);
	EnsureInfo(&train[2]);
	EnsureInfo(&train[3]);
	time_temp1=train[1].train_pause_time;
    speed_temp1=train[1].train_speed;
    time_temp2=train[2].train_pause_time;
    speed_temp2=train[2].train_speed;
    time_temp3=train[3].train_pause_time;
    speed_temp3=train[3].train_speed;
 /*   if((setting=fopen("默认数据.ini","w+"))==NULL)
		 {
			printf("Cannot open the file!");
			exit(0);
		 }
 	else for(temp=0; temp<5; temp++)
	{
		fwrite(&train[temp],sizeof(TrainInfo),1,setting);
	}
	fclose(setting); */
	if((setting=fopen("当前数据.ini","w"))==NULL)
		 {
			printf("Cannot open the file!");
			exit(0);
		 }
	else
	for(temp=1; temp<4; temp++)
	{
		FileWrite(train,setting,temp);
	}
	fclose(setting);
	if((setting=fopen("输出数据.ini","w+"))==NULL)
		 {
			printf("Cannot open the file!");
			exit(0);
		 }
	fclose(setting);
	/*执行策略*/ 
/*	printf("请选择火车的运行策略:1--快车先行  2--快慢交替\n");
	scanf("%d",&run_method);
    while(run_method!=1&&run_method!=2)
	{
		printf("请重新输入.1--快车先行  2--快慢交替\n");
		scanf("%d",run_method);
	} */
	run_method=1;//猥琐 
	if(run_method==1)
	{	Creatmap(train);
		printf("当前使用的是快车先行策略.\n\n");
		AllControl(train);
	  /*线程1：1车运行
		线程2：2车运行
		线程3：3车运行
		线程4：用户挂起--挂起对应线程即可，无操作 
		线程5：train[].train_distance_1D 不断取模，
		       用 length to coordinate.c 中的函数转化为2维坐标 
		线程6：每秒输出，包括信息见要求的doc， 文件和命令行 */
	    
	
	
	
	}
	else//交替运行策略 
	{
		//暂时不用写 
	}
	
	
	
	
	return 0;
}


