/*
�ޡ�л 
*/
#include"TrainHeadfile.h"
int main()
{
	printf("///*��ӭ����С�𳵵�����*///\n"); 
	printf("\n*ֻ����:\n1.����С��\n2.���2��͹��3�����ȹ��1С�ҷֱ��ڹ��1�Ҳ���²�����*\n\n");

	/*���������*/
    TrainInfo train[5];//train[0]û����,Ϊ�˺ÿ���.
	int i; 
	FILE *setting;
	int temp;	
	if((setting=fopen("Ĭ������.ini","r"))==NULL)
		 {
			printf("Cannot open the file!");
			exit(0);
		 }
 	else for(temp=0; temp<5; temp++)
	{
		fread(&train[temp],sizeof(TrainInfo),1,setting);
	}
	fclose(setting);
	/*�𳵲���*/
	SetDefaultSet(train);
	char tempinput;
	LoadInfo(&train[1],&train[2],&train[3],0);  //��ͼ 
	for(temp=1; temp<4; temp++)
	{
		OutputSet(train,temp);
	}
	printf("�Ƿ�����Ĭ������?(Y/N)\n");
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
	
	/*���Ʋ���*/
	CompleteInfo(&train[1],&train[2],&train[3]); 
	
	/*ȷ����Ϣ*/
	EnsureInfo(&train[1]);
	EnsureInfo(&train[2]);
	EnsureInfo(&train[3]);
	time_temp1=train[1].train_pause_time;
    speed_temp1=train[1].train_speed;
    time_temp2=train[2].train_pause_time;
    speed_temp2=train[2].train_speed;
    time_temp3=train[3].train_pause_time;
    speed_temp3=train[3].train_speed;
 /*   if((setting=fopen("Ĭ������.ini","w+"))==NULL)
		 {
			printf("Cannot open the file!");
			exit(0);
		 }
 	else for(temp=0; temp<5; temp++)
	{
		fwrite(&train[temp],sizeof(TrainInfo),1,setting);
	}
	fclose(setting); */
	if((setting=fopen("��ǰ����.ini","w"))==NULL)
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
	if((setting=fopen("�������.ini","w+"))==NULL)
		 {
			printf("Cannot open the file!");
			exit(0);
		 }
	fclose(setting);
	/*ִ�в���*/ 
/*	printf("��ѡ��𳵵����в���:1--�쳵����  2--��������\n");
	scanf("%d",&run_method);
    while(run_method!=1&&run_method!=2)
	{
		printf("����������.1--�쳵����  2--��������\n");
		scanf("%d",run_method);
	} */
	run_method=1;//��� 
	if(run_method==1)
	{	Creatmap(train);
		printf("��ǰʹ�õ��ǿ쳵���в���.\n\n");
		AllControl(train);
	  /*�߳�1��1������
		�߳�2��2������
		�߳�3��3������
		�߳�4���û�����--�����Ӧ�̼߳��ɣ��޲��� 
		�߳�5��train[].train_distance_1D ����ȡģ��
		       �� length to coordinate.c �еĺ���ת��Ϊ2ά���� 
		�߳�6��ÿ�������������Ϣ��Ҫ���doc�� �ļ��������� */
	    
	
	
	
	}
	else//�������в��� 
	{
		//��ʱ����д 
	}
	
	
	
	
	return 0;
}


