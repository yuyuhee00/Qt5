
TEMPLATE    = subdirs

CONFIG += ordered
CONFIG += sdk_no_version_check

SUBDIRS     = \
            01_TcpServer \
            01_TcpClient \
            02_QTcpSocket_Sync \
            02_QTcpSocket_Async \
            03_UDP_Server \
            03_UDP_Client \
            04_Broadcast_Receiver \
            04_Broadcast_Sender \
            05_Multicast_Receiver \
            05_Multicast_Sender \
            06_ChatServer \
            06_ChatClient


