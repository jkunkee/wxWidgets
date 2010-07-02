///////////////////////////////////////////////////////////////////////////////
// Name:        tests/controls/listbooktest.cpp
// Purpose:     wxListbook unit test
// Author:      Steven Lamerton
// Created:     2010-07-02
// RCS-ID:      $Id$
// Copyright:   (c) 2010 Steven Lamerton
///////////////////////////////////////////////////////////////////////////////

#include "testprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include "wx/app.h"
    #include "wx/panel.h"
#endif // WX_PRECOMP

#include "wx/listbook.h"
#include "bookctrlbasetest.h"

class ListbookTestCase : public BookCtrlBaseTestCase
{
public:
    ListbookTestCase() { }

    virtual void setUp();
    virtual void tearDown();

private:
    virtual wxBookCtrlBase *GetBase() const { return m_listbook; }

    virtual wxEventType GetChangedEvent() const
    { return wxEVT_COMMAND_LISTBOOK_PAGE_CHANGED; }

    virtual wxEventType GetChangingEvent() const
    { return wxEVT_COMMAND_LISTBOOK_PAGE_CHANGING; }

    CPPUNIT_TEST_SUITE( ListbookTestCase );
        wxBOOK_CTRL_BASE_TESTS();
    CPPUNIT_TEST_SUITE_END();

    wxListbook *m_listbook;

    DECLARE_NO_COPY_CLASS(ListbookTestCase)
};

// register in the unnamed registry so that these tests are run by default
CPPUNIT_TEST_SUITE_REGISTRATION( ListbookTestCase );

// also include in it's own registry so that these tests can be run alone
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( ListbookTestCase, "ListbookTestCase" );

void ListbookTestCase::setUp()
{
    m_listbook = new wxListbook(wxTheApp->GetTopWindow(), wxID_ANY);
    AddPanels();
}

void ListbookTestCase::tearDown()
{
    wxDELETE(m_listbook);
}
