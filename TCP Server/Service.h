#pragma once
#include <boost/asio.hpp>
#include <thread>
#include <atomic>
#include <memory>
#include <iostream>

using namespace boost;

class Service {
public:
	Service();
	~Service();
	void HandleClient(asio::ip::tcp::socket& sock); 
		
	
};


