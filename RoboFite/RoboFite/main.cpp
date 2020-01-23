// RoboFite.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "GameLib/framework.h"
#include "GameLib/Input/Manager.h"
#include "GameLib/Input/Keyboard.h"

#include "Vector3.h"
#include "Matrix44.h"
#include "Matrix34.h"
#include "main.h"
#include "Stage.h"
#include "Config.h"
#include "Robo.h"

Stage* gStage;
Robo* gRobo[2];
Config* gConfig;

namespace GameLib {
	void Framework::update() {
	  setFrameRate(60);
	  enableDepthTest(true);
		enableDepthWrite(true);

		if (!gConfig) gConfig = new Config;

		if(!gStage) gStage = new Stage;
		gStage->draw(gConfig->pvMatrix());

		for (int i = 0; i < 2; i++) {
			if (!gRobo[i]) gRobo[i] = new Robo(i);
			gRobo[i]->draw(gConfig);
		}
		
		for(int i = 0; i < 2; ++i) gRobo[i]->move();
	}
}