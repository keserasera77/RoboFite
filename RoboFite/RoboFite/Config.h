#pragma once

class Matrix44;
class Matrix34;
class Vector3;

class Config {
public:
Config();
~Config();
Matrix44 pvMatrix();
Vector3 eyePos();
Vector3 eyeTarget();
int playerId();
void setEyePos(Vector3 pos);
void setEyeTarget(Vector3 target);


private:
double mFieldOfViewY = 60.0;
double mNearClip = 1.0;
double mFarClip = 1000.0;
int mPlayerId = 0;
Vector3* mEyePos;
Vector3* mEyeTarget;
Matrix34* mV;
Matrix44* mP;


};

