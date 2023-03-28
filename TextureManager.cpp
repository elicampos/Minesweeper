#pragma once
#include "TextureManager.h"

//ASK FOX WHY I DIDNT WORK WHEN I DIDNT MAKE A CPP FILE


//Redeclare var
unordered_map<string, sf::Texture> TextureManager::textures;

void TextureManager::LoadTexture(string filename)
{
	string path = "images/";
	path += filename + ".png";

	textures[filename].loadFromFile(path);
}

sf::Texture& TextureManager::GetTexture(string textureName)
{
	//If texture doesn't exist load it
	if (textures.find(textureName) == textures.end())
	{
		LoadTexture(textureName);
	}
	return textures[textureName];
}

void TextureManager::Clear()
{
	textures.clear();
}