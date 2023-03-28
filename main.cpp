#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <iostream>
#include <random>
#include <string>
#include <sstream>
#include <fstream>
#include "TextureManager.h"
#include "Tile.h"
#include "Face.h"
#include <random>
#include "Random.h"
#include <vector>


using namespace std;
//Use maps for images and buttons loading to prevent reloading objects
//Make Radnom Generator 
void TileNumberToSprite(Tile &Tile2 , sf::RenderWindow& window)
{
    //Number_#
    sf::Sprite number1(TextureManager::GetTexture("number_1"));
    sf::Sprite number2(TextureManager::GetTexture("number_2"));
    sf::Sprite number3(TextureManager::GetTexture("number_3"));
    sf::Sprite number4(TextureManager::GetTexture("number_4"));
    sf::Sprite number5(TextureManager::GetTexture("number_5"));
    sf::Sprite number6(TextureManager::GetTexture("number_6"));
    sf::Sprite number7(TextureManager::GetTexture("number_7"));
    sf::Sprite number8(TextureManager::GetTexture("number_8"));

    //Revealed tile
    sf::Sprite revealedTile(TextureManager::GetTexture("tile_revealed"));

    // If Number = 0
    if (Tile2.number == 0)
    {
        Tile2.Sprite = revealedTile;
    }


    // If Number = 1
    if (Tile2.number == 1)
    {
        Tile2.Sprite = number1;
    }



    // If Number = 1
    if (Tile2.number == 1)
    {
        Tile2.Sprite = number1;
    }
    // If Number = 2
    if (Tile2.number == 2)
    {
        Tile2.Sprite = number2;
    }


    // If Number = 3
    if (Tile2.number == 3)
    {
        Tile2.Sprite = number3;
    }



    // If Number = 4

    if (Tile2.number == 4)
    {
        Tile2.Sprite = number4;
    }


    // If Number = 5
    if (Tile2.number == 5)
    {
        Tile2.Sprite = number5;
    }


    // If Number = 6
    if (Tile2.number == 6)
    {
        Tile2.Sprite = number6;
    }


    // If Number = 7
    if (Tile2.number == 7)
    {
        Tile2.Sprite = number7;
    }

    // If Number = 8
    if (Tile2.number == 8)
    {
        Tile2.Sprite = number8;
    }

}
void OpenTilesUp(Tile &ZeroTile , sf::RenderWindow& window)
{
    //Revealed tile
    sf::Sprite revealedTile(TextureManager::GetTexture("tile_revealed"));


    int temp = 0;
    //Not a mine 
    //NOTE I KEPT GETTING STACK OVERFLOW BECAUSE I WAS REDOING THE ONES ALREADY PRESSED!
    if (&ZeroTile != nullptr)
    {
        if (ZeroTile.bottom != nullptr)
        {
            if (ZeroTile.bottom->flagged == false && ZeroTile.bottom->pressed == false)
            {
                //Check for value
                if ((ZeroTile.bottom->number) == 0)
                {
                    //Display it
                    sf::Vector2f currentposition = ZeroTile.bottom->Sprite.getPosition();
                    ZeroTile.bottom->pressed = true;
                    TileNumberToSprite(*ZeroTile.bottom, window);
                    ZeroTile.bottom->Sprite.setPosition(currentposition);
                    window.draw(ZeroTile.bottom->Sprite);

                    
                    //Recurse
                    OpenTilesUp(*(ZeroTile.bottom), window);

                    //Remove this from being an option
                    ZeroTile.bottom = nullptr;

                }
            }

        }

        if (ZeroTile.bottomleft != nullptr)
        {
            if (ZeroTile.bottomleft->flagged == false && ZeroTile.bottomleft->pressed == false)
            {
                //Check for value
                if ((ZeroTile.bottomleft->number) == 0)
                {
                    //Display it
                    sf::Vector2f currentposition = ZeroTile.bottomleft->Sprite.getPosition();
                    ZeroTile.bottomleft->pressed = true;
                    TileNumberToSprite(*ZeroTile.bottomleft, window);
                    ZeroTile.bottomleft->Sprite.setPosition(currentposition);
                    window.draw(ZeroTile.bottomleft->Sprite);
                    

                    //Recurse
                    OpenTilesUp(*(ZeroTile.bottomleft), window);

                    //Remove this from being an option
                    ZeroTile.bottomleft = nullptr;
                }
            }

        }
        if (ZeroTile.bottomright != nullptr)
        {
            if (ZeroTile.bottomright->flagged == false && ZeroTile.bottomright->pressed == false)
            {
                //Check for value
                if ((ZeroTile.bottomright->number) == 0)
                {
                    //Display it
                    sf::Vector2f currentposition = ZeroTile.bottomright->Sprite.getPosition();
                    ZeroTile.bottomright->pressed = true;
                    TileNumberToSprite(*ZeroTile.bottomright, window);
                    ZeroTile.bottomright->Sprite.setPosition(currentposition);
                    window.draw(ZeroTile.bottomright->Sprite);
                    
                    //Recurse
                    OpenTilesUp(*(ZeroTile.bottomright), window);

                    //Remove this from being an option
                    ZeroTile.right = nullptr;
                }
            }

        }
        if (ZeroTile.top != nullptr)
        {
            if (ZeroTile.top->flagged == false && ZeroTile.top->pressed == false)
            {
                //Check for value
                if ((ZeroTile.top->number) == 0)
                {
                    //Display it
                    sf::Vector2f currentposition = ZeroTile.top->Sprite.getPosition();
                    ZeroTile.top->pressed = true;
                    TileNumberToSprite(*ZeroTile.top, window);
                    ZeroTile.top->Sprite.setPosition(currentposition);
                    window.draw(ZeroTile.top->Sprite);
                    

                    //Recurse
                    OpenTilesUp(*(ZeroTile.top), window);

                    //Remove this from being an option
                    ZeroTile.top = nullptr;
                }
            }

        }
        if (ZeroTile.topright != nullptr)
        {
            if (ZeroTile.topright->flagged == false && ZeroTile.topright->pressed == false)
            {
                //Check for value
                if ((ZeroTile.topright->number) == 0)
                {
                    //Display it
                    sf::Vector2f currentposition = ZeroTile.topright->Sprite.getPosition();
                    ZeroTile.topright->pressed = true;
                    TileNumberToSprite(*ZeroTile.topright, window);
                    ZeroTile.topright->Sprite.setPosition(currentposition);
                    window.draw(ZeroTile.topright->Sprite);
                    
                    //Recurse
                    OpenTilesUp(*(ZeroTile.topright), window);

                    //Remove this from being an option
                    ZeroTile.topright = nullptr;

                }
            }

        }
        if (ZeroTile.topleft != nullptr)
        {
            if (ZeroTile.topleft->flagged == false && ZeroTile.topleft->pressed == false)
            {
                //Check for value
                if ((ZeroTile.topleft->number) == 0)
                {
                    //Display it
                    sf::Vector2f currentposition = ZeroTile.topleft->Sprite.getPosition();
                    ZeroTile.topleft->pressed = true;
                    TileNumberToSprite(*ZeroTile.topleft, window);
                    ZeroTile.topleft->Sprite.setPosition(currentposition);
                    window.draw(ZeroTile.topleft->Sprite);
                    

                    //Recurse
                    OpenTilesUp(*(ZeroTile.topleft), window);

                    //Remove this from being an option
                    ZeroTile.topleft = nullptr;
                }
            }

        }
        if (ZeroTile.left != nullptr)
        {
            if (ZeroTile.left->flagged == false && ZeroTile.left->pressed == false)
            {
                //Check for value
                if ((ZeroTile.left->number) == 0)
                {
                    //Display it
                    sf::Vector2f currentposition = ZeroTile.left->Sprite.getPosition();
                    ZeroTile.left->pressed = true;
                    TileNumberToSprite(*ZeroTile.left, window);
                    ZeroTile.left->Sprite.setPosition(currentposition);
                    window.draw(ZeroTile.left->Sprite);
                  
                    //Recurse
                    OpenTilesUp(*(ZeroTile.left), window);

                    //Remove this from being an option
                    ZeroTile.left = nullptr;

                }
            }


        }
        if (ZeroTile.right != nullptr)
        {
            if (ZeroTile.right->flagged == false && ZeroTile.right->pressed == false)
            {
                //Check for value
                if ((ZeroTile.right->number) == 0)
                {
                    //Display it
                    sf::Vector2f currentposition = ZeroTile.right->Sprite.getPosition();
                    ZeroTile.right->pressed = true;
                    TileNumberToSprite(*ZeroTile.right, window);
                    ZeroTile.right->Sprite.setPosition(currentposition);
                    window.draw(ZeroTile.right->Sprite);
                    
                    //Recurse
                    OpenTilesUp(*(ZeroTile.right), window);

                    //Remove this from being an option
                    ZeroTile.right = nullptr;

                }
            }
            

        }
        //Once FInished remove pointers as it will never be used again

    } 
}



