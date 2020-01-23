#include "GameLib/Framework.h"
#include "Config.h"
#include "Vector3.h"
#include "Matrix44.h"
#include "Matrix34.h"
#include "Pad.h"

Config::Config() {
  GameLib::Framework f = GameLib::Framework::instance();

	Pad::create();

	mEyePos = new Vector3;
	mEyePos->set(0.0, 50.0, 70.0);

	mEyeTarget = new Vector3;
	mEyeTarget->set(0.0, 0.0, 0.0);

	mV = new Matrix34; 
	mV->setViewTransform(*mEyePos, *mEyeTarget);

	mP = new Matrix44;
	mP->setPerspectiveTransform(60, f.width(), f.height(), 1.0, 1000.0, false);
}

Config::~Config() {
	Pad::destroy();
}

Vector3 Config::eyePos() { return *mEyePos; }

Vector3 Config::eyeTarget() { return *mEyeTarget; }

int Config::playerId(){ return mPlayerId; }

void Config::setEyePos(Vector3 pos) {
  *mEyePos = pos;
}

void Config::setEyeTarget(Vector3 target) {
  *mEyeTarget = target;
}

Matrix44 Config::pvMatrix() {
  mV->setViewTransform(*mEyePos, *mEyeTarget);
  Matrix44 pv = *mP;
	pv *= *mV;
  return pv;
}