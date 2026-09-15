#include "BridgeWebserver.hpp"
#include "Bridge.hpp"
#include "httplib.h"
#include "BridgeMessage.hpp"
#include <sstream>

namespace Bridge
{
using namespace httplib;

Bridge* Webserver::s_bridge = nullptr;

Webserver::Webserver(Bridge* bridge, int port, std::string pasword, std::string keypath, std::string certpath)
{
	s_bridge = bridge;

	m_thread = std::make_unique<std::thread>(([this, port]() {
		Server svr;

		svr.Get("/servers", [](const Request& req, Response& res) {
			if (!s_bridge || !s_bridge->IsConnected())
			{
				res.set_content("Server list not available", "text/plain");
				return;
			}
			std::stringstream ss;
			{
				auto playerList = s_bridge->GetBridgeInstance()->GetServerList();
				cereal::JSONOutputArchive archive(ss);
				archive(cereal::make_nvp("servers", playerList));
			}
			res.set_content(ss.str(), "application/json");
			});

		LOG_INFO("Webserver listening on port: %d", port);
		svr.listen("0.0.0.0", port);
	}));
}

}
