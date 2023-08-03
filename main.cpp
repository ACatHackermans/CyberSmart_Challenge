#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;

float calculateDistance (const Vector2f& point1, const Vector2f& point2)
{
    float distanceX = point2.x - point1.x + 50;
    float distanceY = point2.y - point1.y + 50;
    return sqrt(distanceX * distanceX + distanceY * distanceY);
}
void menu_button ()
{

}

int main()
{
    RenderWindow window(VideoMode(1920, 1080), "CyberSmart Challenge", Style::Fullscreen);
    bool menu = true;

    Texture close_button, play_button, settings_button, info_button, back_button, background1;
    if (!close_button.loadFromFile("resources/close_button.png") || !play_button.loadFromFile("resources/play_button.png") 
    || !settings_button.loadFromFile("resources/settings_button.png") || !info_button.loadFromFile("resources/info_button.png")
    || !back_button.loadFromFile("resources/back_button.png") || !background1.loadFromFile("resources/background1.png"))
    {
        return 0;
    }

    Sprite closebutton(close_button), playbutton(play_button), settingsbutton(settings_button), infobutton(info_button), bg1(background1);
    closebutton.setScale(0.15, 0.15);
    closebutton.setPosition(Vector2f(100, 50));
    playbutton.setScale(0.15, 0.15);
    playbutton.setPosition(Vector2f(800, 500));
    settingsbutton.setScale(0.15, 0.15);
    settingsbutton.setPosition(Vector2f(100, 830));
    infobutton.setScale(0.15, 0.15);
    infobutton.setPosition(Vector2f(1520, 830));

    while (window.isOpen())
    {    
        Event event;
        Vector2f mousePosition = static_cast<Vector2f>(Mouse::getPosition(window));

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
                    window.close();
                }
                break;   

            case Event::MouseButtonPressed:
                if (event.mouseButton.button == Mouse::Left)
                {
                    if (menu == true)
                    {    float closestDistance = 50;
                        if (calculateDistance(mousePosition, closebutton.getPosition()) < closestDistance)
                        {
                            return 0;
                        }
                        if (calculateDistance(mousePosition, playbutton.getPosition()) < closestDistance)
                        {
                            menu = false;
                        }
                        if (calculateDistance(mousePosition, settingsbutton.getPosition()) < closestDistance)
                        {
                            return 0;
                        }
                        if (calculateDistance(mousePosition, infobutton.getPosition()) < closestDistance)
                        {
                            return 0;
                        }
                    }
                }
                    break;         
            }
        }

        window.clear();

        window.draw(bg1);
        
        if (menu == true)
        {          
            window.draw(closebutton);
            window.draw(playbutton);
            window.draw(settingsbutton);
            window.draw(infobutton);
        }

        window.display();
    }



    return 0;
}
