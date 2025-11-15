#include "VerticalStackPanel.hpp"
#include <raygui.h>

namespace raindrops
{
    VerticalStackPanel::VerticalStackPanel() : m_text { nullptr } {}

    VerticalStackPanel::VerticalStackPanel(const char* title) : m_text { title } {}

    VerticalStackPanel::VerticalStackPanel(const rgc::Bounds bounds, const char* title)
    : Component { bounds }
    , m_text { title }
    {
        //
    }

    const char* VerticalStackPanel::GetText() const
    {
        return m_text;
    }

    void VerticalStackPanel::SetText(const char* newTitle)
    {
        m_text = newTitle;
    }

    bool VerticalStackPanel::Show(const bool canClick)
    {
        const int ret = GuiGroupBox(GetBounds().GetRectangle(), m_text);

        this->ShowChildren(canClick);

        return ret;
    }

    void VerticalStackPanel::AddChild(Component* child)
    {
        this->AddChildInternal(child);
    }
}