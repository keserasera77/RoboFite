#include "GameLib/Framework.h"
#include "Vector3.h"
#include "Matrix44.h"
#include "Matrix34.h"
#include "Config.h"
#include "Stage.h"

Stage::Stage() {
  mVer = new Vector3[4];
	mVer[0].set(-50.0, 0.0, -50.0);
	mVer[1].set(50.0, 0.0, -50.0);
	mVer[2].set(-50.0, 0.0, 50.0);
	mVer[3].set(50.0, 0.0, 50.0);
}

void Stage::update() {

}

void Stage::draw(const Matrix44 pvm) {
	GameLib::Framework f = GameLib::Framework::instance();

	double pout[4][4];
	for (int i = 0; i < 4; i++) {
		pvm.multiply(pout[i], mVer[i]);
	}

	double uv[4][2] = {
		{0.0,0.0} ,
		{0.0,1.0} ,
		{1.0,0.0} ,
		{1.0,1.0}
	};

	f.setTexture( mTexture );

	const unsigned red = 0x80ff0000;

	f.drawTriangle3DH(pout[3], pout[2], pout[1], uv[0], uv[1], uv[2]);
	f.drawTriangle3DH(pout[0], pout[2], pout[1], uv[3], uv[1], uv[2]);
}