#pragma once

//Key press surfaces constants
enum KeyPress
{
	KEY_PRESS_DEFAULT,
	KEY_PRESS_UP,
	KEY_PRESS_DOWN,
	KEY_PRESS_LEFT,
	KEY_PRESS_RIGHT,
	KEY_PRESS_TOTAL
};

class EventHandler
{
public:
  EventHandler();
  ~EventHandler();

  bool handleEvent(KeyPress key);
};

