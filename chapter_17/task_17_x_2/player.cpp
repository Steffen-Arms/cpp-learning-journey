#include "player.h"
#include "inputValidation.h"
#include "random.h"
#include "shopItems.h"
#include <array>
#include <iostream>
#include <string>

Player::Player(std::string_view playerName)
{
    m_name = playerName;
    m_gold = Random::get(s_minStartGold, s_maxStartGold);
}
