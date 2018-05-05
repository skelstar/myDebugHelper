#ifndef DebugHelper_h
#define DebugHelper_h

#include <Arduino.h>

typedef enum
{
	d_ERROR         = 1 << 0,
	d_STARTUP       = 1 << 1,
	d_MESH_STATUS   = 1 << 2,
	d_CONNECTION    = 1 << 3,
	d_SYNC          = 1 << 4,
	d_S_TIME        = 1 << 5,
	d_COMMUNICATION = 1 << 6,
	d_GENERAL       = 1 << 7,
	d_MSG_TYPES     = 1 << 8,
	d_REMOTE        = 1 << 9, // not yet implemented
	d_APPLICATION   = 1 << 10,
	d_DEBUG         = 1 << 11
} myDebugType_t;

class debugHelper {
	
	public:
		debugHelper();
		void init(uint16_t options);
		void print(myDebugType_t option, const char* format ...);
	private:
		uint16_t _options = 0;
		char _str[200];


};
#endif

