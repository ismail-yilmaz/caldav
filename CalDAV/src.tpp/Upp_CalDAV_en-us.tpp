topic "CalDAVRequest";
[i448;a25;kKO9;2 $$1,0#37138531426314131252341829483380:class]
[l288;2 $$2,2#27521748481378242620020725143825:desc]
[0 $$3,0#96390100711032703541132217272105:end]
[H6;0 $$4,0#05600065144404261032431302351956:begin]
[i448;a25;kKO9;2 $$5,0#37138531426314131252341829483370:item]
[l288;a4;*@5;1 $$6,6#70004532496200323422659154056402:requirement]
[l288;i1121;b17;O9;~~~.1408;2 $$7,0#10431211400427159095818037425705:param]
[i448;b42;O9;2 $$8,8#61672508125594000341940100500538:tparam]
[b42;2 $$9,9#13035079074754324216151401829390:normal]
[2 $$0,0#00000000000000000000000000000000:Default]
[{_} 
[ {{10000@(113.42.0) [s0;%% [*@7;4 CalDAVRequest]]}}&]
[s3; &]
[s1;:Upp`:`:CalDAVRequest: [@(0.0.255)3 class][3  ][*3 CalDAVRequest][3  
][@(0.0.255)3 :][3  ][@(0.0.255)3 public][3  WebDAVRequest]&]
[s2;%% CalDAVRequest is a CalDAV client implementation that extends 
[^topic`:`/`/WebDAV`/src`/Upp`_WebDAV`_en`-us`#Upp`:`:WebDAVRequest^ WebDAVRequest 
]to provide calendar`-specific operations following RFC 4791. 
It supports calendar discovery, event management, and calendar 
queries with both blocking and non`-blocking operation modes.&]
[s3; &]
[ {{10000F(128)G(128)@1 [s0;%% [* Constructor detail]]}}&]
[s3; &]
[s5;:Upp`:`:CalDAVRequest`:`:CalDAVRequest`(`): [* CalDAVRequest]()&]
[s2;%% Default constructor.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CalDAVRequest`:`:CalDAVRequest`(const String`&`,int`): [* CalDAVRequest]([@(0.0.255) c
onst] String[@(0.0.255) `&] [*@3 host], [@(0.0.255) int] [*@3 port] [@(0.0.255) `=] 
[@3 80])&]
[s2;%% Constructs with the specified [%-*@3 host] and [%-*@3 port] . 
The host parameter is the server hostname or IP address, and 
port is the server port.&]
[s3; &]
[ {{10000F(128)G(128)@1 [s0;%% [* Non`-Blocking Methods]]}}&]
[s3; &]
[s2; Non`-blocking methods begins with Start prefix and initialize 
the given operation. Use [^topic`:`/`/Core`/src`/HttpRequest`_en`-us`#HttpRequest`:`:Do`(`)^ D
o()] method to drive the operation to completion. Check [^topic`:`/`/Core`/src`/HttpRequest`_en`-us`#HttpRequest`:`:IsSuccess`(`)const^ I
sSuccess()] after completion to verify the operation succeeded.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CalDAVRequest`:`:StartGetCurrentUserPrincipal`(`): [@(0.0.255) void] 
[* StartGetCurrentUserPrincipal]()&]
[s0;l288;%% Starts retrieving the current user principal information 
for the authenticated user. This is typically required to locate 
the user’s calendar collections.  [^topic`:`/`/Core`/src`/HttpRequest`_en`-us`#HttpRequest`:`:GetContent`(`)const^ G
etContent()] method can be used to retrieve the data after a 
successful completion. Or [^topic`:`/`/Core`/src`/HttpRequest`_en`-us`#HttpRequest`:`:WhenContent^ W
henContent] event can be used to redirect the output. Note that 
the result will be in XML format.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CalDAVRequest`:`:StartGetCalendarHomeSet`(const String`&`): [@(0.0.255) voi
d] [* StartGetCalendarHomeSet]([@(0.0.255) const] String[@(0.0.255) `&] 
[*@3 path])&]
[s2;%% Starts fetching the calendar home set associated with the 
specified principal [%-*@3 path]. [^topic`:`/`/Core`/src`/HttpRequest`_en`-us`#HttpRequest`:`:GetContent`(`)const^ G
etContent()] method can be used to retrieve the data after a 
successful completion. Or [^topic`:`/`/Core`/src`/HttpRequest`_en`-us`#HttpRequest`:`:WhenContent^ W
henContent] event can be used to redirect the output. The result 
contains the XML response body for custom parsing.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CalDAVRequest`:`:StartGetCalendars`(const String`&`): [@(0.0.255) void] 
[* StartGetCalendars]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path])&]
[s0;l288;%% Starts fetching the list of available calendar collections 
under the given home set [%-*@3 path] .&]
[s2;%% [^topic`:`/`/Core`/src`/HttpRequest`_en`-us`#HttpRequest`:`:GetContent`(`)const^ G
etContent()] method can be used to retrieve the data after a 
successful completion. Or [^topic`:`/`/Core`/src`/HttpRequest`_en`-us`#HttpRequest`:`:WhenContent^ W
henContent] event can be used to redirect the output. The result 
contains the XML response body for custom parsing.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CalDAVRequest`:`:StartGetEvents`(const String`&`,const String`&`,const String`&`): [@(0.0.255) v
oid] [* StartGetEvents]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path], 
[@(0.0.255) const] String[@(0.0.255) `&] [*@3 start`_time] [@(0.0.255) `=] 
Null, [@(0.0.255) const] String[@(0.0.255) `&] [*@3 end`_time] [@(0.0.255) `=] 
Null)&]
[s0;l288;%% Starts querying events within a time range. The [%-*@3 path] 
parameter is the calendar collection path. The [%-*@3 start`_time] 
and [%-*@3 end`_time ]parameters are optional ISO 8601 formatted 
timestamps. [^topic`:`/`/Core`/src`/HttpRequest`_en`-us`#HttpRequest`:`:GetContent`(`)const^ G
etContent()] method can be used to retrieve the data after a 
successful completion. Or [^topic`:`/`/Core`/src`/HttpRequest`_en`-us`#HttpRequest`:`:WhenContent^ W
henContent] event can be used to redirect the output. The result 
contains the XML response body for custom parsing.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CalDAVRequest`:`:StartGetEvents`(const String`&`,const Vector`&`): [@(0.0.255) v
oid] [* StartGetEvents]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path], 
[@(0.0.255) const] Vector<String>[@(0.0.255) `&] [*@3 urls])&]
[s2;%% Starts a calendar`-multiget REPORT for efficient retrieval 
of specific events. The [%-*@3 path] parameter specifies the calendar 
collection to search. The [%-*@3 urls ] paramater specifies the 
events. [^topic`:`/`/Core`/src`/HttpRequest`_en`-us`#HttpRequest`:`:GetContent`(`)const^ G
etContent()] method can be used to retrieve the data after a 
successful completion. Or [^topic`:`/`/Core`/src`/HttpRequest`_en`-us`#HttpRequest`:`:WhenContent^ W
henContent] event can be used to redirect the output. The result 
contains the XML response body for custom parsing.&]
[s3;%% &]
[s4; &]
[s5;:Upp`:`:CalDAVRequest`:`:StartAddEvent`(const String`&`,const String`&`): [@(0.0.255) v
oid] [* StartAddEvent]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path], 
[@(0.0.255) const] String[@(0.0.255) `&] [*@3 ical`_data])&]
[s2;%% Starts event creation in a calendar collection. The [%-*@3 path 
]parameter is the calendar collection path, and ical`_data contains 
the event in iCalendar format (RFC 5545). A unique filename is 
generated automatically using timestamp and UUID.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CalDAVRequest`:`:StartUpdateEvent`(const String`&`,const String`&`,const String`&`): [@(0.0.255) v
oid] [* StartUpdateEvent]([@(0.0.255) const] String[@(0.0.255) `&] 
[*@3 path], [@(0.0.255) const] String[@(0.0.255) `&] [*@3 ical`_data], 
[@(0.0.255) const] String[@(0.0.255) `&] [*@3 etag] [@(0.0.255) `=] Null)&]
[s2;%% Starts event modification in a calendar collection. The [%-*@3 path 
]parameter is the event resource URL, [%-*@3 ical`_data] contains 
the updated event in iCalendar format, and [%-*@3 etag] is an optional 
ETag for optimistic concurrency control. If provided, the update 
only succeeds if the server`'s ETag matches.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CalDAVRequest`:`:StartDeleteEvent`(const String`&`): [@(0.0.255) void] 
[* StartDeleteEvent]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path])&]
[s2;%%  Starts event deletion. The [%-*@3 path] parameter is the event 
resource URL to delete.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CalDAVRequest`:`:StartGetEvent`(const String`&`): [@(0.0.255) void] 
[* StartGetEvent]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path])&]
[s2;%% Starts retrieval of a specific event. The [%-*@3 path] parameter 
is the event resource URL. [^topic`:`/`/Core`/src`/HttpRequest`_en`-us`#HttpRequest`:`:GetContent`(`)const^ G
etContent()] method can be used to retrieve the data after a 
successful completion. Or [^topic`:`/`/Core`/src`/HttpRequest`_en`-us`#HttpRequest`:`:WhenContent^ W
henContent] event can be used to redirect the output. The result 
contains the XML response body for custom parsing.&]
[s3; &]
[ {{10000F(128)G(128)@1 [s0;%% [* Blocking Methods]]}}&]
[s3; &]
[s2; Blocking methods execute immediately and return when the operation 
completes.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CalDAVRequest`:`:GetCurrentUserPrincipal`(`): String 
[* GetCurrentUserPrincipal]()&]
[s2;%% Retrieves the current user principal information for the authenticated 
user on success. This is typically required to locate the user’s 
calendar collections.  Note that the result will be in XML format.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CalDAVRequest`:`:GetCalendarHomeSet`(const String`&`): String 
[* GetCalendarHomeSet]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path])&]
[s2;%% Fetches the calendar home set associated with the specified 
principal [%-*@3 path]. Returns the XML response body for custom 
parsing if successful.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CalDAVRequest`:`:GetCalendars`(const String`&`): String 
[* GetCalendars]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path])&]
[s2;%% Fetches the list of available calendar collections under the 
given home set [%-*@3 path]. Returns the XML response body for 
custom parsing if successful.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CalDAVRequest`:`:GetEvents`(const String`&`,const String`&`,const String`&`): S
tring [* GetEvents]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path], 
[@(0.0.255) const] String[@(0.0.255) `&] [*@3 start`_time] [@(0.0.255) `=] 
Null, [@(0.0.255) const] String[@(0.0.255) `&] [*@3 end`_time] [@(0.0.255) `=] 
Null)&]
[s2;%% Queries events within a time range. The [%-*@3 path] parameter 
is the calendar collection path. The [%-*@3 start`_time] and [%-*@3 end`_time 
]parameters are optional ISO 8601 formatted timestamps. Returns 
raw XML response containing matching events with their calendar 
data and ETags if successful.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CalDAVRequest`:`:GetEvents`(const String`&`,const Vector`&`): String 
[* GetEvents]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path], [@(0.0.255) const] 
Vector<String>[@(0.0.255) `&] [*@3 urls])&]
[s2;%% Retrieves specific events by URLs. The [%-*@3 path] parameter 
is the calendar collection path, and [%-*@3 urls] contains event 
resource URLs. Returns raw XML response containing the requested 
events with their calendar data and ETags if successful.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CalDAVRequest`:`:AddEvent`(const String`&`,const String`&`): [@(0.0.255) bo
ol] [* AddEvent]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path], 
[@(0.0.255) const] String[@(0.0.255) `&] [*@3 ical`_data])&]
[s2;%% Creates a new event. The [%-*@3 path] parameter is the calendar 
collection path, and [%-*@3 ical`_data] contains the event in iCalendar 
format. Returns true if successful.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CalDAVRequest`:`:UpdateEvent`(const String`&`,const String`&`,const String`&`): [@(0.0.255) b
ool] [* UpdateEvent]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path], 
[@(0.0.255) const] String[@(0.0.255) `&] [*@3 ical`_data], [@(0.0.255) const] 
String[@(0.0.255) `&] [*@3 etag] [@(0.0.255) `=] Null)&]
[s2;%% Updates an existing event. The [%-*@3 path] parameter is the 
event resource URL, [%-*@3 ical`_data] contains the updated event, 
and [%-*@3 etag] is optional for conditional updates. Returns true 
if successful. &]
[s3; &]
[s4; &]
[s5;:Upp`:`:CalDAVRequest`:`:DeleteEvent`(const String`&`): [@(0.0.255) bool] 
[* DeleteEvent]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path])&]
[s2;%% Deletes an event. The [%-*@3 path] parameter is the event resource 
URL. Returns true if successful.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CalDAVRequest`:`:GetEvent`(const String`&`): String [* GetEvent]([@(0.0.255) c
onst] String[@(0.0.255) `&] [*@3 path])&]
[s2;%% Retrieves a specific event. The path parameter is the event 
resource URL. Returns the event in iCalendar format. [%-*@3 path] 
.&]
[s3; &]
[s0;%% ]]