#include "Arduino.h"
#include "debugHelper.h"

// myDebugType_t[10] typeCollection;
// int typeCollectionCount = 0;

// char[10][10] typeNames;
// int typeNameCount = 0;

debugHelper::debugHelper() {}

void debugHelper::init() {
	for (int i=0; i<OPTION_NAMES_ARRAY_SIZE; i++) {
		optionNames[i] = '\0';
	}
}

void debugHelper::addOption(uint16_t option, const char* name) {
	if (option <= OPTION_NAMES_ARRAY_SIZE) {
		optionNames[option] = (char*) name;
	}
	else {
		Serial.printf("ERROR: too many options added! \n");
	}
}

bool debugHelper::hasOption(uint16_t option) {
	return optionNames[option] != '\0';
}

void debugHelper::setFilter(uint16_t options) {
	Serial.printf("Options %d\n", options);
	delay(100);
    _options = options;
}

void debugHelper::print(uint16_t option, const char* format ...) {

	if (option & _options) {  //Print only the message types set for output
        va_list args;
        va_start(args, format);

        vsnprintf(_str, 200, format, args);

        if (_options)
        {
			// if (optionNames[option] == '\0') {
			// 	Serial.printf("ERROR: Option not accounted for! \n");
			// }
			// else {
	            Serial.printf("%s: ", optionNames[option]);
	        // }
        }

        Serial.print(_str);

        va_end(args);
	}
}
