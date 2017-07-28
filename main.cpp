#define _CRT_RAND_S
#include <stdlib.h>

#include ".\Viper2D\Viper2D.h"
#include ".\Sprite\2dengine.h"
#include ".\State\StateMgr.h"
#include ".\Audio\Audio.h"
#include ".\Console\Console.h"
#include ".\Math\math.h"
#include ".\Vector\vector.h"
#include ".\Physics\Physics.h"








using namespace Viper2D;

eStateManager *state= new eStateManager();
Audio *audio;
CGameConsole *console;
cMath math;
_vector* ship_vector;
_vector* center;
_vector* bcenter;
Texture *rocket_image;
Texture *asteroid_image;
Texture *explosion_image;
DWORD timer_start=0;
cFontManager* font;
std::ostringstream ostr;
cPhysicsObject *physics;
_2DEngine *rocket;
double _x=0,_y=0, angle_count=0;
int current_count=0;
float ship_angle=0;
int height=0, width=0;
int score=0;





void moveAngleLeft(int);
void moveAngleRight(int);
bool loadMission();
void Fire();
void updateConsole();
void addAsteroid();







int game_preload() 
{
	g_engine->setAppTitle("Space Rocks Demo");
	g_engine->setFullscreen(false);
	g_engine->setScreenWidth(1024);
	g_engine->setScreenHeight(768);
	g_engine->setColorDepth(32);

	state->setState(GAME_PRELOAD);


	

	
	return 1;

}

int game_init(HWND) 
{ 
	//load background image
	_2DEngine *background = new _2DEngine();
	if (!background->loadImage("spacedust_title.bmp")) {
		g_engine->message("Error loading spacedust_title.bmp");
		return false;
	}
	background->setObjectType(OBJECT_BACKGROUND);
	background->setCollidable(false);
	background->setCollision(COLLISION_NONE);
	background->setAlive(true);
	background->setVisible(true);
	g_engine->addEntity(background);
	physics = new cPhysicsObject();
	state->setState(GAME_INIT);
	
	return 1;

}
void game_update()
{
	unsigned int    number;
	//update console info
	updateConsole();
	if((state->getState() == GAME_MISSION))
	{
		
		if(g_engine->getEntityCount(ISWEAPOND) == 0)
		{
			rand_s(&number);
			number=number / 100000000;
			for(int x = 0; x < (signed)number; x++)
			{
				addAsteroid();
			}
		}
	}
}
void game_end()
{

delete state;
delete audio;
delete console;
delete ship_vector;
delete center;
delete bcenter;
delete rocket;
//delete rocket_image;
delete asteroid_image;
delete explosion_image;
delete font;
delete physics;








}


