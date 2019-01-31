#pragma once
#include <boost/asio.hpp>
#include <thread>
#include <atomic>
#include <memory>
#include <iostream>

using namespace boost;

class Server
{
	public:
		Server(); 
		~Server(); 
		void Start(unsigned short port_num); 
		void Stop(); 
	private:
		void Run(unsigned short port_num); 
		
		std::unique_ptr<std::thread>m_thread;
		std::atomic<bool>m_stop;
		asio::io_service m_ios;
	
};

