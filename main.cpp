#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;

float calculateDistance (const Vector2f& point1, const Vector2f& point2)
{
    float distanceX = point2.x - point1.x + 70;
    float distanceY = point2.y - point1.y + 70;
    return sqrt(distanceX * distanceX + distanceY * distanceY);
}

int main()
{
    RenderWindow window(VideoMode(1920, 1080), "CyberSmart Challenge", Style::Fullscreen);
    bool menu = true;
    bool easy = false, hard = false;

    Texture close_button, play_button, settings_button, info_button, back_button, background1, easy_button, hard_button;
    if (!close_button.loadFromFile("resources/close_button.png") || !play_button.loadFromFile("resources/play_button.png") 
    || !settings_button.loadFromFile("resources/settings_button.png") || !info_button.loadFromFile("resources/info_button.png")
    || !back_button.loadFromFile("resources/back_button.png") || !background1.loadFromFile("resources/background1.png")
    || !easy_button.loadFromFile("resources/easy_difficulty_button.png") || !hard_button.loadFromFile("resources/hard_difficulty_button.png"))
    {
        return 0;
    }

    Sprite closebutton(close_button), playbutton(play_button), settingsbutton(settings_button), infobutton(info_button), bg1(background1)
    , backbutton(back_button), easybutton(easy_button), hardbutton(hard_button);

    // Start menu
    closebutton.setScale(0.15, 0.15);
    closebutton.setPosition(Vector2f(100, 50));
    playbutton.setScale(0.15, 0.15);
    playbutton.setPosition(Vector2f(800, 500));
    settingsbutton.setScale(0.15, 0.15);
    settingsbutton.setPosition(Vector2f(100, 830));
    infobutton.setScale(0.15, 0.15);
    infobutton.setPosition(Vector2f(1520, 830));

    // Select difficulty menu
    backbutton.setScale(0.15, 0.15);
    backbutton.setPosition(Vector2f(100, 50));
    easybutton.setScale(0.2, 0.2);
    easybutton.setPosition(Vector2f(400, 500));
    hardbutton.setScale(0.2, 0.2);
    hardbutton.setPosition(Vector2f(1000, 500));

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
                    float closestDistance = 50;

                    if (menu == true)
                    {    
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
                            // Settings menu
                        }
                        if (calculateDistance(mousePosition, infobutton.getPosition()) < closestDistance)
                        {
                            // Info menu
                        }
                    }
                    else if (menu != true)
                    {
                        if (calculateDistance(mousePosition, backbutton.getPosition()) < closestDistance)
                        {
                            menu = true;
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
        else if (menu != true)
        {
            window.draw(backbutton);
            window.draw(easybutton);
            window.draw(hardbutton);
        }

        window.display();
    }
    
    return 0;
}