//external variables and functions




 void game_render3d()
{
	g_engine->ClearScene(D3DCOLOR_XRGB(0,0,80));
    
	
	
}

 void game_render2d()
{
	if(state->getState() == GAME_MISSION)
	{	
		ostr.str(""); 
		ostr <<"Score::"<<score;
		font->writeText(1,g_engine->getScreenHeight()-20,"Press ~ or F12 to toggle the Console",D3DCOLOR_XRGB(255,255,255));
		font->writeText(g_engine->getScreenWidth()-150,g_engine->getScreenHeight()-20,ostr.str(),D3DCOLOR_XRGB(255,255,0));
		
		//draw console
		if (console->IsConsoleVisible())
			console->Activate();
	}



}
 void game_keyPress(int input)/////////////////
{
	
if(state->getState() == GAME_MISSION)
{
	switch(input)
	{
		case DIK_DOWN:
			ship_vector->set(0.0,5.0,0.0);
		break;
		case DIK_UP:
			ship_vector->set(0.0,-5.0,0.0);
		break;
		case DIK_LEFT:
			ship_vector->set(-5.0,0.0,0.0);
		break;
		case DIK_RIGHT:
			ship_vector->set(5.0,0.0,0.0);
		break;
		case DIK_A:
			current_count--;
			if(current_count < 0)
				current_count= 16 + current_count;
			if(current_count > 16)
				current_count=current_count-16;
			moveAngleLeft(current_count);
			
		break;
		case DIK_S:
			current_count++;
			if(current_count < 0)
				current_count= 16 + current_count;
			if(current_count > 16)
				current_count=current_count-16;
			moveAngleRight(current_count);
			
			
		break;
		case DIK_SPACE:
			if ( timeGetTime() > timer_start + 75 )
			{
				Fire();
			}
		break;
	}
}





}
 void game_keyRelease(int input)///////////////
{
	switch (input) {
		case DIK_ESCAPE:
			g_engine->Close();
			break;

		case DIK_F12:
		case DIK_GRAVE:
			{
				if((state->getState() == GAME_MISSION))
				{
					if(console->IsConsoleVisible())
					{
						console->Hide();
					}
					else
						console->Show();
				}
			}break;

		case DIK_F2:
			g_engine->setMaximizeProcessor( !g_engine->getMaximizeProcessor() );
			break;

		


		case DIK_RETURN:
			if(state->getState() == GAME_INIT)
				loadMission();
			break;
	}
}





 void game_mouseButton(int input)///////////////
{




}

 void game_mouseButtonR(int input)///////////////
{




}



 void game_mouseMotion(int x,int y)//////////////
{




}
 void game_mouseMove(int x,int y)/////////////////
{



}
 void game_mouseWheel(int wheel)///////////////////
{




}
 void game_GamePadPress(int input)
{



}

 void game_POVPress(int input)
{



}
 void gamepadLeftThumbMove(long inputx,long inputy)
{



}
 void gamepadRightThumbMove(long inputRX,long inputRY)
{



}
 void game_XBOXPadPress(char *input)
{




}
 void gamepadLeftTriggerMove(long device)
{




}
 void gamepadRightTriggerMove(long device)
{


}

void game_entityUpdate(Viper2D::cBaseEntity* entity)
{


}

void game_entityRender(Viper2D::cBaseEntity* entity)
{
	 double y=0,x=0, rot=0;
    _2DEngine *ship, /**rocket,*/ *asteroid; //Mando said not needed
    _vector position;

    switch(entity->getObjectType()) 
    {
        case ISPLAYER:
            ship = (_2DEngine*)entity;
            position = ship->getPosition();
            y = position.gety() + ship_vector->gety();
            if (y < -15)
			{
                y = -15;
            }
			if (y > g_engine->getScreenHeight()-50)
			{
                y = g_engine->getScreenHeight()-50;
            }
            position.sety((float)y);
            ship->setPosition( position );
			ship_vector->sety(0.0);
//-----------------------------------------------------------
			x = position.getx() + ship_vector->getx();
            if (x < 0)
			{
                x = 0;
			}
			if (x > g_engine->getScreenWidth()-65)
			{
				x = g_engine->getScreenWidth()-65;
            }
            position.setx((float)x);
            ship->setPosition( position );
			ship_vector->setx(0.0);
//-----------------------------------------------------------------
			
			//rot= ship->getRotation() + ship_vector->getRotation();
			//ship->setRotation(rot);
			//ship_vector->setRotation(0);
			//ship_vector->setRotation(0);
			_x=ship->getx();
			_y=ship->gety();
			center->sety((float)(ship->gety()+ 32));
			center->setx((float)(ship->getx() + 32));
			break;

        case ISAMMO:
            rocket = (_2DEngine*)entity;
			if (rocket->getx() > g_engine->getScreenWidth()-25 || rocket->getx() < 25)
                rocket->setAlive(false);
			if (rocket->gety() > g_engine->getScreenHeight()-25 || rocket->gety() < 25)
                rocket->setAlive(false);            
            break;

		case ISWEAPOND:
			asteroid = (_2DEngine*)entity;
			if (asteroid->getx() > g_engine->getScreenWidth()+25 || asteroid->getx() < -25)
              asteroid->setAlive(false);
			if (asteroid->gety() > g_engine->getScreenHeight()+25 || asteroid->gety() < -25)
                asteroid->setAlive(false);            
            break;

		
    }

}


