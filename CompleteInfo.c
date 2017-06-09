/*
罗 
*/ 
#include"TrainHeadfile.h"
 
void CompleteInfo(TrainInfo* train1,TrainInfo* train2,TrainInfo* train3)
{	
	int mod;
	patten=0;
	mod=(*train1).train_start_1D;
    if(mod>=0&&mod<=(*train1).train_orbit_L)
	{ 
		(*train1).train_start_2D.x=(*train1).train_datum_point.x+mod;
		(*train1).train_start_2D.y=(*train1).train_datum_point.y;
	} 
	
	else if(mod>(*train1).train_orbit_L&&mod<=(*train1).train_orbit_L+(*train1).train_orbit_W)
	{
		mod-=(*train1).train_orbit_L;
		(*train1).train_start_2D.x=(*train1).train_datum_point.x+(*train1).train_orbit_L;
		(*train1).train_start_2D.y=(*train1).train_datum_point.y+mod;
	}
	
	else if(mod>(*train1).train_orbit_L+(*train1).train_orbit_W&&mod<=(*train1).train_orbit_L*2+(*train1).train_orbit_W)
	{
		mod-=(*train1).train_orbit_L+(*train1).train_orbit_W;
		(*train1).train_start_2D.x=(*train1).train_datum_point.x+(*train1).train_orbit_L-mod;
		(*train1).train_start_2D.y=(*train1).train_datum_point.y+(*train1).train_orbit_W;
	}
	
	else
	{
		mod-=(*train1).train_orbit_L*2+(*train1).train_orbit_W;
		(*train1).train_start_2D.x=(*train1).train_datum_point.x;
		(*train1).train_start_2D.y=(*train1).train_datum_point.y+(*train1).train_orbit_W-mod;
	}
	
	
	
	
	mod=(*train2).train_start_1D;
    if(mod>=0&&mod<=(*train2).train_orbit_L)
	{ 
		(*train2).train_start_2D.x=(*train2).train_datum_point.x+mod;
		(*train2).train_start_2D.y=(*train2).train_datum_point.y;
	} 
	
	else if(mod>(*train2).train_orbit_L&&mod<=(*train2).train_orbit_L+(*train2).train_orbit_W)
	{
		mod-=(*train2).train_orbit_L;
		(*train2).train_start_2D.x=(*train2).train_datum_point.x+(*train2).train_orbit_L;
		(*train2).train_start_2D.y=(*train2).train_datum_point.y+mod;
	}
	
	else if(mod>(*train2).train_orbit_L+(*train2).train_orbit_W&&mod<=(*train2).train_orbit_L*2+(*train2).train_orbit_W)
	{
		mod-=(*train2).train_orbit_L+(*train2).train_orbit_W;
		(*train2).train_start_2D.x=(*train2).train_datum_point.x+(*train2).train_orbit_L-mod;
		(*train2).train_start_2D.y=(*train2).train_datum_point.y+(*train2).train_orbit_W;
	}
	
	else
	{
		mod-=(*train2).train_orbit_L*2+(*train2).train_orbit_W;
		(*train2).train_start_2D.x=(*train2).train_datum_point.x;
		(*train2).train_start_2D.y=(*train2).train_datum_point.y+(*train2).train_orbit_W-mod;
	}
	
	
	
	
	mod=(*train3).train_start_1D;
    if(mod>=0&&mod<=(*train3).train_orbit_L)
	{ 
		(*train3).train_start_2D.x=(*train3).train_datum_point.x+mod;
		(*train3).train_start_2D.y=(*train3).train_datum_point.y;
	} 
	
	else if(mod>(*train3).train_orbit_L&&mod<=(*train3).train_orbit_L+(*train3).train_orbit_W)
	{
		mod-=(*train3).train_orbit_L;
		(*train3).train_start_2D.x=(*train3).train_datum_point.x+(*train3).train_orbit_L;
		(*train3).train_start_2D.y=(*train3).train_datum_point.y+mod;
	}
	
	else if(mod>(*train3).train_orbit_L+(*train3).train_orbit_W&&mod<=(*train3).train_orbit_L*2+(*train3).train_orbit_W)
	{
		mod-=(*train3).train_orbit_L+(*train3).train_orbit_W;
		(*train3).train_start_2D.x=(*train3).train_datum_point.x+(*train3).train_orbit_L-mod;
		(*train3).train_start_2D.y=(*train3).train_datum_point.y+(*train3).train_orbit_W;
	}
	
	else
	{
		mod-=(*train3).train_orbit_L*2+(*train3).train_orbit_W;
		(*train3).train_start_2D.x=(*train3).train_datum_point.x;
		(*train3).train_start_2D.y=(*train3).train_datum_point.y+(*train3).train_orbit_W-mod;
	}
	
	(*train1).station1=(*train1).train_orbit_L+(*train2).train_datum_point.y+((*train2).train_orbit_W)/2;
    (*train1).station2=2*(*train1).train_orbit_L+(*train1).train_orbit_W-(*train3).train_datum_point.x-(*train3).train_orbit_L/2;
	
	if((*train1).train_direction==1)
	{	
		(*train1).train_detect_1D_1=(*train1).train_orbit_L+(*train2).train_datum_point.y-1;
        (*train1).train_detect_1D_2=(*train1).train_orbit_L+(*train2).train_datum_point.y+(*train2).train_orbit_W+1;
        (*train1).train_detect_1D_3=2*(*train1).train_orbit_L+(*train1).train_orbit_W-(*train3).train_datum_point.x-(*train3).train_orbit_L-1;
        (*train1).train_detect_1D_4=2*(*train1).train_orbit_L+(*train1).train_orbit_W-(*train3).train_datum_point.x+1;
      }
	else if((*train1).train_direction==2)
	{
		(*train1).train_detect_1D_1=2*(*train1).train_orbit_L+(*train1).train_orbit_W-(*train3).train_datum_point.x+1;
        (*train1).train_detect_1D_2=2*(*train1).train_orbit_L+(*train1).train_orbit_W-(*train3).train_datum_point.x-(*train3).train_orbit_L-1;
        (*train1).train_detect_1D_3=(*train1).train_orbit_L+(*train2).train_datum_point.y+(*train2).train_orbit_W+1;
        (*train1).train_detect_1D_4=(*train1).train_orbit_L+(*train2).train_datum_point.y-1;
	}
	
	
	(*train2).station1=2*(*train2).train_orbit_L+((*train2).train_orbit_W)*3/2;
	
	if((*train2).train_direction==1)
	{
        (*train2).train_detect_1D_1=2*(*train2).train_orbit_L+(*train2).train_orbit_W-1;
        (*train2).train_detect_1D_2=1;
	    (*train2).station1=2*(*train2).train_orbit_L+((*train2).train_orbit_W)*3/2;
	}
	else if((*train2).train_direction==2)
	{
		(*train2).train_detect_1D_1=1;
        (*train2).train_detect_1D_2=2*(*train2).train_orbit_L+(*train2).train_orbit_W-1;
	}
	
	(*train3).station1=((*train3).train_orbit_L)/2;
	
	if((*train3).train_direction==1)
	{
		(*train3).train_detect_1D_1=2*(*train3).train_orbit_L+2*(*train3).train_orbit_W-1;
        (*train3).train_detect_1D_2=(*train3).train_orbit_L+1;
	}
    else if((*train3).train_direction==2)
	{
	    (*train3).train_detect_1D_1=(*train3).train_orbit_L+1;
        (*train3).train_detect_1D_2=2*(*train3).train_orbit_L+2*(*train3).train_orbit_W-1;
	} 
	
	
	
	/*指针指向重合轨道火车*/
	(*train1).tptr1=&(*train2);
	(*train1).tptr2=&(*train3);
	(*train2).tptr1=&(*train1);
	(*train3).tptr1=&(*train1);  
	
	/*正方向为顺时针*/
	if((*train1).train_direction==2)
	(*train1).train_speed=-(*train1).train_speed;
	if((*train2).train_direction==2)
	(*train2).train_speed=-(*train2).train_speed;
	if((*train3).train_direction==2)
	(*train3).train_speed=-(*train3).train_speed;
	
	/*初始位置确定*/
	(*train1).train_distance_1D=(*train1).train_start_1D;
	(*train2).train_distance_1D=(*train2).train_start_1D;
	(*train3).train_distance_1D=(*train3).train_start_1D;
	
	/*初始化状态*/
    (*train1).train_state=-1;
	(*train2).train_state=-1;
	(*train3).train_state=-1;
	//state_temp1=-1;
	//state_temp2=-1;
	//state_temp3=-1;
	 
    /*next预处理*/
    (*train1).train_next=(*train1).train_distance_1D+(*train1).train_speed*0.1; 
    (*train2).train_next=(*train2).train_distance_1D+(*train2).train_speed*0.1;
    (*train3).train_next=(*train3).train_distance_1D+(*train3).train_speed*0.1;
	
	/*排除初始共轨情况*/
	int inPub;
	inPub=isBothInPub((*train1),(*train2));
	while(inPub==1)
	{
		printf("AB车同时在公共轨道!请重新输入AB的初始位置");
		scanf("%d %d",&(*train1).train_distance_1D,&(*train2).train_distance_1D);
		while((*train1).train_distance_1D<0||(*train2).train_distance_1D<0)
		{
			printf("请输入两个正数!");
			printf("请重新输入AB的初始位置");
		    scanf("%d %d",&(*train1).train_distance_1D,&(*train2).train_distance_1D);  
		}
		inPub=isBothInPub((*train1),(*train2)); 
	} 
	inPub=isBothInPub((*train1),(*train3));
	while(inPub==1)
	{
		printf("AC车同时在公共轨道!请重新输入AC的初始位置");
		scanf("%d %d",&(*train1).train_distance_1D,&(*train3).train_distance_1D);
		while((*train1).train_distance_1D<0||(*train3).train_distance_1D<0)
		{
			printf("请输入两个正数!");
			printf("请重新输入AC的初始位置");
		    scanf("%d %d",&(*train1).train_distance_1D,&(*train3).train_distance_1D);  
		}
		inPub=isBothInPub((*train1),(*train3)); 
	}
	/*时间初始化*/
	(*train1).time=0;
	(*train2).time=0;
	(*train3).time=0; 
	
	/*状态预处理*/
	if(IsInPubluic((*train1))==0&&IsNextInPubluic(*train1)==0) 
	{
		(*train1).train_state=0; 
	}
	if(IsInPubluic((*train2))==0&&IsNextInPubluic(*train2)==0) 
	{
		(*train2).train_state=0; 
	}
	if(IsInPubluic((*train3))==0&&IsNextInPubluic(*train3)==0) 
	{
		(*train3).train_state=0; 
	}
	
	if(IsInPubluic((*train1))==1&&((*train1).train_distance_1D==(*train1).station1||(*train1).train_distance_1D==(*train1).station2)) 
	{
		(*train1).train_state=2; 
	}
	if(IsInPubluic((*train2))==1&&(*train2).train_distance_1D==(*train2).station1) 
	{
		(*train2).train_state=2; 
	}
	if(IsInPubluic((*train3))==1&&(*train3).train_distance_1D==(*train3).station1) 
	{
		(*train3).train_state=2; 
	}
	
	if(IsInPubluic((*train1))==1&&((*train1).train_distance_1D<(*train1).station1&&IsNextInPubluic(*train1)==1||IsNextInPubluic(*train1)==1&&((*train1).train_distance_1D>(*train1).station1&&(*train1).train_distance_1D<(*train1).station2)))
		{
		(*train1).train_state=3; 
	}
	if(IsInPubluic((*train2))==1&&((*train2).train_distance_1D<(*train2).station1)&&IsNextInPubluic(*train2)==1)
	{
		(*train2).train_state=3; 
	}
	if(IsInPubluic((*train3))==1&&((*train3).train_distance_1D<(*train3).station1)&&IsNextInPubluic(*train3)==1)
	{
		(*train3).train_state=3; 
	}
	 
	if((IsInPubluic((*train1))==1&&((*train1).train_distance_1D>(*train1).station1||(*train1).train_distance_1D>(*train1).station2))||(IsInPubluic((*train1))==1&&IsNextInPubluic(*train1)==0))
	{
		(*train1).train_state=4; 
	}
	if((IsInPubluic((*train2))==1&&((*train2).train_distance_1D>(*train2).station1))||((IsInPubluic((*train2))==1&&IsNextInPubluic(*train2)==0)))
	{
		(*train2).train_state=4; 
	}
	if((IsInPubluic((*train3))==1&&((*train3).train_distance_1D>(*train3).station1))||((IsInPubluic((*train3))==1&&IsNextInPubluic(*train3)==0)))
	{
		(*train3).train_state=4; 
	}
	
	if((*train1).train_start_time!=0)
	{
		(*train1).train_state=5;
	}
	if((*train2).train_start_time!=0)
	{
		(*train2).train_state=5;
	} 
	if((*train3).train_start_time!=0)
	{
		(*train3).train_state=5;
	} 
	
	if(IsInPubluic((*train1))==0&&IsNextInPubluic(*train1)==1&&(*train1).train_state!=5&&(*train2).train_state!=5&&(*train3).train_state!=5)
	{
		if((*train1).train_direction==1&&(*train1).train_next<(*train1).train_detect_1D_2)//1车顺时针,与2 
	    {
    		if(IsInPubluic((*train2))==0&&IsNextInPubluic(*train2)==1)
			{
				if((*train1).train_speed>=(*train2).train_speed)
				{
					(*train1).train_state=3;
					(*train2).train_state=1;
				}
				else
				{
					(*train1).train_state=1;
					(*train2).train_state=3;
				}
			}
			else
			{
				if((*train2).train_state!=2&&(*train2).train_state!=3&&(*train2).train_state!=4)
			    {
    				(*train1).train_state!=2;
    			}
			} 
    	} 
    	else if((*train1).train_direction==1&&(*train1).train_next>(*train1).train_detect_1D_3)//A车顺时针，与3 
    	{
	    	if(IsInPubluic((*train3))==0&&IsNextInPubluic(*train3)==1)
			{
				if((*train1).train_speed>=(*train3).train_speed)
				{
					(*train1).train_state=3;
					(*train3).train_state=1;
				}
				else
				{
					(*train1).train_state=1;
					(*train3).train_state=3;
				}
			}
			else
			{
				if((*train3).train_state!=2&&(*train3).train_state!=3&&(*train3).train_state!=4)
			    {
    				(*train1).train_state!=2;
    			}
			} 
	    }
	    else if((*train1).train_direction==2&&(*train1).train_next<(*train1).train_detect_1D_3)//1逆时针与2
		{
			if(IsInPubluic((*train2))==0&&IsNextInPubluic(*train2)==1)
			{
				if((*train1).train_speed>=(*train2).train_speed)
				{
					(*train1).train_state=3;
					(*train2).train_state=1;
				}
				else
				{
					(*train1).train_state=1;
					(*train2).train_state=3;
				}
			}
			else
			{
				if((*train2).train_state!=2&&(*train2).train_state!=3&&(*train2).train_state!=4)
			    {
    				(*train1).train_state=2;
    			}
			} 
		} 
		else if((*train1).train_direction==2&&(*train1).train_next>(*train1).train_detect_1D_2)//1逆时针与3 
	    {
    		if(IsInPubluic((*train3))==0&&IsNextInPubluic(*train3)==1)
			{
				if((*train1).train_speed>=(*train3).train_speed)
				{
					(*train1).train_state=3;
					(*train3).train_state=1;
				}
				else
				{
					(*train1).train_state=1;
					(*train3).train_state=3;
				}
			}
			else
			{
				if((*train3).train_state!=2&&(*train3).train_state!=3&&(*train3).train_state!=4)
			    {
    				(*train1).train_state!=2;
    			}
			} 
    	} 
	}
	
    if(IsInPubluic((*train1))==1&&(*train1).train_state==5)
    {
    	if((*train1).train_distance_1D<(*train1).train_orbit_L+(*train1).train_orbit_W)
    	{
	    	if(IsNextInPubluic(*train2)==1)
	    	{
	    		(*train2).train_state==1;
	    	}
	    }
	    else
	    {
    		if(IsNextInPubluic(*train3)==1)
	    	{
	    		(*train3).train_state==1;
	    	}
    	}
    }
    else if(IsInPubluic((*train2))==1&&(*train2).train_state==5)
    {
    	if(IsNextInPubluic(*train1)==1&&(*train1).train_distance_1D<(*train1).train_orbit_L+(*train1).train_orbit_W)
	   	{
	   		(*train1).train_state==1;
	   	}
    }
    else if(IsInPubluic((*train3))==1&&(*train3).train_state==5)
    {
    	if(IsNextInPubluic(*train1)==1&&(*train1).train_distance_1D>(*train1).train_orbit_L+(*train1).train_orbit_W)
	   	{
	   		(*train1).train_state==1;
	   	}
    }
	
}
    
    
    
