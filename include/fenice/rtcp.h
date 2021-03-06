
#ifndef _RTCPH
#define _RTCPH

#include <fenice/rtp.h>

	//#define MAX_PKT_SIZE 548 /* 576 - 20 - 8 = Minimum Reassembly Buffer Size - IP datagram header -  UDP header: in octects */
	//#define MAX_SDES_LEN 255 /* in octects */

	/*#define RTCP_MIN_TIME 5.0
	   #define RTCP_SENDER_BW_FRACTION 0.25
	   #define RTCP_RCVR_BW_FRACTION 0.75
																																		        #define COMPENSATION 1.21828 *//* e - 1.5 */

typedef enum {
	SR = 200,
	RR = 201,
	SDES = 202,
	BYE = 203,
	APP = 204
} rtcp_pkt_type;

typedef enum {
	CNAME = 1,
	NAME = 2,
	EMAIL = 3,
	PHONE = 4,
	LOC = 5,
	TOOL = 6,
	NOTE = 7,
	PRIV = 8
} rtcp_info;

typedef struct _RTCP_header {
#if (BYTE_ORDER == LITTLE_ENDIAN)
	unsigned int count:5;	//SC oppure RC
	unsigned int padding:1;
	unsigned int version:2;
#elif (BYTE_ORDER == BIG_ENDIAN)
	unsigned int version:2;
	unsigned int padding:1;
	unsigned int count:5;	//SC oppure RC
#else
#error Neither big nor little
#endif
	unsigned int pt:8;
	unsigned int length:16;
} RTCP_header;

typedef struct _RTCP_header_SR {
	unsigned int ssrc;
	unsigned int ntp_timestampH;
	unsigned int ntp_timestampL;
	unsigned int rtp_timestamp;
	unsigned int pkt_count;
	unsigned int octet_count;
} RTCP_header_SR;

typedef struct _RTCP_header_RR {
	unsigned int ssrc;
} RTCP_header_RR;

typedef struct _RTCP_header_SR_report_block {
	unsigned long ssrc;
	unsigned char fract_lost;
	unsigned char pck_lost[3];
	unsigned int h_seq_no;
	unsigned int jitter;
	unsigned int last_SR;
	unsigned int delay_last_SR;
} RTCP_header_SR_report_block;

typedef struct _RTCP_header_SDES {
	unsigned int ssrc;
	unsigned char attr_name;
	unsigned char len;
} RTCP_header_SDES;

typedef struct _RTCP_header_BYE {
	unsigned int ssrc;
	unsigned char length;
} RTCP_header_BYE;

int RTCP_send_packet(RTP_session * session, rtcp_pkt_type type);
int RTCP_recv_packet(RTP_session * session);
int RTCP_handler(RTP_session * session);

int RTCP_get_pkt_lost(RTP_session * session);
	// Quanti pacchetti (RTP) ha perso il client

float RTCP_get_fract_lost(RTP_session * session);
	// Quanti byte ha perso il client

unsigned int RTCP_get_jitter(RTP_session * session);
	// Il jitter

unsigned int RTCP_get_RR_received(RTP_session * session);
	// Quanti pacchetti RR ha ricevuto il server dal client

unsigned int RTCP_get_total_packet(RTP_session * session);
	// Quanti pacchetti ha spedito il server

unsigned int RTCP_get_total_payload_octet(RTP_session * session);
	// Quanti byte ha spedito il server

	// int RTCP_parse(char *buff,RTP_session *session);
	// Effettua il parsing di un pacchetto RTCP

	// int RTCP_send_SDES(RTP_session *session);

int RTCP_get_pkt_lost(RTP_session * session);
	// Quanti pacchetti (RTP) ha perso il client

float RTCP_get_fract_lost(RTP_session * session);
	// Quanti byte ha perso il client

unsigned int RTCP_get_jitter(RTP_session * session);
	// Il jitter

unsigned int RTCP_get_total_packet(RTP_session * session);
	// Quanti pacchetti ha spedito il server

unsigned int RTCP_get_total_payload_octet(RTP_session * session);
	// Quanti byte ha spedito il server

	// int RTCP_parse(char *buff,RTP_session *session);
	// Effettua il parsing di un pacchetto RTCP

	// int RTCP_send_SDES(RTP_session *session);
	// Spedisce un pacchetto Source DEScription sulla base dei dati in *session.

	// int RTCP_send_SR(RTP_session *session);
	// Spedisce un pacchetto Source Report sulla base dei dati in *session.


#endif
