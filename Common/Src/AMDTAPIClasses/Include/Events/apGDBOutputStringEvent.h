//==================================================================================
// Copyright (c) 2016 , Advanced Micro Devices, Inc.  All rights reserved.
//
/// \author AMD Developer Tools Team
/// \file apGDBOutputStringEvent.h
///
//==================================================================================

//------------------------------ apGDBOutputStringEvent.h ------------------------------

#ifndef __APGDBOUTPUTSTRINGEVENT
#define __APGDBOUTPUTSTRINGEVENT

// Forward declarations:
template <class TransferableObjectType> class osTransferableObjectCreator;

// Infra:
#include <AMDTBaseTools/Include/gtString.h>

// Local:
#include <AMDTAPIClasses/Include/Events/apEvent.h>


// ----------------------------------------------------------------------------------
// Class Name:           AP_API apGDBOutputStringEvent
// General Description:
//   Contains a string output, generated by GDB - the GNU Debugger.
// Author:  AMD Developer Tools Team
// Creation Date:        28/12/2006
// ----------------------------------------------------------------------------------
class AP_API apGDBOutputStringEvent : public apEvent
{
public:
    apGDBOutputStringEvent(const gtString& gdbOutputString);

    // Overrides osTransferableObject:
    virtual osTransferableObjectType type() const;
    virtual bool writeSelfIntoChannel(osChannel& ipcChannel) const;
    virtual bool readSelfFromChannel(osChannel& ipcChannel);

    // Overrides apEvent:
    virtual EventType eventType() const;
    virtual apEvent* clone() const;

    // Self functions:
    const gtString& gdbOutputString() const { return _gdbOutputString; };

private:
    void gdbMIStringToReadableString(const gtString& gdbMIString, gtString& readableString);

    friend class osTransferableObjectCreator<apGDBOutputStringEvent>;

    // Do not allow the use of the default constructor:
    apGDBOutputStringEvent();

private:
    // The outputted debug string:
    gtString _gdbOutputString;
};


#endif  // __APGDBOUTPUTSTRINGEVENT