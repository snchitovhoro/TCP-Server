#pragma once

#include <boost/asio.hpp>
#include <thread>
#include <atomic>
#include <memory>
#include <iostream>

using namespace boost;

class Acceptor {
public:
	Acceptor(asio::io_service &ios, unsigned short port_num); 
	~Acceptor(); 
	void Accept(); 
private:
	asio::io_service &m_ios;
	asio::ip::tcp::acceptor m_acceptor;
};

