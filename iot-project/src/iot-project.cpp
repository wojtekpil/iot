//============================================================================
// Name        : iot-project.cpp
// Author      : Wojciech Piliszek
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "app/bootstrap.h"
#include "lib/iot/modules/Utils/Utils.h"
#include "lib/iot/modules/Exception/Exception.h"
using namespace std;

int main() {
	app::Bootstrap ap;
	try {
		ap.run_app();
	} catch (iot::Exception ex) {
		cout<< "Main Exception Uncaugh in App: "<<ex.getMsg()<<endl;
	}

	return 0;
}
