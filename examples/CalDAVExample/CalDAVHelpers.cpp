#include "CalDAVExample.h"

using namespace Upp;

static const XmlNode& sFindNode(const XmlNode& node, const String& tag)
{
	if(node.IsTag(tag) && node.GetCount())
		return node[0];

	for(const XmlNode& child : node) {
		if(child.IsTag()) {
			if(const XmlNode& r = sFindNode(child, tag); !r.IsVoid())
				return r;
		}
	}

	return XmlNode::Void();
}

static void sExtractRefs(const XmlNode& n, Vector<String>& hrefs, bool& cal)
{
	if(n.IsTag("response")) {
		cal = false;
		for(const XmlNode& child : n)
			sExtractRefs(child, hrefs, cal);
	}
	else
	if(n.IsTag("C:calendar")) {
		cal = true;
	}
	else
	if(n.IsTag("href")) {
		if(cal && n.GetCount()) {
			hrefs.Add(n[0].GetText());
			cal = false;
		}
	}
	
	for(const XmlNode& child : n)
		sExtractRefs(child, hrefs, cal);
}

static void sExtractEvents(const XmlNode& n, VectorMap<String, String>& events, bool& event)
{
	if(n.IsTag("response")) {
		event = true;
		for(const XmlNode& child : n)
			sExtractEvents(child, events, event);
	}
	else
	if(n.IsTag("C:calendar-data")) {
		if(event && n.GetCount()) {
			events.Top() = n[0].GetText();
			event = false;
		}
	}
	else
	if(n.IsTag("href")) {
		if(event && n.GetCount())
			events.Add(n[0].GetText());
	}
	
	for(const XmlNode& child : n)
		sExtractEvents(child, events, event);
}

String ExtractPrincipalFromXml(const String& xml)
{
	const XmlNode& node = ParseXML(xml);
	const XmlNode& principal = sFindNode(node, "current-user-principal");
	return sFindNode(principal, "href").GetText();
}

String ExtractCalendarHomeFromXml(const String& xml)
{
	const XmlNode& node = ParseXML(xml);
	const XmlNode& home_set = sFindNode(node, "C:calendar-home-set");
	return sFindNode(home_set, "D:href").GetText();
}

Vector<String> ExtractCalendarsFromXml(const String& xml)
{
	bool cal = false;
	Vector<String> urls;
	sExtractRefs(ParseXML(xml), urls, cal);
	return pick(urls);
}

VectorMap<String, String> ExtractEventsFromXml(const String& xml)
{
	bool ev = false;
	VectorMap<String, String> urls;
	sExtractEvents(ParseXML(xml), urls, ev);
	return pick(urls);
}

String GetFormattedTime(Time t)
{
	return Format("%4d%2d%2d`T%2d%2d%2d`Z", t.year, t.month, t.day, t.hour, t.minute, t.second);
}

String MakeCalendarEvent()
{
	String event =
		"BEGIN:VCALENDAR\r\n"
		"VERSION:2.0\r\n"
		"PRODID:-//U++ CalDAV//EN\r\n"
		"BEGIN:VEVENT\r\n"
		"UID:" + AsString(UuidValueGen().Get()) + "\r\n"
		"DTSTAMP:" + GetFormattedTime(GetSysTime()) + "\r\n"
		"DTSTART:20251215T100000Z\r\n"
		"DTEND:20251215T110000Z\r\n"
		"SUMMARY:Test Meeting\r\n"
		"DESCRIPTION:This is a test event from U++\r\n"
		"END:VEVENT\r\n"
		"END:VCALENDAR\r\n";
	return event;
}
