/*
刘 
*/ 
#include"TrainHeadfile.h" 

Position Length_To_Coordinate(TrainInfo a)//长度换成坐标 
{
	int mod;
	Position train_position;//2D
	/*取模*/ 
	mod=a.train_distance_1D%(a.train_orbit_L*2+a.train_orbit_W*2);
	
	if(mod>=0&&mod<=a.train_orbit_L)
	{ 
		train_position.x=a.train_datum_point.x+mod;
		train_position.y=a.train_datum_point.y;
	} 
	
	else if(mod>a.train_orbit_L&&mod<=a.train_orbit_L+a.train_orbit_W)
	{
		mod-=a.train_orbit_L;
		train_position.x=a.train_datum_point.x+a.train_orbit_L;
		train_position.y=a.train_datum_point.y+mod;
	}
	
	else if(mod>a.train_orbit_L+a.train_orbit_W&&mod<=a.train_orbit_L*2+a.train_orbit_W)
	{
		mod-=a.train_orbit_L+a.train_orbit_W;
		train_position.x=a.train_datum_point.x+a.train_orbit_L-mod;
		train_position.y=a.train_datum_point.y+a.train_orbit_W;
	}
	
	else
	{
		mod-=a.train_orbit_L*2+a.train_orbit_W;
		train_position.x=a.train_datum_point.x;
		train_position.y=a.train_datum_point.y+a.train_orbit_W-mod;
	}
	
	return train_position;
}
