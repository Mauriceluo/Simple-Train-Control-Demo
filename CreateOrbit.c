/*
�� 
*/
#include"TrainHeadfile.h"
void LoadInfo(TrainInfo* train1,TrainInfo* train2,TrainInfo* train3,int CreatMap)
{
	int Y2=50,X3=50;
    int L1=250,W1=250,L2=150,W2=150,L3=150,W3=150;
//    int a[251][251]={0};
    int i,j,k;
    int state;
	
	if(CreatMap==1){
		/*���1*/
	printf("���1����:\n**��������1�ĳ��Ϳ�:"); 
    scanf("%d %d",&L1,&W1);
    while(L1<0||W1<0||L1>=1000||W1>=1000)
    {
    	printf("�������!\n**���������볤�Ϳ�:");
    	scanf("%d %d",&L1,&W1);
    }
    
    /*���2*/ 
    printf("���2����:\n**��������2���Ͻǵ��������(̽���):");
    scanf("%d",&Y2);
	while(Y2<0||Y2>W1-1)
	{
		printf("�������!\n**����������������:");
		scanf("%d",&Y2);
	} 
	printf("**��������2�ĳ��Ϳ�:");
	scanf("%d %d",&L2,&W2);
	while(Y2+W2>W1)
	{
		printf("�������!\n**����������ѡ��\n  1--�������볤�Ϳ�\n  2--�������������겢���볤��\n");
		
		printf("**����ѡ��:");
		scanf("%d",&state);
		while(state!=0&&state!=1)
		{
			printf("**�������!\n**��������ѡ��:");
			scanf("%d",&state);
		}
		if(state==0)
		{
     		printf("**��������2�ĳ��Ϳ�:");
	        scanf("%d %d",&L2,&W2);
		}
		else if(state==1)
		{
			printf("**��������2���Ͻǵ�������:");
            scanf("%d",&Y2);
            while(Y2<0||Y2>W1-1)
            {
	            printf("�������!\n**����������������:");
	            scanf("%d",&Y2);
            }
            printf("**��������2�ĳ��Ϳ�:");
            scanf("%d %d",&L2,&W2);
		}
	}
	
	/*���3*/
	printf("���3����:\n**��������3���Ͻǵ�ĺ�����(̽���):");
    scanf("%d",&X3);
	while(X3<0||X3>L1-1)
	{
		printf("�������!\n**����������������:");
		scanf("%d",&X3);
	} 
	printf("**��������3�ĳ��Ϳ�:");
	scanf("%d %d",&L3,&W3);
	while(X3+L3>L1)
	{
		printf("�������!\n**����������ѡ��\n  1--�������볤�Ϳ�\n  2--������������겢���볤��\n");
		printf("**����ѡ��:");
		scanf("%d",&state);
		while(state!=0&&state!=1)
		{
			printf("**�������!\n**��������ѡ��:");
			scanf("%d",&state);
		}
		if(state==0)
		{
     		printf("**��������3�ĳ��Ϳ�:");
	        scanf("%d %d",&L3,&W3);
		}
		else if(state==1)
		{
			printf("**��������3���Ͻǵ������:");
            scanf("%d",&X3);
            while(X3<0||X3>L1-1)
            {
	            printf("�������!\n**���������������:");
	            scanf("%d",&X3);
            }
            printf("**��������2�ĳ��Ϳ�:");
            scanf("%d %d",&L3,&W3);
		}
	} 
	}
	
/*if(CreatMap==0){
	L1=(*train1).train_orbit_L;
    W1=(*train1).train_orbit_W;
    
	L2=(*train2).train_orbit_L;
    W2=(*train2).train_orbit_W;
    
	L3=(*train3).train_orbit_L;
    W3=(*train3).train_orbit_W;
    Y2=(*train2).train_datum_point.y;
    X3=(*train3).train_detect_2D_1.x;
}	
	/*��ͼ*/
/*	printf("\n\n");
	for(j=0;j<=L1;j++)
	{
		a[j][0]=1;
		a[j][W1]=1;
	}
	for(j=L1;j<=L1+L2;j++)
	{
		a[j][Y2]=1;
		a[j][Y2+W2]=1;
	}
	for(j=X3;j<=X3+L3;j++)
	{
		a[j][W1+W3]=1;
	}
	j=0;
	for(k=0;k<=W1;k++)
	{
		a[0][k]=1;
		a[L1][k]=1;
	}
	for(k=Y2;k<=Y2+W2;k++)
	{
		a[L1+L2][k]=1;
	}
	for(k=W1;k<=W1+W3;k++)
	{
		a[X3][k]=1;
		a[X3+L3][k]=1;
	}
	for(j=0;j<=L1+L2;j++)
	{
		for(k=0;k<=W1+W3;k++)
		{
			if(a[j][k]==0)
			{
				printf("  ");
			}
			else if(a[j][k]==1)
			{
				printf("��");
			}
		}
		printf("\n");
	}
	
	/*����*/
	printf("��Ϊ�����ǳ��ļ��ٶ�,��̽������غϹ�����˵�\n\n"); 
	printf("\n\n\n���1:\n**��:%d\n**��:%d\n**��׼��:(0,0)\n",L1,W1);
	printf("**̽���1:(%d,%d)  ̽���2:(%d,%d)\n**̽���3:(%d,%d)  ̽���4:(%d,%d)\n\n",L1,Y2,L1,Y2+W2,X3,W1,X3+L3,W1); 
	
	printf("���2:\n**��:%d\n**��:%d\n**��׼��:(%d,%d)\n",L2,W2,L1,Y2);
	printf("**̽���1:(%d,%d)  ̽���2:(%d,%d)\n\n",L1,Y2,L1,Y2+W2);
	
	printf("���3:\n**��:%d\n**��:%d\n**��׼��:(%d,%d)\n",L3,W3,X3,W1);
    printf("**̽���1:(%d,%d)  ̽���2:(%d,%d)\n\n",X3,W1,X3+L3,W1);

    /*��ֵ*/
    (*train1).train_num=1;
    (*train2).train_num=2;
    (*train3).train_num=3;
    
    (*train1).train_orbit_L=L1;
    (*train1).train_orbit_W=W1;
    
	(*train2).train_orbit_L=L2;
    (*train2).train_orbit_W=W2;
    
	(*train3).train_orbit_L=L3;
    (*train3).train_orbit_W=W3;
    
	(*train1).train_datum_point.x=0;
    (*train1).train_datum_point.y=0;
    
	(*train2).train_datum_point.x=L1;
    (*train2).train_datum_point.y=Y2;
    
	(*train3).train_datum_point.x=X3;
    (*train3).train_datum_point.y=W1;
    
	
}
