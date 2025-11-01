#include "CalDAVExample.h"

using namespace Upp;

String DiscoverPrincipal(CalDAVRequest& cal)
{
	String xml = cal.GetCurrentUserPrincipal();
	if(!cal.IsSuccess()) {
		LOG("ERROR: Failed to discover principal - " << cal.GetErrorDesc());
		return Null;
	}

	String principal = ExtractPrincipalFromXml(xml);
	LOG("Principal: " << principal);
	return principal;
}

String DiscoverCalendarHome(CalDAVRequest& cal, const String& principal)
{
	String xml = cal.GetCalendarHomeSet(principal);
	if(!cal.IsSuccess()) {
		LOG("ERROR: Failed to get calendar home - " << cal.GetErrorDesc());
		return Null;
	}

	String homeset = ExtractCalendarHomeFromXml(xml);
	LOG("Calendar home: " << Nvl(homeset, principal));
	return Nvl(homeset, principal);
}

Vector<String> DiscoverCalendars(CalDAVRequest& cal, const String& homeset)
{
	String xml = cal.GetCalendars(homeset);
	if(!cal.IsSuccess()) {
		LOG("ERROR: Failed to get calendars - " << cal.GetErrorDesc());
		return {};
	}

	Vector<String> calendars = ExtractCalendarsFromXml(xml);
	LOG("Found " << calendars.GetCount() << " calendar(s):");
	for(const String& path : calendars)
		LOG("  " << path);

	return calendars;
}

bool CreateEvent(CalDAVRequest& cal, const String& calendar_path)
{
	String event = MakeCalendarEvent();
	bool success = cal.AddEvent(calendar_path, event);

	if(success)
		LOG("Event created in: " << calendar_path);
	else
		LOG("ERROR: Failed to create event - " << cal.GetErrorDesc());

	return success;
}

VectorMap<String, String> QueryEvents(CalDAVRequest& cal, const String& calendar_path,
									const String& start, const String& end)
{
	String xml = cal.GetEvents(calendar_path, start, end);
	if(!cal.IsSuccess()) {
		LOG("ERROR: Failed to query events - " << cal.GetErrorDesc());
		return {};
	}

	VectorMap<String, String> events = ExtractEventsFromXml(xml);
	LOG("Found " << events.GetCount() << " event(s) in range " << start << " to " << end);

	return events;
}

void DisplayEvents(const VectorMap<String, String>& events)
{
	for(int i = 0; i < events.GetCount(); i++) {
		LOG("\n--- Event " << (i + 1) << " ---");
		LOG("URL: " << events.GetKey(i));
		LOG("Data:\n" << events[i]);
	}
}

CONSOLE_APP_MAIN
{
	// Note that this example requires a running CalDAV service.
	// In order to test locally, radical calDAV server can be used.
	// E.g.: radicale --storage-filesystem-folder=~/.radicale/collections --auth-type=none
	// Change the username and port accordingly.
	
	StdLogSetup(LOG_FILE | LOG_COUT);

	CalDAVRequest cal("localhost", 80);
	cal.User("username", Null);

	// Discovery flow
	String principal = DiscoverPrincipal(cal);
	if(IsNull(principal))
		return;

	String homeset = DiscoverCalendarHome(cal, principal);
	if(IsNull(homeset))
		return;

	Vector<String> calendars = DiscoverCalendars(cal, homeset);
	if(calendars.IsEmpty()) {
		LOG("No calendars found");
		return;
	}

	// Work with first calendar
	String calendar = calendars[0];

	// Create an event
	CreateEvent(cal, calendar);

	// Query events in December 2025
	VectorMap<String, String> events = QueryEvents(cal, calendar,
													"20251201T000000Z",
													"20251231T235959Z");

	// Display results
	DisplayEvents(events);
}