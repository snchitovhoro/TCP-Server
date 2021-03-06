// TCP Server.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <boost/any.hpp>


int main()
{
	unsigned short port_num = 3333;
	try {
		Server srv;
		srv.Start(port_num);
		std::this_thread::sleep_for(std::chrono::seconds(60));
		srv.Stop();
	}
	catch (system::system_error&e) {
		std::cout << "Error occured! Error code = "
			<< e.code() << ". Message: "
			<< e.what();
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

