#pragma once
#define d_toggle_bind 0x2D /* VK_INSERT */
#define d_end_bind 0x23 /* VK_END */

namespace overlay
{
	void draw_gui();
	void render();

	inline bool enabled = true;
}
