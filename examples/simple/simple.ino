#include <debugHelper.h>

/*--------------------------------------------------------------------------------*/

const char compile_date[] = __DATE__ " " __TIME__;

//--------------------------------------------------------------------------------

debugHelper debug;

#define	STARTUP   	1 << 0
#define WARNING   	1 << 1
#define ERROR   	1 << 2
#define DEBUG   	1 << 3



void setup() {

	debug.init();
	debug.addOption(STARTUP, "STARTUP");
	debug.setFilter(d_DEBUG | d_STARTUP | d_COMMUNICATION);

    Serial.begin(9600);

	debug.print(d_STARTUP, compile_date);
}

void loop () {

}