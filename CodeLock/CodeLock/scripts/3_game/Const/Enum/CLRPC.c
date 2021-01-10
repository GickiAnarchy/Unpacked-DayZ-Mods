enum CLRPC {
    CRPC_START = 51651632,

    // Server RPC's
    RPC_SERVER_SETCODE,
    RPC_SERVER_ENTERCODE,
    RPC_SERVER_CLAIMCODE,
    RPC_SERVER_SYNCHLOCK,
    RPC_SERVER_ADMINMENU,

    // Client RPC's
    RPC_CLIENT_SYNCHLOCK,
    RPC_CLIENT_SHOWMENU,
    RPC_CLIENT_HANDLEUI,
    RPC_CLIENT_SETCONFIG,
    RPC_CLIENT_SYNCHADMINS
}