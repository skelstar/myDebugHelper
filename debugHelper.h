#ifndef DebugHelper_h
#define DebugHelper_h

#include <Arduino.h>

#define OPTION_NAMES_ARRAY_SIZE	20

class debugHelper {
	
	public:
		debugHelper();
		void init();
		void addOption(uint16_t option, char* name);
		void setFilter(uint16_t options);
		void print(const char* optionByName, const char* format ...);
		void print(uint16_t option, const char* format ...);

	private:
		uint16_t _options = 0;
		char _str[200];
		char* optionNames[OPTION_NAMES_ARRAY_SIZE];
};
#endif

