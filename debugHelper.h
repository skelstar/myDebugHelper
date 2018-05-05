#ifndef DebugHelper_h
#define DebugHelper_h

#include <Arduino.h>

class debugHelper {
	
	public:
		debugHelper();
		void init();
		void addOption(uint16_t option, char* name);
		void setFilter(uint16_t options);
		void print(uint16_t option, const char* format ...);

	private:
		uint16_t _options = 0;
		char _str[200];
		char* optionNames[10];
};
#endif

