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

/// @file State.h Contains declaration of the State class

#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>
#include "../managers/StateManager.h"

namespace ng
{

class State
{
public:

	/**
	 * State::enter
	 * @param window - SFML::Window passed to the client
	 * @brief Called when the state enters a state queue in a state manager
	 */
	virtual void Enter(sf::RenderWindow& window) = 0;

	/**
	 * State::exit
	 * @param window - SFML::Window passed to the client
	 * @brief Called when the state exits a state queue in a state manager
	 */
	virtual void Exit(sf::RenderWindow& window) = 0;

	/**
	 * State::pause
	 * @brief Called when the state is paused
	 */
	virtual void Pause() = 0;

	/**
	 * State::resume
	 * @brief Called when the state is resumed
	 */
	virtual void Resume() = 0;

	/**
	 * State::key_pressed
	 * @param event - SFML::Event passed to the client
	 * @brief Called when a key is pressed
	 */
	virtual void KeyPressed(sf::Event& event) = 0;

	/**
	 * State::key_released
	 * @param window - SFML::Event passed to the client
	 * @brief Called when a key is released
	 */
	virtual void KeyReleased(sf::Event& event) = 0;	

	/**
	 * State::frame_render
	 * @param window - SFML::Window passed to the client
	 * @return Returns true if the event processor is to be closed, else false
	 * @brief Called when a render event is generated by the event processor
	 */
	virtual bool FrameRender(sf::RenderWindow& window, float frametime) = 0;

	/**
	 * State::change_state
	 * @param state - The state to change to
	 * @brief Used to replace this state with another in the state queue
	 */
	void ChangeState(State* state) { mStateManager.ChangeState(state); }

	/**
	 * State::push_state
	 * @param state - The state to push
	 * @brief Used to push a new state onto the top of the state queue
	 */
	void PushState(State* state) { mStateManager.PushState(state); }

	/**
	 * State::pop_state
	 * @brief Used to remove the top state from the state queue
	 */
	void PopState() { mStateManager.PopState(); }

protected:

	/**
	 * State::State
	 * @brief Default State constructor
	 */
	State() {}

private:

	StateManager mStateManager;
};

} // namespace ng

#endif
