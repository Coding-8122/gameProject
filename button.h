#pragma once

#include <SFML/Graphics.hpp>
#include <string>

/**
 * @brief Simple UI button used for menus (Play, Quit, etc.).
 *
 * Handles:
 * - Rectangle background
 * - Text label
 * - Colour change on hover / press
 * - Hit testing for mouse clicks
 */

class Button
{
public:
    Button();

    /**
     * @brief Construct a button with basic visual properties.
     * @param size Size of the button rectangle.
     * @param position Top-left pixel position on the window.
     * @param font Font used for the button label.
     * @param text Text to display inside the button.
     * @param characterSize Size of the text in pixels.
     */
    Button(const sf::Vector2f& size,
           const sf::Vector2f& position,
           const sf::Font&     font,
           const std::string&  text,
           unsigned int        characterSize = 24U);

    void setText(const std::string& text);
    void setPosition(const sf::Vector2f& position);
    void setSize(const sf::Vector2f& size);

    void setIdleColor(const sf::Color& color);
    void setHoverColor(const sf::Color& color);
    void setPressedColor(const sf::Color& color);

    /**
     * @brief Update the button state based on mouse position.
     * Call this once per frame before drawing.
     */
    void update(const sf::RenderWindow& window);

    /**
     * @brief Returns true if the button is clicked in this event.
     * @param window Reference to render window (for mouse position).
     * @param event  Event being processed (check for MouseButtonPressed).
     */
    bool isClicked(const sf::RenderWindow& window,
                   const sf::Event& event) const;

    /// Draw the button to the window.
    void draw(sf::RenderWindow& window) const;

private:
    bool contains(sf::Vector2f point) const;

    sf::RectangleShape m_shape;
    sf::Text           m_text;

    sf::Color          m_idleColor{ sf::Color(70, 70, 70) };
    sf::Color          m_hoverColor{ sf::Color(100, 100, 100) };
    sf::Color          m_pressedColor{ sf::Color(150, 150, 150) };
};
