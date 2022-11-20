#include "project04.h"

int string_to_int(char *string, int base) {
	int value = 0, rv = 0, pv = 1;
	// Loop backwards
	for (int i = strlen(string) - 1; i >= 0; i--) {
		value = string[i];
		// Ascii value addition to convert the character to an integer
		if (value >= '0' && value <= '9') {
			value = ((value - 48) * pv);
			rv += value;
			pv *= base;
		} else if (value >= 'a' && value <= 'f') {
			value = ((value - 87) * pv);
			rv += value;
			pv *= base;
		} else if (value >= 'A' && value <= 'F') {
			value = ((value - 55) * pv);
			rv += value;
			pv *= base;
		}
	}
	
    return rv;
}
