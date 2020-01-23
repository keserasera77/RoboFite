#pragma once

class Vector3;

class Stage {
  public:
	  Stage();
		//~Stage();
		void update();
		void draw(const Matrix44 pvm);
	private:
	  GameLib::Texture* mTexture;
    int mWidth = 100;
		int mHeight = 100;
		Vector3* mVer;
};

