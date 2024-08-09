/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus' Graphical User Interface
// Copyright (C) 2012-2024 Bruno Van de Velde (vdv_b@tgui.eu)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef TGUI_LABEL_HPP
#define TGUI_LABEL_HPP

#include <TGUI/Widgets/ClickableWidget.hpp>
#include <TGUI/Renderers/LabelRenderer.hpp>
#include <TGUI/CopiedSharedPtr.hpp>
#include <TGUI/Widgets/Scrollbar.hpp>
#include <TGUI/Text.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TGUI_MODULE_EXPORT namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Label widget
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class TGUI_API Label : public ClickableWidget
    {
    public:

        using Ptr = std::shared_ptr<Label>; //!< Shared widget pointer
        using ConstPtr = std::shared_ptr<const Label>; //!< Shared constant widget pointer

        static constexpr const char StaticWidgetType[] = "Label"; //!< Type name of the widget

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief The horizontal text alignment
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        using HorizontalAlignment TGUI_DEPRECATED("Use tgui::HorizontalAlignment instead") = tgui::HorizontalAlignment;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief The vertical text alignment
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        using VerticalAlignment TGUI_DEPRECATED("Use tgui::VerticalAlignment instead") = tgui::VerticalAlignment;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /// @brief Constructor
        /// @param typeName     Type of the widget
        /// @param initRenderer Should the renderer be initialized? Should be true unless a derived class initializes it.
        /// @see create
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Label(const char* typeName = StaticWidgetType, bool initRenderer = true);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Creates a new label widget
        ///
        /// @param text  The text to display
        ///
        /// @return The new label
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD static Label::Ptr create(const String& text = "");

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Makes a copy of another label
        ///
        /// @param label  The other label
        ///
        /// @return The new label
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD static Label::Ptr copy(const Label::ConstPtr& label);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the renderer, which gives access to functions that determine how the widget is displayed
        /// @return Temporary pointer to the renderer that may be shared with other widgets using the same renderer
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD LabelRenderer* getSharedRenderer() override;
        TGUI_NODISCARD const LabelRenderer* getSharedRenderer() const override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the renderer, which gives access to functions that determine how the widget is displayed
        /// @return Temporary pointer to the renderer
        /// @warning After calling this function, the widget has its own copy of the renderer and it will no longer be shared.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD LabelRenderer* getRenderer() override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the area of the text that will be drawn
        ///
        /// @param size  Size of the part to draw
        ///
        /// Only the part of the text that lies within the size will be drawn.
        ///
        /// When a background color is set, the drawn background will have this size.
        /// So setting a size that is bigger than the text will result in a bigger area being filled.
        ///
        /// When this function is called, the label will no longer be auto-sizing.
        ///
        /// @see setAutoSize
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setSize(const Layout2d& size) override;
        using Widget::setSize;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the text
        ///
        /// @param text  The new text
        ///
        /// When the text is auto-sized (default), then the size of the label will be changed to fit the whole text.
        ///
        /// @see setAutoSize
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setText(const String& text);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the text
        ///
        /// @return Text that is currently used
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD const String& getText() const;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the horizontal text alignment
        ///
        /// @param alignment  The new horizontal text alignment
        ///
        /// By default the text is aligned to the left.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setHorizontalAlignment(tgui::HorizontalAlignment alignment); // TGUI_NEXT: Remove "tgui::" prefix

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Gets the current horizontal text alignment
        ///
        /// @return Horizontal text alignment
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD tgui::HorizontalAlignment getHorizontalAlignment() const; // TGUI_NEXT: Remove "tgui::" prefix

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the vertical text alignment
        ///
        /// @param alignment  The new vertical text alignment
        ///
        /// By default the text is aligned to the top.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setVerticalAlignment(tgui::VerticalAlignment alignment); // TGUI_NEXT: Remove "tgui::" prefix

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Gets the current vertical text alignment
        ///
        /// @return Vertical text alignment
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD tgui::VerticalAlignment getVerticalAlignment() const; // TGUI_NEXT: Remove "tgui::" prefix

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes when the vertical scrollbar should be displayed
        /// @param policy  The policy for displaying the vertical scrollbar
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setScrollbarPolicy(Scrollbar::Policy policy);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns when the vertical scrollbar should be displayed
        /// @return The policy for displaying the vertical scrollbar
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Scrollbar::Policy getScrollbarPolicy() const;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the thumb position of the scrollbar
        ///
        /// @param value  New value of the scrollbar
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setScrollbarValue(unsigned int value);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the thumb position of the scrollbar
        ///
        /// @return Value of the scrollbar
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD unsigned int getScrollbarValue() const;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the maximum thumb position of the scrollbar
        ///
        /// @return Maximum value of the scrollbar
        ///
        /// @since TGUI 1.4
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD unsigned int getScrollbarMaxValue() const;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes whether the label is auto-sized or not
        ///
        /// @param autoSize  Should the size of the label be changed when the text changes?
        ///
        /// When the label is in auto-size mode, the width and height of the label will be changed to fit the text.
        /// Otherwise, only the part defined by the size will be visible.
        ///
        /// The label is auto-sized by default.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setAutoSize(bool autoSize);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns whether the label is auto-sized or not
        ///
        /// @return Is the size of the label changed when the text changes?
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD bool getAutoSize() const;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the maximum width that the text will have when auto-sizing
        ///
        /// @param maximumWidth The new maximum text width
        ///
        /// This property is ignored when an exact size has been given.
        /// Pass 0 to this function to disable the maximum.
        ///
        /// When the text is auto-sizing then the text will be split over several lines when its width would exceed the
        /// value passed to this function.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setMaximumTextWidth(float maximumWidth);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the maximum width that the text will have
        ///
        /// @return
        ///        - The width of the label minus the padding when a specific size was set.
        ///        - The maximum text width when auto-sizing and a maximum was set.
        ///        - 0 when auto-sizing but there is no maximum width.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD float getMaximumTextWidth() const;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Sets whether the widget should completely ignore mouse events and let them pass to the widgets behind it
        ///
        /// @param ignore  Should mouse events be ignored by this widget?
        ///
        /// By default, mouse events are NOT ignored.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_DEPRECATED("Use setIgnoreMouseEvents instead") void ignoreMouseEvents(bool ignore = true);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns whether the widget is ignoring mouse events and letting them pass to the widgets behind it
        ///
        /// @return Are mouse events ignored by this widget?
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_DEPRECATED("Use getIgnoreMouseEvents instead") TGUI_NODISCARD bool isIgnoringMouseEvents() const;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /// This function is called when the widget is added to a container.
        /// You should not call this function yourself.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setParent(Container* parent) override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns whether the widget can gain focus
        /// @return Can the widget be focused?
        ///
        /// This function returns false for Label widgets.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD bool canGainFocus() const override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns whether the mouse position (which is relative to the parent widget) lies on top of the widget
        /// @return Is the mouse on top of the widget?
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD bool isMouseOnWidget(Vector2f pos) const override;

        /// @internal
        bool leftMousePressed(Vector2f pos) override;

        /// @internal
        void leftMouseReleased(Vector2f pos) override;

        /// @internal
        void mouseMoved(Vector2f pos) override;

        /// @internal
        bool scrolled(float delta, Vector2f pos, bool touch) override;

        /// @internal
        void mouseNoLongerOnWidget() override;

        /// @internal
        void leftMouseButtonNoLongerDown() override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Draw the widget to a render target
        ///
        /// @param target Render target to draw to
        /// @param states Current render states
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void draw(BackendRenderTarget& target, RenderStates states) const override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Retrieves a signal based on its name
        ///
        /// @param signalName  Name of the signal
        ///
        /// @return Signal that corresponds to the name
        ///
        /// @throw Exception when the name does not match any signal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Signal& getSignal(String signalName) override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Function called when one of the properties of the renderer is changed
        ///
        /// @param property  Name of the property that was changed
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void rendererChanged(const String& property) override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Saves the widget as a tree node in order to save it to a file
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD std::unique_ptr<DataIO::Node> save(SavingRenderersMap& renderers) const override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Loads the widget from a tree of nodes
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void load(const std::unique_ptr<DataIO::Node>& node, const LoadingRenderersMap& renderers) override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Called when the text size is changed (either by setTextSize or via the renderer)
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void updateTextSize() override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // This function is called every frame with the time passed since the last frame.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool updateTime(Duration elapsedTime) override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Rearrange the text (recreates m_textPieces), making use of the given size of maximum text width.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void rearrangeText();

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Called at the end of rearrangeText() to position the text pieces that were created during rearrangeText().
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void updateTextPiecePositions(float maxWidth);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Makes a copy of the widget
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_NODISCARD Widget::Ptr clone() const override;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    public:

        SignalString onDoubleClick = {"DoubleClicked"}; //!< The label was double clicked. Optional parameter: text of the label

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        String m_string;
        std::vector<std::vector<Text>> m_lines;

        // TGUI_NEXT: Remove "tgui::" prefixes
        tgui::HorizontalAlignment m_horizontalAlignment = tgui::HorizontalAlignment::Left;
        tgui::VerticalAlignment m_verticalAlignment = tgui::VerticalAlignment::Top;

        bool m_autoSize = true;

        float m_maximumTextWidth = 0;

        bool m_ignoringMouseEvents = false; // TGUI_NEXT: Remove this property

        // Will be set to true after the first click, but gets reset to false when the second click does not occur soon after
        bool m_possibleDoubleClick = false;

        CopiedSharedPtr<ScrollbarChildWidget> m_scrollbar;
        Scrollbar::Policy  m_scrollbarPolicy = Scrollbar::Policy::Automatic;

        Sprite    m_spriteBackground;

        // Cached renderer properties
        Borders   m_bordersCached;
        Padding   m_paddingCached;
        TextStyles m_textStyleCached;
        Color     m_textColorCached;
        Color     m_borderColorCached;
        Color     m_backgroundColorCached;
        Color     m_textOutlineColorCached;
        float     m_textOutlineThicknessCached = 0;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_LABEL_HPP