void collisionTest()
{
	physics->TestForCollisions();
}

bool loadMission()
{
	state->setState(GAME_MISSION);
	g_engine->deleteEntity(OBJECT_BACKGROUND);
	//create the background
    _2DEngine *background = new _2DEngine();
    background->setObjectType(OBJECT_BACKGROUND);
    if (!background->loadImage("spacedust.bmp")) {
        g_engine->message("Error loading spacedust.bmp");
        return false;
    }
	background->setAlive(true);
	background->setVisible(true);
    g_engine->addEntity( background );

    //create the console
    console = new CGameConsole();
	if (!console->Initialize()) {
        g_engine->message("Error initializing console");
        return false;
    }
/*
    //create ship sprite
    _2DEngine *ship = new _2DEngine();
    ship->setObjectType(ISPLAYER);
    if (!ship->loadImage("spaceship80.tga",D3DCOLOR_XRGB(255,0,0))) 
	{
      g_engine->message("Error loading spaceship.tga");
       return false;
    }
	ship->setColor(D3DCOLOR_XRGB(255,255,255));
	ship->setAlive(true);
	ship->setVisible(true);
    ship->setRotation(math.toRadians(0) );
	ship->setPosition( 10, (g_engine->getScreenWidth())/2-32 );
	ship->setScale(.50);
    g_engine->addEntity(ship);
*/
	
	
	Texture *ship_image;

	//load asteroid image
    ship_image = new Texture();
    ship_image->Load("ship.bmp");

	_2DEngine *ship;
    //create a new asteroid sprite
        ship = new _2DEngine();
        ship->setObjectType(ISPLAYER);
        ship->setImage(ship_image);
        ship->setTotalFrames(16);
        ship->setColumns(8);
        ship->setSize(64,64);
		ship->setPosition(250, 250 );
        ship->setFrameTimer(1);//rand() % 1 );
        ship->setCurrentFrame(current_count);
		ship->setVisible(true);
		ship->setAlive(true);
		ship->setCollidable(false);
		ship->setCollision(COLLISION_NONE);
		//if (rand()%2==0)
		ship->setFrameControl(0);
		center = new _vector();
		bcenter = new _vector();
		height=ship->getHeight();
		width=ship->getWidth();
		
		
		
        //ship->setVelocity( (float)(rand()%10)/10.0f, (float)(rand()%10)/10.0f );
        //add asteroid to the entity manager
        g_engine->addEntity(ship);
    

	
	
	


    //load bullet image
    rocket_image = new Texture();
    if (!rocket_image->Load("bullet.png",D3DCOLOR_XRGB(255,255,255))) {
        g_engine->message("Error loading bullet.png");
        return false;
    }

	//load bullet image
	//rocket_image= new Particle();
    //rocket_image->loadImage("bullet.png");
    //rocket_image->setPosition(100,300);
    //rocket_image->setDirection(0);
    //rocket_image->setMax(500);
    //rocket_image->setMax(500);
    //rocket_image->setMax(500);
    //rocket_image->setAlphaRange(100,255);
	//rocket_image->setDither(30);
    //rocket_image->setVelocity(2.0);
    //rocket_image->setLength(250);
///////////////////////////////////////////////////////////////////////////////////////////////////////
    //load asteroid image
    asteroid_image = new Texture();
	if (!asteroid_image->Load("asteroid.tga")) {
        g_engine->message("Error loading asteroid.tga");
        return false;
    }
	
   
////////////////////////////////////////////////////////////////////////////////////////////////////////
    //load the explosion image
    explosion_image = new Texture();
    if (!explosion_image->Load("explosion.tga")) {
        g_engine->message("Error loading explosion");
        return false;
    }

    //load the Verdana10 font
    font = new cFontManager();
    if (!font->loadImage("verdana10.tga")) {
        g_engine->message("Error loading verdana10.tga");
        return false;
    }
	if (!font->loadFontData("verdana10.dat")) {
        g_engine->message("Error loading verdana10.dat");
        return false;
    }
    font->setColumns(16);
	font->setFontSize(20,16);

    //load sound effects
	audio = new Audio();
	audio->Init(g_engine->getWindowHandle());

	if (!audio->Load("fire.wav","fire")) {
        g_engine->message("Error loading fire.wav");
        return false;
    }

	if (!audio->Load("explode.wav","boom")) {
        g_engine->message("Error loading boom.wav");
        return false;
    }

	//if (!audio->Load("impact.wav","impact")) {
    //    g_engine->message("Error loading impact.wav");
    //    return false;
    //}
	ship_vector = new _vector();
	
	






    //maximize processor
    g_engine->setMaximizeProcessor(true);

	g_engine->setKeyContinuous(true);
	

	return true;


}

