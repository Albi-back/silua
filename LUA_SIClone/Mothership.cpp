/*
Space invaders game
Author:		Philip Alassad
Filename:	Mothership.cpp
Date:		14/10/2015
Last Updated:	25/10/2015

Description: Source file for Mothership class
*/

#include "Mothership.h"
#include "LuaHelper.h"
#include <stdio.h>
using namespace std;



//Constructor
Mothership::Mothership(float xPos, float yPos, string filename)
	:Ship(xPos, yPos, filename)
{
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	if (!LuaOK(L, luaL_dofile(L, "Script.lua")))
		assert(false);
	
	m_lives = LuaGetInt(L,"mlives");
	m_xpos = LuaGetInt(L, "mxpos");
	m_ypos = LuaGetInt(L, "mypos");
}

Mothership::~Mothership()
{

}

//Methods
void Mothership::left()
{
}

void Mothership::right()
{
	m_xpos = m_xpos + 3 ;
}

void Mothership::reduceLives()
{
	m_lives --;
}

int Mothership::getLives()
{
	return m_lives;
}
