/*
$Id: dvb_api.h,v 1.6 2005/08/12 23:02:33 rasc Exp $


 DVBSNOOP

 a dvb sniffer  and mpeg2 stream analyzer tool
 http://dvbsnoop.sourceforge.net/

 (c) 2001-2005   Rainer.Scherg@gmx.de (rasc)




$Log: dvb_api.h,v $
Revision 1.6  2005/08/12 23:02:33  rasc
New shortcut options: -adapter and -devnr to select dvb cards/adapters or device numbers on a card.
This is a shortcut for -demux -dvr and -frontend...


*/



#ifndef __DVB_API_H
#define __DVB_API_H


#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>



#if defined(HAVE_LINUX_DVB_DMX_H)


// API 3
#define DVB_API_VERSION 3

#include <linux/dvb/dmx.h>
#define DEMUX_DEVICE_MASK    "/dev/dvb/adapter%d/demux%d"
#define DVR_DEVICE_MASK      "/dev/dvb/adapter%d/dvr%d"
#include <linux/dvb/frontend.h> 
#define FRONTEND_DEVICE_MASK "/dev/dvb/adapter%d/frontend%d"

// adapter[0-4]/device[0-4]
#define DVB_STD_ADAPTER_NR	0
#define DVB_STD_DEVICE_NR	0
#define DVB_MAX_DEV_PATH_LEN	64


#elif defined(HAVE_OST_DMX_H)


// API 1
#define DVB_API_VERSION 1

#include <ost/dmx.h>
#define DEMUX_DEVICE_MASK   "/dev/dvb/card0/demux0"
#define DVR_DEVICE_MASK     "/dev/dvb/card0/dvr0"
#define dmx_pes_filter_params dmxPesFilterParams
#define dmx_sct_filter_params dmxSctFilterParams
#define pes_type pesType
#include <ost/frontend.h> 
#define FRONTEND_DEVICE_MASK "/dev/dvb/card0/frontend0"
#define fe_status_t FrontendStatus

// card[0-4]/device[0-4]   card = adapter
#define DVB_STD_ADAPTER_NR	0
#define DVB_STD_DEVICE_NR	0
#define DVB_MAX_DEV_PATH_LEN	64


#endif



#endif

