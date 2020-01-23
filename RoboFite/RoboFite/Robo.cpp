#include "GameLib/Framework.h"
#include "GameLib/Input/Manager.h"
#include "GameLib/Input/Keyboard.h"
#include "GameLib/Math.h"

#include "Vector3.h"
#include "Matrix44.h"
#include "Matrix34.h"
#include "Pad.h"
#include "Config.h"
#include "Robo.h"

void Robo::update() {

}

double Robo::angleY() {
  return mAngleY;
}

Vector3 Robo::position() {
  return *mPos;
}

void Robo::setAngleY(double a) {
  mAngleY = a;
}

void Robo::setPosition(Vector3 vec) {
  *mPos = vec;
}

Robo::Robo(int id) {
	Pad::create();

  mPos = new Vector3; 
	mId = id;
	if (id) {
		mPos->set(0.0, 0.0, -45.0);
		mAngleY = 0.0;
	}
	else {
		mPos->set(0.0, 0.0, 45.0);
		mAngleY = 180.0;
 	}

	

	mVer = new Vector3[8];
	mVer[0].set( 5.0, 0.1,  5.0);
	mVer[1].set(-5.0, 0.1,  5.0);
	mVer[2].set( 5.0, 0.1, -5.0);
	mVer[3].set(-5.0, 0.1, -5.0);
	mVer[4].set( 5.0, 10.0,  5.0);
	mVer[5].set(-5.0, 10.0,  5.0);
	mVer[6].set( 5.0, 10.0, -5.0);
	mVer[7].set(-5.0, 10.0, -5.0);

}

Robo::~Robo() {
  
}

void Robo::move() {
	Pad* pad = Pad::instance();

  Vector3 w(GameLib::sin(mAngleY),0.0,GameLib::cos(mAngleY)), d(-GameLib::cos(mAngleY),0.0,GameLib::sin(mAngleY)), f(0.0, 1.0, 0.0);
	if (pad->isOn(Pad::UP, mId)) { 
	  *mPos += w;
	}
	if (pad->isOn(Pad::DOWN, mId)) {
	  *mPos -= w;
	}
	if (pad->isOn(Pad::RIGHT, mId)) {
	  *mPos += d;
	}
	if (pad->isOn(Pad::LEFT, mId)) {
	  *mPos -= d;
	}
	if (pad->isOn(Pad::COUNTERCLOCKWISE, mId))  {
	  mAngleY -= 2.0;
	}
	if (pad->isOn(Pad::CLOCKWISE, mId)) {
		mAngleY += 2.0;
	}
	if (pad->isOn(Pad::JUMP, mId)) {
		*mPos += f;
	}
	else if (mPos->y > 0) {
		if (mPos->y - 1.0 < 0.0) mPos->y = 0.0;
		else mPos->y -= 1.0;
	}
}

void Robo::draw(Config* config) {
	GameLib::Framework f = GameLib::Framework::instance();		

	double p[8][4];
	Vector3 ver1,ver2,ver3;
	Matrix34 w;
	for (int i = 0; i < 8; i++) {
		w.setTranslation(*mPos);
		w.rotateY(mAngleY);

		if (mId == config->playerId()) {
			w.multiply(&ver2, Vector3(0.0, 30.0, -30.0));
			config->setEyePos(ver2);

			w.multiply(&ver3, Vector3(0.0, 0.0, 30.0));
			config->setEyeTarget(ver3);
		}

    w.multiply(&ver1,mVer[i]);
		config->pvMatrix().multiply(p[i], ver1);
	}

	const double g = 0x8000ff00;
	const double gg = 0x8000d000;

  //â∫ñ 
	f.drawTriangle3DH(p[0], p[1], p[2], 0, 0, 0, g, g, g);
	f.drawTriangle3DH(p[3], p[1], p[2], 0, 0, 0, g, g, g);
	//è„ñ 
	f.drawTriangle3DH(p[4], p[5], p[6], 0, 0, 0, g, g, g);
	f.drawTriangle3DH(p[7], p[5], p[6], 0, 0, 0, g, g, g);
	//éËëO
	f.drawTriangle3DH(p[2], p[3], p[6], 0, 0, 0, gg, gg, gg);
	f.drawTriangle3DH(p[7], p[3], p[6], 0, 0, 0, gg, gg, gg);
}