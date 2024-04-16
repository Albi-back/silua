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