void SetNumberOnTiles (vector<Tile> &Tiles , int columnsize)
{
    //Assigning tiles numbers after mines    
    int countfornumber = 0;
    for (float i = 0; i < Tiles.size(); i++)
    {
        //Reset Count for each tile
        countfornumber = 0;
        //If tile has any mines adjacnet to it count them and assign number value to it for all tiles

        //Top Left
        int topleft = i - ((columnsize / 32) + 1);
        if (topleft >= 0 && topleft < Tiles.size())
        {
            if (Tiles[topleft].contains_mine == true)
            {
                countfornumber++;
            }
            else if(Tiles[topleft].contains_mine == false)
            {
                //Grab memory address of tiles and place it in tile object if not a mine
                Tiles[i].topleft = &(Tiles[topleft]) ;
            }
        }
        //Top 
        int top = i - (columnsize / 32);
        if (top >= 0 && top < Tiles.size())
        {
            if (Tiles[top].contains_mine == true)
            {
                countfornumber++;
            }
            else if (Tiles[top].contains_mine == false)
            {
                //Grab memory address of tiles and place it in tile object
                Tiles[i].top = &(Tiles[top]);
            }
        }
        //Top Right
        int topright = i - ((columnsize / 32) - 1);
        if (topright >= 0 && topright < Tiles.size())
        {
            if (Tiles[topright].contains_mine == true)
            {
                countfornumber++;
            }
            else if (Tiles[topright].contains_mine == false)
            {
                //Grab memory address of tiles and place it in tile object
                Tiles[i].topright = &(Tiles[topright]);
            }
        }
        //Left
        int left = i - 1;
        if (left >= 0 && left < Tiles.size())
        {
            if (Tiles[left].contains_mine == true)
            {
                countfornumber++;
            }
            else if (Tiles[left].contains_mine == false)
            {
                //Grab memory address of tiles and place it in tile object
                Tiles[i].left = &(Tiles[left]);
            }
        }
        //Right
        int right = i + 1;
        if (right >= 0 && right < Tiles.size())
        {
            if (Tiles[right].contains_mine == true)
            {
                countfornumber++;
            }
            else if (Tiles[right].contains_mine == false)
            {
                //Grab memory address of tiles and place it in tile object
                Tiles[i].right = &(Tiles[right]);
            }
        }
        //Bottom Left
        int bottomleft = i + ((columnsize / 32) - 1);
        if (bottomleft >= 0 && bottomleft < Tiles.size())
        {
            if (Tiles[bottomleft].contains_mine == true)
            {
                countfornumber++;
            }
            else if (Tiles[bottomleft].contains_mine == false)
            {
                //Grab memory address of tiles and place it in tile object
                Tiles[i].bottomleft = &(Tiles[bottomleft]);
            }
        }
        //Bottom
        int bottom = i + (columnsize / 32);
        if (bottom >= 0 && bottom < Tiles.size())
        {
            if (Tiles[bottom].contains_mine == true)
            {
                countfornumber++;
            }
            else if (Tiles[bottom].contains_mine == false)
            {
                //Grab memory address of tiles and place it in tile object
                Tiles[i].bottom = &(Tiles[bottom]);
            }
        }
        //Bottom Right
        int bottomright = i + ((columnsize / 32) + 1);
        if (bottomright >= 0 && bottomright < Tiles.size())
        {
            if (Tiles[bottomright].contains_mine == true)
            {
                countfornumber++;
            }
            else if (Tiles[bottomright].contains_mine == false)
            {
                //Grab memory address of tiles and place it in tile object
                Tiles[i].bottomright = &(Tiles[bottomright]);
            }

        }

        Tiles[i].number = countfornumber;
    }
}
vector<Tile> SetTestFiles(string filenumber, sf::RenderWindow& window, sf::Sprite test1layout, sf::Sprite test2layout, sf::Sprite test3layout, vector<Tile> Tiles, float rowsize, float columnsize, sf::Sprite hiddenTile, sf::Sprite mineSprite, bool &gameon,bool &debugon, int &numofmines)
{
    gameon = true;

    //Create a vector of all numbers for the file and of all the lines(since they will represent each other perfectly)
    ifstream TextFile;
    TextFile.open("boards/testboard" + filenumber + ".brd"); //Read Mode

    if (TextFile.is_open())
    {

        //Creating Singleline holder
        string singleLine;


        //Convert string to stream
        istringstream stream(singleLine);


        //Vector to hold data             
        vector<char> TestFiledata;
        TestFiledata.clear();
        string token;
        char c;

        //USE .GOOD FOR END OF DOUMCENT WITHOUT SKIPPING OVER FIRST ONE
        while ((TextFile.good() == true))
        {
            //Read char by char
            TextFile.get(c);
            if (c == '1' || c == '0')
            {
                TestFiledata.push_back(c);
            }
        }
        //Close File
        TextFile.close();

        //Write Operation to change tile size and clean old one
        Tiles.clear();
        int temp = 0;
        for (float i = 0; i < (rowsize / 32); i++)
        {
            temp = i * 32;
            for (float j = 0; j < (columnsize / 32); j++)
            {
                hiddenTile.setPosition(sf::Vector2f((32 * j), (temp)));
                window.draw(hiddenTile);

                Tile curtile;
                curtile.Sprite = hiddenTile;
                //Storing Tiles in Vector and in order from left to right and then down
                Tiles.push_back(curtile);

            }
        }
        int numofminescall = 0;

        //Assinging Tiles Mines(IF 1 MINE IF NONE LEAVE TILES AS IS)
        for (unsigned int i = 0; i < TestFiledata.size(); i++)
        {
            //ERROR: DATA FILES SOMEHOW HAVE MORE DATA THEN TILES
            if (TestFiledata[i] == '1')
            {
                numofminescall++;
                Tiles[i].contains_mine = true;

                //To keep debug button on
                if (debugon == true)
                {
                    Tiles[i].debugshowcase = true;
                    sf::Vector2f currentposition = Tiles[i].Sprite.getPosition();
                    Tiles[i].Sprite = mineSprite;
                    Tiles[i].Sprite.setPosition(currentposition);
                    window.draw(Tiles[i].Sprite);
                }
                else if (debugon == false)
                {
                    Tiles[i].debugshowcase = false;
                    sf::Vector2f currentposition = Tiles[i].Sprite.getPosition();
                    Tiles[i].Sprite = hiddenTile;
                    Tiles[i].Sprite.setPosition(currentposition);
                    window.draw(Tiles[i].Sprite);

                }
            }
            

        }
        numofmines = numofminescall;
        
        //Set Tiles with value
        SetNumberOnTiles(Tiles , columnsize);


    }
    return Tiles;
}
vector<Tile> ReloadTexture(float columnsize, float rowsize, float minecount, sf::RenderWindow& window, bool &debugon, vector<Tile> Tiles, int &callnumofmine)
{

    //------------------Load Textures and Create sprites------------------

    //Mine
    sf::Sprite mineSprite(TextureManager::GetTexture("mine"));

    //Hidden tile
    sf::Sprite hiddenTile(TextureManager::GetTexture("tile_hidden"));

    //Revealed tile
    sf::Sprite revealedTile(TextureManager::GetTexture("tile_revealed"));

    //Number_#
    sf::Sprite number1(TextureManager::GetTexture("number_1"));
    sf::Sprite number2(TextureManager::GetTexture("number_2"));
    sf::Sprite number3(TextureManager::GetTexture("number_3"));
    sf::Sprite number4(TextureManager::GetTexture("number_4"));
    sf::Sprite number5(TextureManager::GetTexture("number_5"));
    sf::Sprite number6(TextureManager::GetTexture("number_6"));
    sf::Sprite number7(TextureManager::GetTexture("number_7"));
    sf::Sprite number8(TextureManager::GetTexture("number_8"));

    //Flag
    sf::Sprite flag(TextureManager::GetTexture("flag"));

    //Happy Faces
    sf::Sprite happyface(TextureManager::GetTexture("face_happy"));
    sf::Sprite winface(TextureManager::GetTexture("face_win"));
    sf::Sprite loseface(TextureManager::GetTexture("face_lose"));

    //Digits
    sf::Sprite digitcounter(TextureManager::GetTexture("digits"));

    //Debug tools
    sf::Sprite minevisibility(TextureManager::GetTexture("debug"));

    sf::Sprite test1layout(TextureManager::GetTexture("test_1"));
    sf::Sprite test2layout(TextureManager::GetTexture("test_2"));
    sf::Sprite test3layout(TextureManager::GetTexture("test_3"));



    //------------------Draw Game------------------

    //Happy Face
    happyface.setPosition(sf::Vector2f((columnsize - 64) / 2, (rowsize)));
    window.draw(happyface);

    //Note: Move up by 2 times because it pulls it from the right (64*2)

    //Debug Tools
    minevisibility.setPosition(sf::Vector2f((columnsize + 192) / 2, (rowsize)));
    window.draw(minevisibility);

    //Tests Tools
    test1layout.setPosition(sf::Vector2f((columnsize + 320) / 2, (rowsize)));
    window.draw(test1layout);
    test2layout.setPosition(sf::Vector2f((columnsize + 448) / 2, (rowsize)));
    window.draw(test2layout);
    test3layout.setPosition(sf::Vector2f((columnsize + 576) / 2, (rowsize)));
    window.draw(test3layout);



    //We will create a similar area but of mouse space that when clicked draws on top of it

    //Vector To Store Tiles and states
    Tiles.clear();


    //Blocks(WORKING)    
    int temp = 0;
    for (float i = 0; i < (rowsize / 32); i++)
    {
        temp = i * 32;
        for (float j = 0; j < (columnsize / 32); j++)
        {
            hiddenTile.setPosition(sf::Vector2f((32 * j), (temp)));
            window.draw(hiddenTile);

            Tile curtile;
            curtile.Sprite = hiddenTile;
            curtile.contains_mine = false;
            //Storing Tiles in Vector and in order from left to right and then down
            Tiles.push_back(curtile);

        }
    }
    //Assinging Tiles Mines(Not working kinda)
    int numofmines = 0;
    int randomtile = 0;
    for (float i = 0; i < minecount; i++)
    {
        //SUBTRACT ONE FROM RANGE AS INDEX IS ALWAYS 1 LESS
        //RANDOM TILE IS WORKING EACH TIME IT'S CALLED
        randomtile = Random::Int(0, Tiles.size() - 1);
        if (Tiles[randomtile].contains_mine == false)
        {
            Tiles[randomtile].contains_mine = true;
        }

        //If already has a mine go back one index and retry

        if (Tiles[randomtile].contains_mine == true)
        {
            numofmines++;
            //To keep debug button on
            if (debugon == true)
            {
                Tiles[i].debugshowcase = true;
                sf::Vector2f currentposition = Tiles[randomtile].Sprite.getPosition();
                Tiles[randomtile].Sprite = mineSprite;
                Tiles[randomtile].Sprite.setPosition(currentposition);
                window.draw(Tiles[randomtile].Sprite);

            }
            else if (debugon == false)
            {
                Tiles[i].debugshowcase = false;
                sf::Vector2f currentposition = Tiles[randomtile].Sprite.getPosition();
                Tiles[randomtile].Sprite = hiddenTile;
                Tiles[randomtile].Sprite.setPosition(currentposition);
                window.draw(Tiles[randomtile].Sprite);


            }
            
        }
        else //CALL ITSELF AGAIN if same number repeats
        {
            i = i - 1;
        }
        
    }
    numofmines = callnumofmine;

    //Set Tiles with value
    SetNumberOnTiles(Tiles , columnsize);




    return Tiles;

    //Digits(At Zero for now)

    //For a different number add+21 to third one or 21*2 not sure yet
    /*
    digitcounter.setPosition(32, rowsize - 64);
    digitcounter.setTextureRect(sf::IntRect(0, 0, 21, 32));
    window.draw(digitcounter);
    window.display();
    */

}


