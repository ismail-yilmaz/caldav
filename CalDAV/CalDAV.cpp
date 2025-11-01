#include "CalDAV.h"

namespace Upp {

namespace {

constexpr const char *sCalendarHomeQuery =
	"<?xml version=\"1.0\" encoding=\"utf-8\"?>"
	"<D:propfind xmlns:D=\"DAV:\" xmlns:C=\"urn:ietf:params:xml:ns:caldav\">"
	"<D:prop>"
	"<C:calendar-home-set/>"
	"</D:prop>"
	"</D:propfind>";
	
constexpr const char *sCalendarQuery =
	"<?xml version=\"1.0\" encoding=\"utf-8\"?>"
	"<C:calendar-query xmlns:C=\"urn:ietf:params:xml:ns:caldav\">"
	"<D:prop xmlns:D=\"DAV:\">"
	"<D:getetag/>"
	"<C:calendar-data/>"
	"</D:prop>"
	"%s" // Time range filter
	"</C:calendar-query>";

// See iCalendar RFC 5545 for VCALENDAR and VEVENT
constexpr const char *sTimeRangeFilter =
	"<C:filter>"
	"<C:comp-filter name=\"VCALENDAR\">"
	"<C:comp-filter name=\"VEVENT\">"
	"<C:time-range start=\"%s\" end=\"%s\"/>"
	"</C:comp-filter>"
	"</C:comp-filter>"
	"</C:filter>";

constexpr const char *sCalendarPropFind =
	"<?xml version=\"1.0\" encoding=\"utf-8\"?>"
	"<D:propfind xmlns:D=\"DAV:\" xmlns:C=\"urn:ietf:params:xml:ns:caldav\">"
	"<D:prop>"
	"<D:resourcetype/>"
	"<D:displayname/>"
	"<C:supported-calendar-component-set/>"
	"<C:calendar-description/>"
	"<C:calendar-timezone/>"
	"</D:prop>"
	"</D:propfind>";

constexpr const char *sCalendarMultigetQuery =
    "<?xml version=\"1.0\" encoding=\"utf-8\"?>"
    "<C:calendar-multiget xmlns:C=\"urn:ietf:params:xml:ns:caldav\">"
    "<D:prop xmlns:D=\"DAV:\">"
    "<D:getetag/>"
    "<C:calendar-data/>"
    "</D:prop>"
    "%s"
    "</C:calendar-multiget>";

constexpr const char *sCurrentUserPrincipalQuery =
    "<?xml version=\"1.0\" encoding=\"utf-8\"?>"
    "<D:propfind xmlns:D=\"DAV:\">"
    "<D:prop>"
    "<D:current-user-principal/>"
    "</D:prop>"
    "</D:propfind>";
    
String CalDavGetEventPath(const String& path)
{
	String event_id = (String) UuidValueGen().Get() + ".ics";
	return AppendFileName(path, event_id);
}

String BuildMultiGetXml(const Vector<String>& event_urls)
{
    String hrefs;
    for(const String& url : event_urls)
        hrefs << "<D:href>" << url << "</D:href>";
    return Format(sCalendarMultigetQuery, hrefs);
}

}

CalDAVRequest::CalDAVRequest()
: WebDAVRequest()
{
}

CalDAVRequest::CalDAVRequest(const String& host, int port)
: WebDAVRequest(host, port)
{
}

CalDAVRequest::~CalDAVRequest()
{
}

void CalDAVRequest::StartGetCurrentUserPrincipal()
{
	StartPropFind("/", 0, sCurrentUserPrincipalQuery);
}

void CalDAVRequest::StartGetCalendarHomeSet(const String& path)
{
	StartPropFind(path, 0, sCalendarHomeQuery);
}

void CalDAVRequest::StartGetCalendars(const String& path)
{
	StartPropFind(path, 1, sCalendarPropFind);
}

void CalDAVRequest::StartGetEvents(const String& path, const String& start_time, const String& end_time)
{
	String filter = Format(sTimeRangeFilter, start_time, end_time);
	StartReport(path, Format(sCalendarQuery, filter));
}

void CalDAVRequest::StartGetEvents(const String& path, const Vector<String>& urls)
{
	StartReport(path, BuildMultiGetXml(urls));
}

void CalDAVRequest::StartAddEvent(const String& path, const String& ical_data)
{
	StartSaveFile(CalDavGetEventPath(path), ical_data, "text/calendar");
}

void CalDAVRequest::StartUpdateEvent(const String& path, const String& ical_data, const String& etag)
{
	StartSaveFile(path, ical_data, "text/calendar");
	if(!IsNull(etag))
		Header("If-Match", etag);
}

void CalDAVRequest::StartDeleteEvent(const String& path)
{
	StartDelete(path);
}

void CalDAVRequest::StartGetEvent(const String& path)
{
	StartLoadFile(path);
}

String CalDAVRequest::GetCurrentUserPrincipal()
{
	StartGetCurrentUserPrincipal();
	return Execute();
}

String CalDAVRequest::GetCalendarHomeSet(const String& path)
{
	StartGetCalendarHomeSet(path);
	return Execute();
}

String CalDAVRequest::GetCalendars(const String& path)
{
	StartGetCalendars(path);
	return Execute();
}

String CalDAVRequest::GetEvents(const String& path, const String& start_time, const String& end_time)
{
	StartGetEvents(path, start_time, end_time);
	return Execute();
}

String CalDAVRequest::GetEvents(const String& path, const Vector<String>& urls)
{
	StartGetEvents(path, urls);
	return Execute();
}

bool CalDAVRequest::AddEvent(const String& path, const String& ical_data)
{
	StartAddEvent(path, ical_data);
	Execute();
	return IsSuccess();
}

bool CalDAVRequest::UpdateEvent(const String& path, const String& ical_data, const String& etag)
{
	StartUpdateEvent(path, ical_data, etag);
	Execute();
	return IsSuccess();
}

bool CalDAVRequest::DeleteEvent(const String& path)
{
	StartDeleteEvent(path);
	Execute();
	return IsSuccess();
}

String CalDAVRequest::GetEvent(const String& path)
{
	StartGetEvent(path);
	return Execute();
}

}