#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ConnectBits
{
    bool close;
    bool reuse;
    bool conn_to_host;
    bool conn_to_port;
    bool proxy;
    bool httpproxy;
    bool socksproxy;
    bool user_passwd;
    bool proxy_user_passwd;
    bool ipv6_ip;
    bool ipv6;
    bool do_more;
    bool tcpconnect[2];
    bool protoconnstart;
    bool retry;
    bool tunnel_proxy;
    bool authneg;
    bool rewindaftersend;
    bool ftp_use_epsv;
    bool ftp_use_eprt;
    bool ftp_use_data_ssl;
    bool netrc;
    bool userpwd_in_url;
    bool stream_was_rewound;
    bool proxy_connect_closed;
    bool bound;
    bool type_set;
    bool multiplex;
    bool tcp_fastopen;
    bool tls_enable_npn;
    bool tls_enable_alpn;
    bool proxy_ssl_connected[2];
    bool socksproxy_connecting;
};

}

}
