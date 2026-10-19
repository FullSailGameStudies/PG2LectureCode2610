#include "Textures.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool Textures::LoadSubtextures()
{
	//
	// Part A-1
	//
	std::ifstream inFile("character_robot_sheetHD.csv");
	if (inFile.is_open())
	{
		std::getline(inFile, imageFile_);

		std::string line;
		//loop reading a line from the file
		//	parse the line to get the name,x,y,width,height
		//  create a subtexture object with the data
		//  add the subtexture to the vector field
		char colDelim = '?';
		maxWidth_ = maxHeight_ = 0;
		while (not inFile.eof())
		{
			std::getline(inFile, line);

			//parse the line
			std::stringstream lineStream(line);
			std::string name;
			std::getline(lineStream, name, colDelim);

			int x, y, width, height;
			std::string data;
			std::getline(lineStream, data, colDelim);
			x = std::stoi(data);
			std::getline(lineStream, data, colDelim);
			y = std::stoi(data);
			std::getline(lineStream, data, colDelim);
			width = std::stoi(data);
			std::getline(lineStream, data, colDelim);
			height = std::stoi(data);

			SubTexture sub;
			sub.name = name;
			sub.x = x;
			sub.y = y;
			sub.width = width;
			sub.height = height;

			if (maxWidth_ < width) maxWidth_ = width;
			if (maxHeight_ < height) maxHeight_ = height;

			subTextures_.push_back(sub);

		}
		inFile.close();
		return true;
	}
	else
	{
		std::cout << "Couldn't find the character sheet.\n";
	}
	inFile.close();
	return false;
}

bool Textures::LoadSpritesheet(SDL_Renderer* renderer)
{
	spriteSheet_ = new PG2Texture(renderer);
	return spriteSheet_->LoadFromFile(imageFile_);
}

SDL_Rect Textures::GetTextureSource(int index)
{
	SDL_Rect rect{ 0,0,0,0 };
	if (index >= 0 && index < subTextures_.size())
	{
		rect.x = subTextures_[index].x;
		rect.y = subTextures_[index].y;
		rect.w = subTextures_[index].width;
		rect.h = subTextures_[index].height;
	}
	return rect;
}

void Textures::Render(SDL_Rect* texSrc, SDL_Rect* dest, SDL_RendererFlip flip)
{
	spriteSheet_->Render(texSrc, dest, 0, 0, flip);
}
