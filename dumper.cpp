#include <lua.hpp>
#include <iostream>


int dumpArgs(lua_State * state) {
	/* stuff to get each arg */
	for(int i=1; i <= lua_gettop(state); ++i) {
		//this'll be in a for loop
		switch(lua_type(state, i)) {
			case LUA_TSTRING:
				std::cout<<lua_tostring(state,i)<<std::endl;
				break;
			case LUA_TBOOLEAN:
				std::cout<<(lua_toboolean(state, i) ? "true" : "false")<<std::endl;
				break;
			case LUA_TNUMBER:
				std::cout<<(double) (lua_tonumber(state,i))<<std::endl;
				break;
			default:
				std::cout<<"idk"<<std::endl;
		}
	}
	return 0;
}

static const struct luaL_Reg dumper [] = {
	{ "dump", dumpArgs },
	{ NULL, NULL },
};

extern "C" {
	int luaopen_dumper(lua_State * state) {
		luaL_newlib(state, dumper);
		return 1;
	}
}

