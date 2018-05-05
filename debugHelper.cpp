#include "Arduino.h"
#include "debugHelper.h"

// myDebugType_t[10] typeCollection;
// int typeCollectionCount = 0;

// char[10][10] typeNames;
// int typeNameCount = 0;

debugHelper::debugHelper() {}

void debugHelper::init() {
}

void debugHelper::addOption(uint16_t option, char* name) {
    optionNames[option] = name;
}

void debugHelper::setFilter(uint16_t options) {
    _options = options;
}

void debugHelper::print(uint16_t option, const char* format ...) {

	if (option & _options) {  //Print only the message types set for output
        va_list args;
        va_start(args, format);

        vsnprintf(_str, 200, format, args);

        if (_options)
        {
            Serial.print(optionNames[option]);
            Serial.print(": ");
        }

        Serial.print(_str);

        va_end(args);
	}
}