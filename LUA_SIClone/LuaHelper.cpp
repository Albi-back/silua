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
