#pragma once

class Tile
{
public:
	//Variables
	bool pressed = false;
	bool flagged = false;
	bool hidden = true;
	bool revealed = false;
	bool contains_mine = false;
	sf::Sprite Sprite;
	bool debugshowcase = false;
	int number = 0;
	Tile* bottomleft = nullptr;
	Tile *bottomright = nullptr;
	Tile *bottom = nullptr;
	Tile *top = nullptr;
	Tile *topleft = nullptr;
	Tile *topright = nullptr;
	Tile *left = nullptr;
	Tile *right = nullptr;
};
