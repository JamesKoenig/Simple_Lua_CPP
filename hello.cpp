#include <iostream>
#include <lua.hpp>

extern "C" {
	
	
	int luaTest_hello(lua_State * state) {
		printf("hello world from a c function called in lua");
		return 0;
	}
	
	static const luaL_Reg testLib [] = {
		{ "hello", luaTest_hello },
		{ NULL, NULL }
	};
} /* extern "C" */

int main(int argc, char ** argv) {
	int result;
	lua_State * lState = luaL_newstate();
	luaL_openlibs(lState);
	luaL_newlib(lState, testLib);
	lua_pushvalue(lState, -1);
	lua_setglobal(lState,"test");

	result = luaL_loadfile(lState, "hello.lua");

	if(result != LUA_OK) 
		goto luaerr;
	result = lua_pcall(lState, 0, LUA_MULTRET, 0);
	if(result != LUA_OK) 
		goto luaerr;
	std::cout << "hello world from the C++ program" << std::endl;
	lua_close(lState);
	return 0;

luaerr:
	const char *message = lua_tostring(lState, -1);
	std::cout<< message << std::endl;
	lua_pop(lState,1);
	lua_close(lState);
	return 1;

}
