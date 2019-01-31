#include "pch.h"
#include "Service.h"
#include <boost/asio.hpp>
#include <thread>
#include <atomic>
#include <memory>
#include <iostream>
using namespace boost;
class Service {
public:
	Service() {}
	void HandleClient(asio::ip::tcp::socket& sock) {
		try {
			asio::streambuf request;
			asio::read_until(sock, request, '\n');
			// Emulate request processing.
			int i = 0;
			while (i != 1000000)
				i++;
			std::this_thread::sleep_for(
				std::chrono::milliseconds(500));
			// Sending response.
			std::string response = "Response\n";
			asio::write(sock, asio::buffer(response));
		}
		catch (system::system_error&e) {
			std::cout << "Error occured! Error code = "
				<< e.code() << ". Message: "
				<< e.what();
		}
	}
};