void Fire()
{

	double x=0,y=0;
	//get the ship from the entity manager
	cBaseEntity* entity;
	std::list<cBaseEntity*>::iterator it = g_engine->findEntity(ISPLAYER);
	entity = *it;
	_2DEngine* ship = (_2DEngine*)entity;
	

    if (!ship)
    {
        g_engine->message("Error locating ship in entity manager!","ERROR");
        g_engine->Close();
    }

	
    rocket = new _2DEngine();
    rocket->setObjectType(ISAMMO);
	rocket->setImage(rocket_image);
	rocket->setFrameTimer(1);
    rocket->setCollidable(true);
	rocket->setCollision(COLLISION_DIST);
	rocket->setAlive(true);
	rocket->setVisible(true);
	bcenter->sety((center->gety()) + (rocket_image->getHeight()/2)-20);
	bcenter->setx((center->getx()) + (rocket_image->getWidth()/2)-20);
    double angle = math.toRadians(45);
    rocket->setRotation(0);
    //rocket->setRotation( math.toRadians(120) );
	//rocket->setDirection(25);
	
	
	x = bcenter->getx();
		y = bcenter->gety();
	

	//double x = ship->getx() + ship->getWidth();
	//double y = ship->gety() + 0;///2-rocket->getHeight()/2;
    rocket->setPosition(x,y);

    double vx = math.LinearVelocityX(ship_angle);
    double vy = math.LinearVelocityY(ship_angle);
	//double vx =50;
	//double vy =-50;
	//float PI= 3.14159f;
	//float fang = (270)*(PI/180.0f);

	 
	//double vx = -cos(fang)*2;
	//double vy = -sin(fang)*2;
	rocket->setVelocity(vx*2, vy*2);

    g_engine->addEntity(rocket);

	
	timer_start=timeGetTime();

}

void updateConsole()
{
	//cBaseEntity* entity;
	//std::list<cBaseEntity*>::iterator it = g_engine->findEntity(ISPLAYER);
	//entity = *it;
	//_2DEngine* ship = (_2DEngine*)entity;
	if((state->getState() == GAME_MISSION))
	{
		if((console->IsConsoleVisible() == true))
		{
			console->Clear();
			static Timer timer;
			if (!timer.stopwatch(12))
				return;
			console->Printf(g_engine->getVersionText(), 0);
			ostr.str(""); 
			ostr << "CORE : " << (float)(1000.0f/g_engine->getFrameRate_core()) 
				<< " ms (" << g_engine->getFrameRate_core() << " fps)";
			console->Printf(ostr.str(), 2);

			console->Printf("Press F2 to toggle Processor Throttling", 27);
			ostr.str("");
				ostr << "Entities: " << g_engine->getEntityCount(OBJECT_SPRITE);
			console->Printf(ostr.str(), 29);
			ostr.str("");
			ostr << "Ship X Position: " << _x;
			console->Printf(ostr.str(), 30);
			ostr.str("");
				ostr << "Ship Y Position: " << _y;
			console->Printf(ostr.str(), 31);
			ostr.str("");
				ostr << "Ship angle: " << ship_angle;
			console->Printf(ostr.str(), 32);
			ostr.str("");
				ostr << "Ship center: " << center->getx() << "     "<<center->gety();
			console->Printf(ostr.str(), 33);
			ostr.str("");
				ostr << "Ship atr: " << height << "     "<<width;
			console->Printf(ostr.str(), 34);
			ostr.str("");
			ostr << "rocket center: " << bcenter->getx() << "     "<<bcenter->gety();
			console->Printf(ostr.str(), 35);
			ostr.str("");
			ostr << "astroid count: " << g_engine->getEntityCount(ISWEAPOND);
			console->Printf(ostr.str(), 35);
			ostr.str("");
			ostr << "Collision Count: " <<physics->collision_count;
			console->Printf(ostr.str(), 35);
			//ostr << "Frame Timer: " <<ship->getFrameTimer();
			//console->Printf(ostr.str(), 35);
			


			
		}
	}
}



