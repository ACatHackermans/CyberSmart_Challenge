#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>

using namespace sf;

float calculateDistance (const Vector2f& point1, const Vector2f& point2)
{
    float distanceX = point2.x - point1.x + 100;
    float distanceY = point2.y - point1.y + 100;
    return sqrt(distanceX * distanceX + distanceY * distanceY);
}

int main()
{
    Music music1;
    RenderWindow window(VideoMode(1920, 1080), "CyberSmart Challenge", Style::Default);
    bool startMenu = true, playMenu = false, settingsMenu = false, infoMenu = false;
    bool easy = false, hard = false;

    Texture close_button, play_button, settings_button, info_button, back_button, background1, easy_button, hard_button;
    if (!close_button.loadFromFile("resources/close_button.png") || !play_button.loadFromFile("resources/play_button.png") 
    || !settings_button.loadFromFile("resources/settings_button.png") || !info_button.loadFromFile("resources/info_button.png")
    || !back_button.loadFromFile("resources/back_button.png") || !background1.loadFromFile("resources/background1.png")
    || !easy_button.loadFromFile("resources/easy_difficulty_button.png") || !hard_button.loadFromFile("resources/hard_difficulty_button.png"))
    {
        return 0;
    }

    Sprite closebutton(close_button), playbutton(play_button), settingsbutton(settings_button), infobutton(info_button), bg1(background1), 
    backbutton(back_button), easybutton(easy_button), hardbutton(hard_button);

    // Start startMenu
    closebutton.setScale(0.15, 0.15);
    closebutton.setPosition(Vector2f(100, 50));
    playbutton.setScale(0.15, 0.15);
    playbutton.setPosition(Vector2f(800, 500));
    settingsbutton.setScale(0.15, 0.15);
    settingsbutton.setPosition(Vector2f(100, 830));
    infobutton.setScale(0.15, 0.15);
    infobutton.setPosition(Vector2f(1520, 830));

    // Select difficulty startMenu
    backbutton.setScale(0.15, 0.15);
    backbutton.setPosition(Vector2f(100, 50));
    easybutton.setScale(0.2, 0.2);
    easybutton.setPosition(Vector2f(400, 500));
    hardbutton.setScale(0.2, 0.2);
    hardbutton.setPosition(Vector2f(1000, 500));

    if (!music1.openFromFile("resources/music1.wav"))
        {
            return 0;
        }

    music1.play();
    music1.setLoop(true);    

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
                else if (event.key.code == Keyboard::M)
                {  
                    music1.setVolume(0);
                }
                else if (event.key.code == Keyboard::N)
                {  
                    music1.setVolume(100);
                }
                break;   

            case Event::MouseButtonPressed:
                if (event.mouseButton.button == Mouse::Left)
                {
                    float closestDistance = 100;

                    if (startMenu == true)
                    {    
                        if (calculateDistance(mousePosition, closebutton.getPosition()) < closestDistance)
                        {
                            return 0;
                        }
                        if (calculateDistance(mousePosition, playbutton.getPosition()) < closestDistance)
                        {
                            startMenu = false;
                            playMenu = true;
                        }
                        if (calculateDistance(mousePosition, settingsbutton.getPosition()) < closestDistance)
                        {
                            startMenu = false;
                            settingsMenu = true;
                        }
                        if (calculateDistance(mousePosition, infobutton.getPosition()) < closestDistance)
                        {
                            startMenu = false;
                            infoMenu = true;
                        }
                    }
                    else if (startMenu != true)
                    {
                        if (calculateDistance(mousePosition, backbutton.getPosition()) < closestDistance)
                        {
                            startMenu = true;
                            playMenu = false;
                            settingsMenu = false;
                            infoMenu = false;
                        }
                    }
                }
                    break;         
            }
        }

        window.clear();

        window.draw(bg1);

        if (startMenu)
        {          
            window.draw(closebutton);
            window.draw(playbutton);
            window.draw(settingsbutton);
            window.draw(infobutton);
        }
        else if (playMenu)
        {
            window.draw(backbutton);
            window.draw(easybutton);
            window.draw(hardbutton);
        }
        else if (settingsMenu)
        {
            window.draw(backbutton);
        }
        else if (infoMenu)
        {
            window.draw(backbutton);
        }
        
        window.display();
    }

    return 0;
}
