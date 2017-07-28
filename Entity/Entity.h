//========= Copyright © 2009, David Martin, All rights reserved. ============
//
// Purpose: Base Entity Class Header
//=============================================================================

#ifndef c_BASEENTITY_H
#define c_BASEENTITY_H
#include "../Global/Timer.h"
#include <strstream>
namespace Viper2D
{
// ----------------------------------------------------------------
//  Name:			ObjectType
//  Class:			
//  Description:    object types
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
enum ObjectType//object mode
{
	OBJECT_BACKGROUND = 999,//backdrop
	OBJECT_SPRITE = 1,//basic sprites
	OBJECT_MESH = 2,//basic mesh
	ISBASEOBJECT = 3,//base object
	ISBASECOMBATCHARACTER = 4,//enemy
	ISPLAYER =	5,//player
	ISWEAPOND = 6,//weapon
	ISAMMO = 7//ammo
};

// ----------------------------------------------------------------
//  Name:			RenderType
//  Class:			
//  Description:    render types
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
enum RenderType
{
	RENDER2D = 0,//for 2D objects
	RENDER3D = 1//for 3D objects
};

// ----------------------------------------------------------------
//  Name:			CollideType
//  Class:			
//  Description:    object collision types
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
enum CollideType
{
	ENTITY_SHOULD_NOT_COLLIDE = 0,//no collision
	ENTITY_SHOULD_COLLIDE = 1,//can collide
	ENTITY_SHOULD_RESPOND = 2//only responds to other collsion(static)
};

// ----------------------------------------------------------------
//  Name:			DamageState
//  Class:			
//  Description:    object damage types
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
enum DamageState
{
	DAMAGE_YES = 0,//has damage
	DAMAGE_EVENTS_ONLY = 1,
	DAMAGE_NO = 2//doesn't have damege
};

// ----------------------------------------------------------------
//  Name:			LifeState
//  Class:			
//  Description:    object life types
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
enum LifeState
{
	LIFE_ALIVE = 0,//object is alive
	LIFE_DYING = 1,//object is falling or is in death sequence
	LIFE_DEAD = 2//object is dead
};
	
// ----------------------------------------------------------------
//  Name:			
//  Class:			cBaseEntity
//  Description:    Base client side entity object
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
class cBaseEntity
{


public:
	


cBaseEntity(enum RenderType renderType);//constructor

~cBaseEntity();//deconstructor

int GetModelIndex();//get index of entity

void SetModelIndex( int index );//set the index for the entity
void SetModelName(std::string name );//set a name to to the entity
std::string GetModelName();//get the model name 
void setObjectType(ObjectType input);//set the object type
ObjectType getObjectType();//get the object type
bool lifetimeExpired();//check to see if the object has expired
int getLifeExpect();//get the time of expect life of an object
void setLifeExpect(int input);//set the time 
void setAlive(bool input);//set the object alive 
bool IsAlive();//check to see if object is alive
bool IsVisible();//check to see if obejct isvisible
void setVisible(bool input);//set the visiblity of an object
void setCollidable(bool value);//set collidable mode
bool checkCollidable();//check colliable mode
RenderType getRenderType();//get render type
void setRenderType(RenderType input);//set the render type
int	GetHealth();//get health of object
int	GetMaxHealth();//get maximum health
void setHealth(int input);//set health
void setMaxHealth(int input);//set maximum health
int GetShield();//get shield to protect object
int GetMaxShield();//get the maximum amount of shielding to protect the object
void setShield(int input);//set the current object shield
void setMaxShield(int input);//set the maximum shield.



	virtual void move() = 0;//move function based on type of entity
		virtual void animate() = 0;//animation function based on type of entity
		virtual void draw() = 0;//draw function beased on type of entity




private:
	 RenderType renderType;//render type
	 ObjectType objectType;//object type
	 Timer lifeTimer;//timer object
	 int lifeLength; //var to hold life length
	 int m_nModelIndex;//var to hold model index
	 std::string m_ModelName;//model name
	 bool alive;//flag to hold alive
	 bool visible;//visible flag
	 int iHealth;//health var
	 int m_iHealth;//maximum value
	 int isheild;//shield var
	 int m_isheild;//maximum shield
	 bool isCollidable;//colliable var
		



};
};

#endif