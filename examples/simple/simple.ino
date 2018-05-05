#include <debugHelper.h>

/*--------------------------------------------------------------------------------*/

const char compile_date[] = __DATE__ " " __TIME__;

//--------------------------------------------------------------------------------

debugHelper debug;


void setup() {

	debug.init(d_DEBUG | d_STARTUP | d_COMMUNICATION);

    Serial.begin(9600);

	debug.print(d_STARTUP, compile_date);
}

void loop () {

}