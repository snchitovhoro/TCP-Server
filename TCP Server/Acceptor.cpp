#include "pch.h"
#include "Acceptor.h"
#include "Service.h"


Acceptor::Acceptor(asio::io_service &ios, unsigned short port_num) :
		m_ios(ios),
		m_acceptor(m_ios,
			asio::ip::tcp::endpoint(
				asio::ip::address_v4::any(),
				port_num))
	{
		m_acceptor.listen();
	}

Acceptor::~Acceptor(){}

void Acceptor::Accept() {
		asio::ip::tcp::socket sock(m_ios);
		m_acceptor.accept(sock);
		Service svc;
		svc.HandleClient(sock);
	}

Acceptor::~Acceptor()
{
}
