
feniceincludedir = $(top_srcdir)/include

noinst_LTLIBRARIES = librtp.la
librtp_la_SOURCES =	RTP_get_port_pair.c \
			RTP_recv.c \
			RTP_release_port_pair.c \
			RTP_port_pool_init.c \
			RTP_send_packet.c \
			RTP_sendto.c \
			RTP_session_destroy.c \
			RTP_transport_close.c
			
librtp_la_LDFLAGS = -static
INCLUDES = -I$(feniceincludedir) -I$(top_srcdir)
