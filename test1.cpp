#include <SFML/Graphics.hpp>
#include <cmath>

int main() {
    sf::RenderWindow window(sf::VideoMode(300, 300), "Circle with Gradient Colors");

    const int textureSize = 700;
    const float circleRadius = 7.56;
    const sf::Vector2f circleCenter(100, 100);

    // Create an image
    sf::Image image;
    image.create(textureSize, textureSize, sf::Color::Transparent);

    // Fill the image with pixel colors
    for (int y = 0; y < textureSize; ++y) {
        for (int x = 0; x < textureSize; ++x) {
            float dx = x - circleCenter.x;
            float dy = y - circleCenter.y;
            float distance = std::sqrt(dx * dx + dy * dy);

            if (distance <= circleRadius) {
                // Gradient color based on distance
                float gradient = distance / circleRadius;
                sf::Uint8 r = static_cast<sf::Uint8>(gradient * 255);
                sf::Uint8 g = static_cast<sf::Uint8>((1.0f - gradient) * 255);
                sf::Uint8 b = static_cast<sf::Uint8>((0.5f + 0.5f * gradient) * 255);

                image.setPixel(x, y, sf::Color(r, g, b));
            }
        }
    }

    // Create a texture and sprite
    sf::Texture texture;
    texture.loadFromImage(image);

    sf::Sprite sprite(texture);

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Render the sprite
        window.clear(sf::Color::Black);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