void moveAngleLeft(int input)
{

	//get the ship from the entity manager
	cBaseEntity* entity;
	std::list<cBaseEntity*>::iterator it = g_engine->findEntity(ISPLAYER);
	entity = *it;
	_2DEngine* ship = (_2DEngine*)entity;

	ship->setCurrentFrame(input);
	ship_angle=(float)(input*(360/ship->getTotalFrames()));

	ship->setAngle(ship_angle);

	





}


void moveAngleRight(int input)
{
	//get the ship from the entity manager
	cBaseEntity* entity;
	std::list<cBaseEntity*>::iterator it = g_engine->findEntity(ISPLAYER);
	entity = *it;
	_2DEngine* ship = (_2DEngine*)entity;

	ship->setCurrentFrame(input);
	ship_angle=(float)(input*(360/ship->getTotalFrames()));

	ship->setAngle(ship_angle);




}

void addAsteroid()
{
    //add an asteroid
    _2DEngine *asteroid = new _2DEngine();
    asteroid->setObjectType(ISWEAPOND);
    asteroid->setVelocity(-3.0, 0);
	asteroid->setPosition(50+rand()%g_engine->getScreenWidth(),50+rand()%(g_engine->getScreenHeight()-150));
    asteroid->setImage(asteroid_image);
    asteroid->setTotalFrames(64);
    asteroid->setColumns(8);
    asteroid->setSize(60,60);
    asteroid->setFrameTimer( rand() % 100 );
    asteroid->setCurrentFrame( rand() % 64 );
    if (rand()%2==0)
		asteroid->setFrameControl(-1);
	asteroid->setAlive(true);
	asteroid->setVisible(true);
	asteroid->setCollidable(true);
	asteroid->setCollision(COLLISION_DIST);
    g_engine->addEntity( asteroid );
}

void game_entityCollision(std::list<Viper2D::cBaseEntity*>::iterator test1,std::list<Viper2D::cBaseEntity*>::iterator test2)
{	
	//physics->collision_count++;


	_2DEngine *a = (_2DEngine*)*test1;
	_2DEngine *b = (_2DEngine*)*test2;

	if (((a->getObjectType() == ISWEAPOND) && (b->getObjectType() == ISAMMO)) || ((b->getObjectType() == ISWEAPOND) && (a->getObjectType() == ISAMMO)) )
    {
           	physics->collision_count++;
			score++;
			//create an explosion
            _2DEngine *expl = new _2DEngine();
            expl->setObjectType(ISBASEOBJECT);
            expl->setImage(explosion_image);
            expl->setColumns(6);
            expl->setCollidable(false);
            expl->setSize(128,128);
            double x = a->getPosition().getx();
            double y = a->getPosition().gety();
            expl->setPosition(x-32,y-32);
            expl->setTotalFrames(30);
            expl->setFrameTimer(40);
			expl->setLifeExpect(1000);
			expl->setAlive(true);
			expl->setVisible(true);
			expl->setCollidable(false);
			expl->setCollision(COLLISION_NONE);
            g_engine->addEntity( expl );

            //remove the asteroid
            a->setAlive(false);

            //remove the bullet
            b->setAlive(false);

            //play explosion sound
              audio->Play("boom");
	}
}