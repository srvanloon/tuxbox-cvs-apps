#ifndef __scan_h
#define __scan_h

#include "dvb.h"
#include "multipage.h"
#include "ewidget.h"

class eWindow;
class eLabel;
class eProgress;

class tsText: public eWidget
{
	eLabel *headline, *body;
protected:
	void keyUp(int rc);
	int eventFilter(const eWidgetEvent &event);
public:
	void redrawWidget();
	tsText(QString headline, QString body, eWidget *parent);
};

class tpPacket
{
public:
	tpPacket(QString name, int scanflags): name(name), scanflags(scanflags) {}
	QString name;
	int scanflags;
	std::list<eTransponder*> possibleTransponders;
	~tpPacket()
	{
		for (std::list<eTransponder*>::iterator It = possibleTransponders.begin(); It != possibleTransponders.end(); It++)
			delete *It;
	}
};

class tsFindInit: public eWidget
{
	eLabel *headline, *body;
	eProgress *signalbar;
	eTimer sstimer;
	QList<tpPacket> packets;
	enum
	{
		sInactive, sSearching, sFound, sFailed
	};
	void scanPacket();
	int state;
	virtual int eventFilter(const eWidgetEvent &event);
protected:
	void keyUp(int rc);
private:
	void tunedIn(eTransponder *trans, int error);
	void showSignalStrength();
public:
	void redrawWidget();
	tsFindInit(eWidget *parent);
	
	tpPacket *result;
};

class tsDoScan: public eWidget
{
	eTimer etatimer;
	eLabel *transp_found, *transp_scanned, *known_services, *eta, *dummy1, *dummy2;
	eProgress *bar, *dummybar;
	
	time_t start;
	time_t fexp;
	tsFindInit *init;
protected:
	void updateStats();
	virtual int eventFilter(const eWidgetEvent &event);
private:
	void stateChanged(int newstate);
	void eventOccured(int event);
	void updateETA();
public:
	tsDoScan(tsFindInit *init, eWidget *parent);
	void redrawWidget();
};

class TransponderScan
{
	eWindow *window;
	eProgress *progress;
	eLabel *progress_text;
	eMultipage mp;
public:
	TransponderScan();
	~TransponderScan();
	int exec();
};

#endif
