# CalDAV Package for U++

A lightweight, RFC 4791-compliant **CalDAV client** for U++.
Implements calendar discovery, event management, and scheduling operations over HTTP/WebDAV protocol.

## Features

- **Full CalDAV coverage**: discovery, event retrieval, creation, update, and deletion
- **Dual operation modes**: blocking and non-blocking
- **Built on WebDAV**: extends `WebDAVRequest`, inheriting all HTTP functionality, including SSL, authentication, and redirection
- **Simple U++ API**: clean, self-contained interface using familiar U++ conventions

## Supported Operations

- **Principal and home discovery**: `GetCurrentUserPrincipal`, `GetCalendarHomeSet`
- **Calendar collection discovery**: `GetCalendars`
- **Event retrieval**: `GetEvents`, `GetEvent`
- **Event modification**: `AddEvent`, `UpdateEvent`, `DeleteEvent`
- **Non-blocking variants**: all `Start*` methods correspond to blocking calls

## Examples

| Name              | Description                                                                      |
| ----------------- | -------------------------------------------------------------------------------- |
| **CalDAVExample** | Demonstrates connecting to a CalDAV server, listing calendars, and adding events |


