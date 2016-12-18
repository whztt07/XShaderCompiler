/*
 * ReportView.cpp
 * 
 * This file is part of the XShaderCompiler project (Copyright (c) 2014-2016 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#include "ReportView.h"


namespace Xsc
{


ReportView::ReportView(wxWindow* parent, const wxPoint& pos, const wxSize& size) :
    wxListBox{ parent, wxID_ANY, pos, size }
{
    wxFont font(wxFontInfo(8).Family(wxFONTFAMILY_MODERN));
    SetFont(font);
}

void ReportView::AddReport(const Report& r)
{
    Add(r.Context());
    Add(r.Message());

    if (r.HasLine())
    {
        Add(r.Line());
        Add(r.Marker());
    }

    for (const auto& s : r.GetHints())
        Add(s);
}


/*
 * ======= Private: =======
 */

void ReportView::Add(const std::string& s)
{
    if (!s.empty())
        Append(s);
}


} // /namespace Xsc



// ================================================================================