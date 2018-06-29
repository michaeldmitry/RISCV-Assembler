#include <string>
#pragma once
#ifndef HelperClass
struct Helper {
	static int Decimal(std::string sub) {
		int decimalNumber = 0;
		int remainder;
		int j = 0;
		for (int i = sub.size() - 1; i >= 0; i--) {
			remainder = sub[i];
			remainder = remainder - 48;
			decimalNumber += (remainder*pow(2, j));
			j++;
		}
		return decimalNumber;
	}
	static void emitError(string error) {
		cout << error << endl;
		exit(-1);
	}
};
#endif