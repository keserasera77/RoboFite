#pragma once

class Vector3;

class Robo {
  public : 
	  Robo(int id);
		~Robo();
		void update();
		void draw(Config* config);
		void move();
		double angleY();
		Vector3 position();
		void setAngleY(double a);
		void setPosition(Vector3 vec);

	private:
	  int mId;
	  Vector3* mPos;
		double mAngleY;
		Vector3* mVer;
		GameLib::Texture* mTexture;
};

