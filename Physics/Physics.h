//*********** (C) Copyright 2009 David Martin All rights reserved. **********
//
// Purpose: Physics Class Header 
//
//****************************************************************************************

#include "../Entity/Entity.h"
#include "../Sprite/2dengine.h"
#include "../Rect/Rect.h"
#include <list>




namespace Viper2D
{

// ----------------------------------------------------------------
//  Name:           
//	Class:			cPhysicsObject
//  Description:    Physics Class
//  Arguments:      NONE
//  Return Value:   NONE
// ----------------------------------------------------------------	
	class cPhysicsObject//very very small physics engine
	{
	public:
		cPhysicsObject();//constructor
		~cPhysicsObject();//deconstructor

		void TestForCollisions();//test for collisions
		bool collision(std::list<cBaseEntity*>::iterator test1,std::list<cBaseEntity*>::iterator test2);
		//check for type of collisons needed
		bool collisionD(std::list<cBaseEntity*>::iterator test1,std::list<cBaseEntity*>::iterator test2);
		//distance formula for calculating collsion
		bool collisionBR(std::list<cBaseEntity*>::iterator test1,std::list<cBaseEntity*>::iterator test2);
		//bounding box formula for calculating collsion
		int collision_count;//collsion count var
	};
};

        