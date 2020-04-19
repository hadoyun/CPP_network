#include "CUdpServer.h"
#include <iostream>

//TODO client 완성

int main()
{
	CUdpServer server{};

	std::thread thread_receive
	{
		[&]
		{
			while (true)
			{
				server.receive();
				
				const char* message = server.getBuf();
				
				printf(message);
			}
		}
	};

	printf("Server Address: %s:%d \n" ,server.getHostIp().c_str(), server.getServicePort());


	//server.sendToAll("야호 연결됬어요~~");

	//메세지 입력받기 + 메세지 보내기

	char send_message[100]{};

	while (true)
	{
		fgets(send_message, 100, stdin);

		server.sendToAll(send_message);
	}

	thread_receive.join();

	return 0;
}