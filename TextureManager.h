#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

//Using makes it more specific
using std::unordered_map;
using std::string;


class TextureManager
{

	//This is causing errors
	static unordered_map<string, sf::Texture> textures;

	static void LoadTexture(string filename);

public:

	static sf::Texture& GetTexture(string texturename);

	static void Clear();
};