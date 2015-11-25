/*	File:		FileLogging.h	Contains:	File logging engine for OTStreamLogViewer.	Written by:	Quinn "The Eskimo!"	Copyright:	� 1998 by Apple Computer, Inc., all rights reserved.	Change History (most recent first):	You may incorporate this sample code into your applications without	restriction, though the sample code has been provided "AS IS" and the	responsibility for its operation is 100% yours.  However, what you are	not permitted to do is to redistribute the source as "DSC Sample Code"	after having made changes. If you're going to re-distribute the source,	we require that you make it clear in the source that the code was	descended from Apple Sample Code, but that you've made changes.*/#pragma once/////////////////////////////////////////////////////////////////////// Pick up LogEntryPtr definition.#include "LogEngine.h"/////////////////////////////////////////////////////////////////////extern OSStatus StartFileLogging(void);	// Tells the file log module that we're about to	// start logging records to the file using RecordLogEntryToFile.	// Returns an error if the file logging module could not	// start up, in which case the client should not call	// StopFileLogging.// The following two routines both use the same assembly// buffer. If you call LogEntryToCString, you must copy the// results out of the buffer before you call either of// these routines again.extern char *LogEntryToCString(LogEntryPtr thisEntry);	// Converts a log entry to a string.  The log module	// has to do this anyway, so we export the function	// for use by the clipboard code.	extern void RecordLogEntryToFile(LogEntryPtr thisEntry);	// Record a log entry to the log file.extern void FileLoggingIdle(void);	// This routine is called periodically by the client	// to flush out any pending log entries.	extern Boolean FileLoggingActive(void);	// Returns whether a log file is currently open or not.extern void StopFileLogging(void);	// Called by the client to shut down the file logging	// module.	