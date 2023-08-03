#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    bool exit = false;

    RenderWindow window(VideoMode(1600, 900), "CyberSmart Challenge", Style::Fullscreen);
    // Texture close_button;
    // if (!close_button.loadFromFile("close_button.png"))
    // {

    // }

    while (!exit)
    {
        while (window.isOpen())
        {    Event event;
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                case Event::Closed:
                    window.close();
                    break;

                case Event::KeyPressed:
                    if (event.key.code == Keyboard::Escape)
                    {   
                        exit = true;
                        window.close();
                    }
                    break;            
                }
            }

            window.clear();

            //window.draw(close_button);

            window.display();
        }
    }

    return 0;
}