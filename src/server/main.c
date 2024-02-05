#include "server.h"
AcceptCallback accept = (AcceptCallback) OnClientAccept;

int ServerStartupMain(int args, char* arg[]) {
	struct event_base *base;
	struct evconnlistener *listener;
	struct sockaddr_in sin;
	int flags = LEV_OPT_CLOSE_ON_FREE | LEV_OPT_REUSEABLE;

	INSTANCE server = CreateInstance();
	g_write_log("Server initializing.");

	if ((base = event_base_new())) {
		memset(&sin, 0, sizeof(sin));
		sin.sin_family = AF_INET;
		sin.sin_port = htons(5190);

		size_t sinSize = sizeof(sin);
		struct sockaddr* srvSockAddr = (struct sockaddr*) &sin;

		if ((listener = evconnlistener_new_bind( base, accept, server, flags, -1, srvSockAddr, sinSize))) {
			event_base_dispatch(base);
			evconnlistener_free(listener);

			event_base_free(base);
			return 0;
		}
		else fputs("Could not create listener!", stderr);
	}
	else fputs("Could not initialize libevent!", stderr);

	return 1;
}