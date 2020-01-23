#pragma once
class Pad {
public:
	enum Button {
		UP,
		DOWN,
		LEFT,
		RIGHT,
		JUMP,
		CLOCKWISE,
		COUNTERCLOCKWISE,
	};
	static Pad* instance();
	static void create();
	static void destroy();
	bool isOn( Button, int id) const;
	bool isTriggered( Button, int id) const;
private:
 Pad();
 ~Pad();
 static Pad* mInstance;
};

