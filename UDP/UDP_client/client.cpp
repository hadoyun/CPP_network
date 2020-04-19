#include "CUdpClient.h"
#include <thread>
#include <iostream>

int main()
{
	CUdpClient client{};

	client.setServerAddr("192.168.35.229", 15000);

	std::thread thread_send
	{
		[&]
		{
			char send_message[1000]{};

			while (true)
			{
				std::cin >> send_message;

				client.send(send_message);
			}
		}
	};

	while (true)
	{
		client.receive();
		
		printf(client.getBuf());
	}

	thread_send.join();

	return 0;
}