int isBothInPub(TrainInfo a,TrainInfo b)//1是 0不是 
{
	//a永远是1车，b是2或3车 
	if(a.train_direction==1)
	{
		if(b.train_num==2)
		{
			if(b.train_direction==1)//12顺时针 
			{
				if(a.train_distance_1D>a.train_detect_1D_1&&a.train_distance_1D<a.train_detect_1D_2&&(b.train_distance_1D>b.train_detect_1D_1||b.train_distance_1D<b.train_detect_1D_2))
			    {
    				return 1; 
    			}
    			else
    			{
			    	return 0;
			    }
			}
			else//1顺时针2逆时针 
			{
				if(a.train_distance_1D>a.train_detect_1D_1&&a.train_distance_1D<a.train_detect_1D_2&&(b.train_distance_1D>b.train_detect_1D_2||b.train_distance_1D<b.train_detect_1D_1))
			    {
    				return 1; 
    			}
    			else
    			{
			    	return 0;
			    }
			}
		}
		else//3车
		{
			if(b.train_direction==1)//13顺时针 
			{
				if(a.train_distance_1D>a.train_detect_1D_3&&a.train_distance_1D<a.train_detect_1D_4&&(b.train_distance_1D>b.train_detect_1D_1||b.train_distance_1D<b.train_detect_1D_2))
			    {
    				return 1; 
    			}
    			else
    			{
			    	return 0;
			    }
			}
			else//1顺时针3逆时针 
			{
				if(a.train_distance_1D>a.train_detect_1D_3&&a.train_distance_1D<a.train_detect_1D_4&&(b.train_distance_1D>b.train_detect_1D_2||b.train_distance_1D<b.train_detect_1D_1))
			    {
    				return 1; 
    			}
    			else
    			{
			    	return 0;
			    }
			}
		} 
	} 
	else//1逆时针 
	{
		if(b.train_num==2)
		{
			if(b.train_direction==1)//1逆时针2顺时针 
			{
				if(a.train_distance_1D>a.train_detect_1D_4&&a.train_distance_1D<a.train_detect_1D_3&&(b.train_distance_1D>b.train_detect_1D_1||b.train_distance_1D<b.train_detect_1D_2))
			    {
    				return 1; 
    			}
    			else
    			{
			    	return 0;
			    }
			}
			else//12逆时针 
			{
				if(a.train_distance_1D>a.train_detect_1D_4&&a.train_distance_1D<a.train_detect_1D_3&&(b.train_distance_1D>b.train_detect_1D_2||b.train_distance_1D<b.train_detect_1D_1))
			    {
    				return 1; 
    			}
    			else
    			{
			    	return 0;
			    }
			}
		}
		else//3车
		{
			if(b.train_direction==1)//1逆时针 3顺时针 
			{
				if(a.train_distance_1D>a.train_detect_1D_2&&a.train_distance_1D<a.train_detect_1D_1&&(b.train_distance_1D>b.train_detect_1D_1||b.train_distance_1D<b.train_detect_1D_2))
			    {
    				return 1; 
    			}
    			else
    			{
			    	return 0;
			    }
			}
			else//13逆时针 
			{
				if(a.train_distance_1D>a.train_detect_1D_2&&a.train_distance_1D<a.train_detect_1D_1&&(b.train_distance_1D>b.train_detect_1D_2||b.train_distance_1D<b.train_detect_1D_1))
			    {
    				return 1; 
    			}
    			else
    			{
			    	return 0;
			    }
			}
		} 
	}
}

int IsNextInPubluic(TrainInfo a)//1在 0不在 
{
	if(a.train_num==1)
	{
		if(a.train_direction==1)//1车顺时针 
		{
			if((a.train_next<a.train_detect_1D_2&&a.train_next>a.train_detect_1D_1)||(a.train_next<a.train_detect_1D_4&&a.train_next>a.train_detect_1D_3)) 
		    return 1;
		    else
		    return 0;
		}
		else//1车逆时针 
		{
			if((a.train_next<a.train_detect_1D_1&&a.train_next>a.train_detect_1D_2)||(a.train_next<a.train_detect_1D_3&&a.train_next>a.train_detect_1D_4))
		    return 1;
		    else
		    return 0;
		} 
	}
	else//2或3车 
	{
		if(a.train_direction==1)//2或3车顺时针 
		{
			if(a.train_next<a.train_detect_1D_2||a.train_next>a.train_detect_1D_1) 
		    return 1;
		    else
		    return 0;
		}
		else//2或3车逆时针 
		{
			if(a.train_next<a.train_detect_1D_1||a.train_next>a.train_detect_1D_2)
		    return 1;
		    else
		    return 0;
		} 
	}
}
