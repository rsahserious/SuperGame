#pragma once

namespace Constants
{
	static const unsigned short		SCREEN_WIDTH			= 1280;
	static const unsigned short		SCREEN_HEIGHT			= 800;
	static const float				ASPECT_RATIO			= (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT;
	static const float				FOV = 75.0f;

	static const unsigned short		FPS_LIMIT				= 120;
	static const unsigned short		FPS_OUTPUT_INTERVAL		= 750;

	static const float				MIN_DRAW_DISTANCE		= 0.1f;
	static const float				MAX_DRAW_DISTANCE		= 200000.0f;

	static const float				MOUSE_SENSITIVITY		= 0.07f;
	static const float				CAMERA_SPEED			= 0.3f;
	static const float				CAMERA_SPRINT_BOOST		= 3.0f;
}