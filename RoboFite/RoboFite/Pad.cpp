#include "GameLib/Framework.h"
#include "GameLib/Input/Manager.h"
#include "GameLib/Input/Keyboard.h"
#include "Pad.h"

Pad::Pad() { }

Pad::~Pad(){}

Pad* Pad::mInstance = 0;

Pad* Pad::instance() {
  return mInstance;
}

void Pad::create() {
  //TODO STRONG_ASSERT(!mInstance);
  mInstance = new Pad();
}

void Pad::destroy() {
	SAFE_DELETE_ARRAY(mInstance);
}

bool Pad::isOn(Button button, int id) const {
	if (id == 0) {
		if (button == UP && GameLib::Input::Manager::instance().keyboard().isOn('w')) return true;
		if (button == DOWN && GameLib::Input::Manager::instance().keyboard().isOn('s')) return true;
		if (button == LEFT && GameLib::Input::Manager::instance().keyboard().isOn('a')) return true;
		if (button == RIGHT && GameLib::Input::Manager::instance().keyboard().isOn('d')) return true;
		if (button == JUMP && GameLib::Input::Manager::instance().keyboard().isOn('f')) return true;
		if (button == COUNTERCLOCKWISE && GameLib::Input::Manager::instance().keyboard().isOn('e')) return true;
		if (button == CLOCKWISE && GameLib::Input::Manager::instance().keyboard().isOn('q')) return true;
  }
	else if (id == 1) {
		if (button == UP && GameLib::Input::Manager::instance().keyboard().isOn('i')) return true;
		if (button == DOWN && GameLib::Input::Manager::instance().keyboard().isOn('k')) return true;
		if (button == LEFT && GameLib::Input::Manager::instance().keyboard().isOn('j')) return true;
		if (button == RIGHT && GameLib::Input::Manager::instance().keyboard().isOn('l')) return true;
		if (button == JUMP && GameLib::Input::Manager::instance().keyboard().isOn('h')) return true;
		if (button == COUNTERCLOCKWISE && GameLib::Input::Manager::instance().keyboard().isOn('o')) return true;
		if (button == CLOCKWISE && GameLib::Input::Manager::instance().keyboard().isOn('u')) return true;
	}

 return false;
}

bool Pad::isTriggered(Button button, int id) const {
	if (id == 0) {
		if (button == UP && GameLib::Input::Manager::instance().keyboard().isTriggered('w')) return true;
		if (button == DOWN && GameLib::Input::Manager::instance().keyboard().isTriggered('s')) return true;
		if (button == LEFT && GameLib::Input::Manager::instance().keyboard().isTriggered('a')) return true;
		if (button == RIGHT && GameLib::Input::Manager::instance().keyboard().isTriggered('d')) return true;
		if (button == JUMP && GameLib::Input::Manager::instance().keyboard().isTriggered('f')) return true;
	}
	else if (id == 1) {
		if (button == UP && GameLib::Input::Manager::instance().keyboard().isTriggered('i')) return true;
		if (button == DOWN && GameLib::Input::Manager::instance().keyboard().isTriggered('k')) return true;
		if (button == LEFT && GameLib::Input::Manager::instance().keyboard().isTriggered('j')) return true;
		if (button == RIGHT && GameLib::Input::Manager::instance().keyboard().isTriggered('l')) return true;
		if (button == JUMP && GameLib::Input::Manager::instance().keyboard().isTriggered('h')) return true;
	}

	return false;
}