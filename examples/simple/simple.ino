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

	Serial.begin(9600);
	Serial.println("\nReady");

	debug.init();
	debug.addOption(STARTUP, "STARTUP");
	debug.addOption(WARNING, "WARNING");
	//debug.setFilter(d_DEBUG | d_STARTUP | d_COMMUNICATION);
	debug.setFilter(STARTUP | WARNING);

	debug.print(STARTUP, "%s \n", compile_date);
	debug.print(WARNING, "this is a warning \n");
	debug.print(DEBUG, "this won't be printed");
}

void loop () {

}