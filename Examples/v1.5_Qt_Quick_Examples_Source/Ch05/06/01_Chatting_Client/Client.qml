import QtQuick 2.12
import TCP 1.0

ChatWindow {
    width: 300; height: 200
    type : TcpConnection.Client
    port : 4242
    hostName : "localhost"
}
