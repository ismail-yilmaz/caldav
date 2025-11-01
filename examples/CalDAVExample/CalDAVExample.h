#ifndef _CalDAVExample_CalDAVExample_h
#define _CalDAVExample_CalDAVExample_h

#include <Core/Core.h>
#include <CalDAV/CalDAV.h>

using namespace Upp;

// Helpers for CalDAV responses.
String ExtractPrincipalFromXml(const String& xml);
String ExtractCalendarHomeFromXml(const String& xml);
Vector<String> ExtractCalendarsFromXml(const String& xml);
VectorMap<String, String> ExtractEventsFromXml(const String& xml);
String GetFormattedTime(Time t);
String MakeCalendarEvent();


#endif
