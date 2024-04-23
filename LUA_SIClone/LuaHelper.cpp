#include <assert.h>
#include <iostream>

#include "LuaHelper.h"

using namespace std;


bool LuaOK(lua_State* L, int id)
{
    if (id != LUA_OK)
    {
        cout << lua_tostring(L, -1) << endl;
        return false;
    }
    return true;
    
}

int LuaGetInt(lua_State* L, const std::string& name)
{
    lua_getglobal(L, name.c_str());
    if (!lua_isinteger(L, -1))
        assert(false);
    return (int)lua_tointeger(L, -1);

}

std::string LuaGetStr(lua_State* L, const std::string& name)
{
    lua_getglobal(L, name.c_str());
    if (!lua_isstring(L, -1))
        assert(false);
    return lua_tostring(L, -1);
}


int CallRandomNumber(lua_State* L, const string& fname)
{
    lua_getglobal(L, fname.c_str());
    if (!lua_isfunction(L, -1))
        assert(false);
    if (!LuaOK(L, lua_pcall(L, 0, 1, 0)))//calls a function in protected mode. (state, number of parameters, numbe rof return values, errorfunc)
        assert(false);
    int result = (int)lua_tointeger(L, -1);
    lua_pop(L, 1);
    return result;
}
void CallmoveRight(lua_State* L, const std::string& fname, float& xVal, float& frameVal)  // calls the move right funtion
{
        lua_getglobal(L, fname.c_str());
    if (!lua_isfunction(L, -1))
        assert(false);
    lua_pushnumber(L, xVal);
    lua_pushnumber(L, frameVal);
    if(!LuaOK(L, lua_pcall(L, 2, 2,0)))                                                     //calls a function in protected mode. (state, number of parameters, numbe rof return values, errorfunc)
        assert(false);
    xVal =(float) lua_tonumber(L, -2);
    frameVal - (float)lua_tonumber(L, -1);
    lua_pop(L, 2);
}

void CallmoveLeft(lua_State* L, const std::string& fname, float& xVal, float& frameVal) // calls the move left function
{
        lua_getglobal(L, fname.c_str());
    if (!lua_isfunction(L, -1))
        assert(false);
    lua_pushnumber(L, xVal);
    lua_pushnumber(L, frameVal);
    if (!LuaOK(L, lua_pcall(L, 2, 2, 0)))                                                    //calls a function in protected mode. (state, number of parameters, number of return values, errorfunc)
        assert(false);
    xVal = (float)lua_tonumber(L, -2);
    frameVal - (float)lua_tonumber(L, -1);
    lua_pop(L, 2);
}



void CallVoidVoidCFunc(lua_State* L, const std::string& fname)
{
    lua_getglobal(L, fname.c_str());
        if (!lua_isfunction(L, -1))
            assert(false);
        if (!LuaOK(L, lua_pcall(L, 0, 0, 0)))
            assert(false);
}

std::map<string, Dispatcher::Command> Dispatcher::library;

int Dispatcher::LuaCall(lua_State* L)
{
    string name = lua_tostring(L, 1);
    std::map<string, Command>::iterator it = library.find(name);
    assert(it != library.end());
    Command& cmd = (*it).second;
    if (cmd.voidintfunct)
    {
        int param = lua_tointeger(L, 2);
        cmd.voidintfunct(param);
        lua_pop(L, 1);
    }
    else
        assert(false);
    return 1;
}
