#pragma once
#include "raylib.h"

class Window
{
private:
	Color bg_color = { 109, 111, 161, 255 };
public:
	int window_width;
	int window_height;

public:
	Window(int window_width, int window_height, const char* window_name);
	Window();
	inline Color GetBgColor() const { return bg_color; }
};

