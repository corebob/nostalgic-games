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

/// @file TextureManager.h Contains declaration of TextureManager

#ifndef TextureManager_H
#define TextureManager_H

#include <string>
#include <SFML/Graphics.hpp>
#include "ResourceBase.h"

namespace ng
{

class TextureManager : public ResourceBase<sf::Texture>
{
public:

    TextureManager();

    static std::string ResourceFile;

protected:

    virtual sf::Texture* Load(const std::string& name);
};

} // namespace ng

#endif
