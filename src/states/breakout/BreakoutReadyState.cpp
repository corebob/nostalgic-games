/*
This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place - Suite 330, Boston, MA 02111-1307, USA, or go to
http://www.gnu.org/licenses/gpl.txt

Copyright (c) 2010 Dag Robøle
*/

#include <SFML/Graphics.hpp>
#include "BreakoutReadyState.h"

using namespace sf;

BreakoutReadyState BreakoutReadyState::gBreakoutReadyState;

void BreakoutReadyState::Enter(RenderWindow& window)
{
    Font& font = fontManager["arial"];

	text.SetFont(font);
	text.SetCharacterSize(20);
	text.SetColor(Color(255, 128, 0));
}

void BreakoutReadyState::Exit(RenderWindow& window)
{
}

void BreakoutReadyState::Pause()
{
}

void BreakoutReadyState::Resume()
{
}

void BreakoutReadyState::KeyPressed(Event& event)
{
	switch(event.Key.Code)
	{
	case Keyboard::Space:
		PopState();
		break;
	default: break;
	}
}

void BreakoutReadyState::KeyReleased(Event& event)
{
}

bool BreakoutReadyState::FrameRender(RenderWindow& window, float frametime)
{
    text.SetString("Press SPACE when you are ready for next level");
	text.SetCharacterSize(20);
	text.SetPosition(window.GetWidth() / 2 - text.GetGlobalBounds().Width / 2, 120);
	window.Draw(text);

	return false;
}