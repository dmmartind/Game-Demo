//*********** (C) Copyright 2009 David Martin All rights reserved. **********
//
// Purpose: Particle Class Header 
//
//****************************************************************************************

#include "../Viper2D/Viper2D.h"
#include "../Sprite/2dengine.h"
//#include "../Global/Timer.h"
#include <vector>

namespace Viper2D
{

	class Particle//particle class
	{
	private:
		//typedef std::vector<_2DEngine*>::iterator iter;
		//std::vector<_2DEngine*> particles;
		typedef std::vector<_2DEngine*> Partical_Vector;//main vector queue object
        typedef std::vector<_2DEngine*>::iterator iter;//queue iterater
        Partical_Vector particles;//instance of the queue object

		Texture *image;//image object
		_vector position;//posision vector
		double direction;//direction var
		double length;//length var
		int max;//maximum number variables
		int alpha_min;//minimum alpha used
		int alpha_max;//maximum alpha used
		int minRed;//minimum red used
		int minGreen;//minimum green used
		int minBlue;//minimum blue used
		int maxRed;//maximum red used
		int maxGreen;//maximum green used
		int maxBlue;//maximum blue used
		int dither;//for random spread of the particle
		double velocity;//velocity var
		double scale;//scaling var
		bool isLoaded;//is loaded var

	public:
		Particle();//constructor
		virtual ~Particle();//deconstructor
		void Free();//free objects
		bool loadImage(char *filename);//load image for a base for the particle
		void Add();//add particle to the list
		void draw();//draw particles
		void update();//update the movement of the particles
		void setAlphaRange(int min, int max);//set the alpha
		void setColorRange(int red1, int green1, int blue1, int red2, int green2, int blue2);
		//set the color range
		void setPosition(double x, double y);//set the position with cordinate inputs
		void setPosition(_vector vec);//set the position with vector inputs
		_vector getPosition();//get position of the particle
		void setDirection(double angle);//set the direction 
		double getDirection();//get the direction
		void setMax(int num);//set maximum number of particles
		void setDither(int value);//set the dither for the random calculations for particle spread
		void setLength(double value);//set the length of the particle
		void setVelocity(double value);//set the velocity of the particle
		void setScale(double value);//set the scale of the particle
		
	};
};



	