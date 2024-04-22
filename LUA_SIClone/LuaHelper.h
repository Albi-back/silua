#pragma once


#include<string>
#include<functional>
#include<map>

extern "C"
{
#include "../lua-5.4.4/include/lua.h"
#include "../lua-5.4.4/include/lauxlib.h"
#include "../lua-5.4.4/include/lualib.h"
}

#ifdef _WIN32
#pragma comment(lib,  "../lua-5.4.4/liblua54.a")
#endif // _WIN32

//check for errors
bool LuaOK(lua_State* L, int id);

//get an int from lua
int LuaGetInt(lua_State* L, const std::string& name);

//get a string from lua
std::string LuaGetStr(lua_State* L, const std::string& name);

struct Vector2
{
    int x, y;

    void FromLua(lua_State* L, const std::string& name) {
        lua_getglobal(L, name.c_str());
        if (!lua_istable(L, -1))
            assert(false);

        lua_pushstring(L, "x");
        lua_gettable(L, -2);
        x = (int)lua_tointeger(L, -1);
        lua_pop(L, 1);

        lua_pushstring(L, "y");
        lua_gettable(L, -2);
        y = (int)lua_tointeger(L, -1);
        lua_pop(L, 1);
    }
};
int CallRandomNumber(lua_State* L, const std::string& fname);


void CallmoveRight(lua_State* L, const std::string& fname, float& xVal, float& frameVal);

void CallVoidVoidCFunc(lua_State* L, const std::string& fname);


class Dispatcher {
public:
    struct Command {
        typedef std::function<void(int)> voidintfunc;
        voidintfunc voidintfunct;

    };

    void Init(lua_State* L) {
        lua_register(L, "CDispatcher", LuaCall);

    }

    void Register(const std::string& name, Command cmd) {
        assert(library.find(name) == library.end());
        library[name] = cmd;

    }

    static int LuaCall(lua_State* L);

private:
    static std::map<std::string, Command> library;
};