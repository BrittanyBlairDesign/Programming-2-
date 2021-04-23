/*
	Player.cpp
	Brittany Blair
*/
#include "Player.h"
#include <iostream>
void Player::PrintName()
{
	std::cout << m_name << ' ' << m_number;
}

bool Player::HorizontalMove(int W, int H)
{
	char current;

	current = m_pBoard->GetHorizontalTile(W,H);

	if (current == ' ')
	{
		m_pBoard->ChangeHorizontalTile(W, H, m_horizontal);
		return true;
	}
	else
	{
		std::cout << "Oops! That spot has been taken. Please try again." << std::endl;
		return false;
	}
}

bool Player::VerticalMove(int W, int H)
{
	char current;

	current = m_pBoard->GetVerticalTile(W, H);

	if (current == ' ')
	{
		m_pBoard->ChangeVerticalTile(W, H, m_vertical);
		return true;
	}
	else
	{
		std::cout << "Oops! That spot has been taken. Please try again." << std::endl;
		return false;
	}
}