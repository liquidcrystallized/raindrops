#ifndef RAINDROPS_STACKPANEL_HPP
#define RAINDROPS_STACKPANEL_HPP

#include "raygui-cpp/Component.h"

namespace raindrops
{
    /**
     * @brief rgc component implementation.<br>
     * A vertical stack panel that stores and displays controls sequentially.<br>
     * It's just a simple cross between WindowBox and GroupBox to remove<br>
     * the header buttons and make things look nicer.<br>
     * Made so controls can be grouped and moved together without using WindowBox.
     */
    class VerticalStackPanel final : public rgc::Component<bool> {
    public:
        VerticalStackPanel();
        explicit VerticalStackPanel(const char* title);
        VerticalStackPanel(rgc::Bounds bounds, const char* title);

        [[nodiscard]] const char* GetText() const;
        void SetText(const char* newTitle);

        [[nodiscard]] bool Show(bool canClick) override;

        void AddChild(Component* child) override;
    private:
        const char* m_text;
    };
}

#endif //RAINDROPS_STACKPANEL_HPP