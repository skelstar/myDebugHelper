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

}

void debugHelper::setFilter(uint16_t options) {
    _options = options;
}

// void debugHelper::addOption(char[10] name, myDebugType_t option) {
// 	typeCollection[typeCollectionCount] = option;
// 	typeCollectionCount++;
// 	typeNames[typeCollectionCount] = strcpy
// }

void debugHelper::print(myDebugType_t option, const char* format ...) {

	if (option & _options) {  //Print only the message types set for output
        va_list args;
        va_start(args, format);

        vsnprintf(_str, 200, format, args);

        if (_options)
        {
            switch(option)
            {
                case d_ERROR:
                    Serial.print("ERROR: ");
                    break;
                case d_STARTUP:
                    Serial.print("STARTUP: ");
                    break;
                case d_MESH_STATUS:
                    Serial.print("MESH_STATUS: ");
                    break;
                case d_CONNECTION:
                    Serial.print("CONNECTION: ");
                    break;
                case d_SYNC:
                    Serial.print("SYNC: ");
                    break;
                case d_S_TIME:
                    Serial.print("S_TIME: ");
                    break;
                case d_COMMUNICATION:
                    Serial.print("COMMUNICATION: ");
                    break;
                case d_GENERAL:
                    Serial.print("GENERAL: ");
                    break;
                case d_MSG_TYPES:
                    Serial.print("MSG_TYPES: ");
                    break;
                case d_REMOTE:
                    Serial.print("REMOTE: ");
                    break;
                case d_APPLICATION:
                    Serial.print("APPLICATION: ");
                    break;
                case d_DEBUG:
                    Serial.print("DEBUG: ");
                    break;
                default:
                	Serial.printf("CUSTOM(%d)", option);
                	break;
            }
        }

        Serial.print(_str);

        va_end(args);
	}
}