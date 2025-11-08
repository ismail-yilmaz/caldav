#ifndef _WebDAV_CalDAV_h_
#define _WebDAV_CalDAV_h_

#include <WebDAV/WebDAV.h>

namespace Upp {

class CalDAVRequest : public WebDAVRequest {
public:
	CalDAVRequest();
	CalDAVRequest(const String& host, int port = 80);
	virtual ~CalDAVRequest();
	
	// Non-blocking initializers (use with Do() method)
	void    StartGetCurrentUserPrincipal(const String& path = Null);
	void    StartGetCalendarHomeSet(const String& path);
	void    StartGetCalendars(const String& path);
	void    StartGetEvents(const String& path, const String& start_time = Null, const String& end_time = Null);
	void    StartGetEvents(const String& path, const Vector<String>& urls);
	void    StartAddEvent(const String& path, const String& ical_data);
	void    StartUpdateEvent(const String& path, const String& ical_data, const String& etag = Null);
	void    StartDeleteEvent(const String& path);
	void    StartGetEvent(const String& path);
    
	// Blocking variants
	String  GetCurrentUserPrincipal(const String& path = Null);
	String  GetCalendarHomeSet(const String& path);
	String  GetCalendars(const String& path);
	String  GetEvents(const String& path, const String& start_time = Null, const String& end_time = Null);
	String  GetEvents(const String& path, const Vector<String>& urls);
	bool    AddEvent(const String& path, const String& ical_data);
	bool    UpdateEvent(const String& path, const String& ical_data, const String& etag = Null);
	bool    DeleteEvent(const String& path);
	String  GetEvent(const String& path);
};

}
#endif