int main()
{
    bool gameon = true;
    bool debugon = false;
    //------------------Load Config file to create window size------------------
    ifstream TextFile;
    TextFile.open("boards/config.cfg"); //Read Mode

    float rowsize = 0;
    float columnsize = 0;
    if (TextFile.is_open())
    {
        //Creating Singleline holder
        string singleLine;


        //Convert string to stream
        istringstream stream(singleLine);


        //------------------Grabbing all info from config files------------------

        //Columns(Length)
        getline(TextFile, singleLine);
        columnsize = (stoi(singleLine) * 32);

        //Rows(Width)
        getline(TextFile, singleLine);
        rowsize = stoi(singleLine) * 32;

        //Number of mines
        getline(TextFile, singleLine);
        float minecount = stoi(singleLine);

        //Close File
        TextFile.close();


        sf::RenderWindow window(sf::VideoMode(columnsize, rowsize + 100), "Eli's Minesweeper");
        sf::Event event;

        //------------------Load Textures and Create sprites------------------

        //Mine
        sf::Sprite mineSprite(TextureManager::GetTexture("mine"));

        //Hidden tile
        sf::Sprite hiddenTile(TextureManager::GetTexture("tile_hidden"));

        //Revealed tile
        sf::Sprite revealedTile(TextureManager::GetTexture("tile_revealed"));

        //Number_#
        sf::Sprite number1(TextureManager::GetTexture("number_1"));
        sf::Sprite number2(TextureManager::GetTexture("number_2"));
        sf::Sprite number3(TextureManager::GetTexture("number_3"));
        sf::Sprite number4(TextureManager::GetTexture("number_4"));
        sf::Sprite number5(TextureManager::GetTexture("number_5"));
        sf::Sprite number6(TextureManager::GetTexture("number_6"));
        sf::Sprite number7(TextureManager::GetTexture("number_7"));
        sf::Sprite number8(TextureManager::GetTexture("number_8"));

        //Flag
        sf::Sprite flag(TextureManager::GetTexture("flag"));

        //Happy Faces
        sf::Sprite happyface(TextureManager::GetTexture("face_happy"));
        sf::Sprite winface(TextureManager::GetTexture("face_win"));
        sf::Sprite loseface(TextureManager::GetTexture("face_lose"));

        //Digits
        sf::Sprite digitcounter(TextureManager::GetTexture("digits"));

        //Debug tools
        sf::Sprite minevisibility(TextureManager::GetTexture("debug"));

        sf::Sprite test1layout(TextureManager::GetTexture("test_1"));
        sf::Sprite test2layout(TextureManager::GetTexture("test_2"));
        sf::Sprite test3layout(TextureManager::GetTexture("test_3"));



        //------------------Draw Game------------------

        //Happy Face
        happyface.setPosition(sf::Vector2f((columnsize - 64) / 2, (rowsize)));
        window.draw(happyface);

        //Note: Move up by 2 times because it pulls it from the right (64*2)

        //Debug Tools
        minevisibility.setPosition(sf::Vector2f((columnsize + 192) / 2, (rowsize)));
        window.draw(minevisibility);

        //Tests Tools
        test1layout.setPosition(sf::Vector2f((columnsize + 320) / 2, (rowsize)));
        window.draw(test1layout);
        test2layout.setPosition(sf::Vector2f((columnsize + 448) / 2, (rowsize)));
        window.draw(test2layout);
        test3layout.setPosition(sf::Vector2f((columnsize + 576) / 2, (rowsize)));
        window.draw(test3layout);





        //We will create a similar area but of mouse space that when clicked draws on top of it

        //Vector To Store Tiles and states
        vector <Tile> Tiles;
        //Blocks      
        int temp = 0;
        for (float i = 0; i < (rowsize / 32); i++)
        {
            temp = i * 32;
            for (float j = 0; j < (columnsize / 32); j++)
            {
                hiddenTile.setPosition(sf::Vector2f((32 * j), (temp)));
                window.draw(hiddenTile);

                Tile curtile;
                curtile.Sprite = hiddenTile;
                //Storing Tiles in Vector and in order from left to right and then down
                Tiles.push_back(curtile);

            }
        }
        //Assinging Tiles Mines

        int randomtile = 0;
        int numofminesmain = 0;
        for (float i = 0; i < minecount; i++)
        {
            //SUBTRACT ONE FROM RANGE AS INDEX IS ALWAYS 1 LESS
            randomtile = Random::Int(0, Tiles.size() - 1);

            if (Tiles[randomtile].contains_mine == false)
            {
                Tiles[randomtile].contains_mine = true;
                //To keep debug button on
                if (debugon == true)
                {
                    Tiles[i].debugshowcase = true;
                    sf::Vector2f currentposition = Tiles[randomtile].Sprite.getPosition();
                    Tiles[randomtile].Sprite = mineSprite;
                    Tiles[randomtile].Sprite.setPosition(currentposition);
                    window.draw(Tiles[randomtile].Sprite);
                }
                else if (debugon == false)
                {
                    Tiles[i].debugshowcase = false;
                    sf::Vector2f currentposition = Tiles[randomtile].Sprite.getPosition();
                    Tiles[randomtile].Sprite = hiddenTile;
                    Tiles[randomtile].Sprite.setPosition(currentposition);
                    window.draw(Tiles[randomtile].Sprite);
                }
                numofminesmain++;
                //TODO:CALL ITSELF AGAIN
            }
            //If already has a mine go back one index and retry
            else if (Tiles[randomtile].contains_mine == true) //CALL ITSELF AGAIN if same number repeats
            {
                i = i - 1;
            }


        }
        //Set Tiles with value
        SetNumberOnTiles(Tiles , columnsize);

        //Digits(At Zero for now)

        //For a different number add+21 to third one or 21*2 not sure yet
        /*
        digitcounter.setPosition(32, rowsize - 64);
        digitcounter.setTextureRect(sf::IntRect(0, 0, 21, 32));
        window.draw(digitcounter);
        window.display();
        */
        while (window.isOpen())
        {

            while (window.pollEvent(event))
            {
                
                //------------------Check for mouse input------------------
                //Checking if Any tile has been revealed
                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) //AND IN VALID AREA)
                {
                    sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    int numofseceltedtiles = 0;
                    for (unsigned int i = 0; i < Tiles.size(); i++)
                    {
                        //Check if I even clicked it
                        sf::FloatRect bounds = Tiles[i].Sprite.getGlobalBounds();
                        sf::Vector2f currentposition = Tiles[i].Sprite.getPosition();

                        if (bounds.contains(mouse) && Tiles[i].contains_mine == false && gameon == true && Tiles[i].pressed == false && Tiles[i].flagged == false) //If Mouse is on Sprite
                        {
                            
                            Tiles[i].pressed = true;

                            // If Number = 0
                            if (Tiles[i].number == 0 && Tiles[i].flagged == false)
                            {
                                Tiles[i].Sprite = revealedTile;
                                Tiles[i].Sprite.setPosition(currentposition);

                                //Use recursive Algo to "press" and reveal all other 0 tiles nearby
                                OpenTilesUp(Tiles[i], window);
                                

                            }

                            TileNumberToSprite(Tiles[i], window);
                            Tiles[i].Sprite.setPosition(currentposition);

    
                            //Print Sprite Result
                            window.draw(Tiles[i].Sprite);
                            
                            //Check win
                            //Check to see if player one game
                            int numofselcectedtiles = 0;
                            for (unsigned int i = 0; i < Tiles.size(); i++)
                            {
                                if (Tiles[i].pressed == true)
                                {
                                    numofselcectedtiles++;
                                }
                            }

                            

                        
                             //Check if I won 
                            if (numofselcectedtiles == Tiles.size() - numofminesmain )
                            {
                                //End game
                                gameon = false;

                                //Draw Smiley Man
                                winface.setPosition(sf::Vector2f((columnsize - 64) / 2, (rowsize)));
                                happyface = winface;
                                window.draw(happyface);

                                //Show Mines with flags
                                for (unsigned int j = 0; j < Tiles.size(); j++)
                                {
                                    if (Tiles[j].contains_mine == true)
                                    {
                                        if (debugon == true)
                                        {
                                            sf::Vector2f currentposition = Tiles[j].Sprite.getPosition();
                                            Tiles[j].Sprite = hiddenTile;
                                            Tiles[j].Sprite.setPosition(currentposition);
                                            window.draw(Tiles[j].Sprite);
                                        }
                                        sf::Vector2f currentposition = Tiles[j].Sprite.getPosition();
                                        Tiles[j].Sprite = flag;
                                        Tiles[j].Sprite.setPosition(currentposition);
                                        window.draw(Tiles[j].Sprite);
                                    }
                                }


                            }
                                
                        }
                        else if (bounds.contains(mouse) && Tiles[i].contains_mine == true && gameon == true & Tiles[i].pressed == false && Tiles[i].flagged == false)
                        {
                            //Reveal All Mines
                            for (unsigned int j = 0; j < Tiles.size(); j++)
                            {
                                //ALL MINES ARE NOW PRESSED
                                Tiles[j].pressed = true;
                                if (Tiles[j].contains_mine == true)
                                {
                                    //Reveal Mines
                                    sf::Vector2f currentposition = Tiles[j].Sprite.getPosition();
                                    Tiles[j].Sprite = mineSprite;
                                    Tiles[j].Sprite.setPosition(currentposition);
                                    window.draw(Tiles[j].Sprite);

                                }
                            }


                            //Reveal Sad Face                          
                            loseface.setPosition(sf::Vector2f((columnsize - 64) / 2, (rowsize)));
                            happyface = loseface;
                            window.draw(happyface);
                            //Stop Everything
                            gameon = false;

                        }

                    }


                    //Debug Button for only when alive

                    //Creating Bounds and checking mouse position for button
                    sf::Vector2f newmouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    sf::FloatRect newbounds = minevisibility.getGlobalBounds();

                    //Because of some interesting proporties when clicked for the first time make sure

                    //If Found
                    if (newbounds.contains(newmouse) && gameon == true)
                    {
                        debugon = !debugon;
                        //Reveal All Mines if debugshow case off and vice versa

                        for (unsigned int j = 0; j < Tiles.size(); j++)
                        {

                            if (debugon == true && Tiles[j].contains_mine == true)
                            {

                                Tiles[j].debugshowcase = true;
                                sf::Vector2f currentposition = Tiles[j].Sprite.getPosition();
                                Tiles[j].debugshowcase = true;
                                Tiles[j].Sprite = mineSprite;
                                Tiles[j].Sprite.setPosition(currentposition);
                                window.draw(Tiles[j].Sprite);

                            }
                            else if (debugon == false && Tiles[j].contains_mine == true)
                            {

                                Tiles[j].debugshowcase = false;
                                sf::Vector2f currentposition = Tiles[j].Sprite.getPosition();
                                Tiles[j].debugshowcase = false;
                                Tiles[j].Sprite = hiddenTile;
                                Tiles[j].Sprite.setPosition(currentposition);
                                window.draw(Tiles[j].Sprite);

                            }


                        }
                    }

                    //Test 1
                    sf::Vector2f newmouse1 = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    sf::FloatRect newbounds1 = test1layout.getGlobalBounds();
                    if (newbounds1.contains(newmouse1))
                    {
                        
                        Tiles = ReloadTexture(columnsize, rowsize, minecount, window, debugon, Tiles, numofminesmain);

                        Tiles = SetTestFiles("1", window, test1layout, test2layout, test3layout, Tiles, rowsize, columnsize, hiddenTile, mineSprite, gameon, debugon, numofminesmain);
                    }

                    //Test 2
                    newmouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    newbounds = test2layout.getGlobalBounds();
                    if (newbounds.contains(newmouse))
                    {
                        Tiles = ReloadTexture(columnsize, rowsize, minecount, window, debugon, Tiles, numofminesmain);


                        Tiles = SetTestFiles("2", window, test1layout, test2layout, test3layout, Tiles, rowsize, columnsize, hiddenTile, mineSprite, gameon, debugon, numofminesmain);
                    }

                    //Test 3
                    newmouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    newbounds = test3layout.getGlobalBounds();
                    if (newbounds.contains(newmouse))
                    {
                        
                        Tiles = ReloadTexture(columnsize, rowsize, minecount, window, debugon, Tiles, numofminesmain);

                        Tiles = SetTestFiles("3", window, test1layout, test2layout, test3layout, Tiles, rowsize, columnsize, hiddenTile, mineSprite, gameon, debugon, numofminesmain);
                    }

                }
                //Check if it was right clicked and overlay flag 
                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) && gameon == true) //AND IN VALID AREA)
                {
                    sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                    for (unsigned int i = 0; i < Tiles.size(); i++)
                    {
                        if (Tiles[i].flagged == false && Tiles[i].pressed == false && gameon == true)
                        {


                            sf::FloatRect bounds = Tiles[i].Sprite.getGlobalBounds();
                            sf::Vector2f currentposition = Tiles[i].Sprite.getPosition();
                            if (bounds.contains(mouse)) //If Mouse is on Sprite
                            {
                                //sf::Sprite revealedTile(TextureManager::GetTexture("tile_revealed"));
                                Tiles[i].flagged = true;
                                Tiles[i].Sprite = flag;
                                Tiles[i].Sprite.setPosition(currentposition);
                                window.draw(Tiles[i].Sprite);
                            }
                        }
                        else if (Tiles[i].flagged == true && Tiles[i].pressed == false && gameon == true)
                        {



                            sf::FloatRect bounds = Tiles[i].Sprite.getGlobalBounds();
                            sf::Vector2f currentposition = Tiles[i].Sprite.getPosition();
                            if (bounds.contains(mouse)) //If Mouse is on Sprite
                            {
                                //sf::Sprite revealedTile(TextureManager::GetTexture("tile_revealed"));
                                Tiles[i].flagged = false;
                                Tiles[i].Sprite = hiddenTile;
                                Tiles[i].Sprite.setPosition(currentposition);
                                window.draw(Tiles[i].Sprite);
                            }
                        }
                    }
                }
                


                /*
                cout << "pressed" << endl;
                digitcounter.setPosition(32, rowsize - 64);
                digitcounter.setTextureRect(sf::IntRect(0, 0, 21, 10));
                window.draw(digitcounter);
                window.display();
                */
                //Make sure changes show
                //After his eveyrhting sems to be working

                //-------------RESTART---------------

                //Flipping Face
                sf::Vector2f newmouse5 = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                sf::FloatRect newbounds5 = happyface.getGlobalBounds();

                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && newbounds5.contains(newmouse5))
                {
                    sf::Sprite happyface(TextureManager::GetTexture("face_happy"));
                    window.draw(happyface);
                    //Restart

                    //Check State 
                    Tiles.clear();
                    Tiles = ReloadTexture(columnsize, rowsize, minecount, window, debugon, Tiles, numofminesmain);
                    gameon = true;


                }
                window.display();
            }
        }
    }
    else
    {
        cout << "Cannot Read Config" << endl;
    }
    return 0;
}