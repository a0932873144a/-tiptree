//
// Created by 翁廷豪 on 2024/3/6.
//
#include "Character.hpp"
#include "Util/Image.hpp"


Character::Character(const std::string& ImagePath) {
    SetImage(ImagePath);

    ResetPosition();
}

void Character::SetImage(const std::string& ImagePath) {
    m_ImagePath = ImagePath;

    m_Drawable = std::make_shared<Util::Image>(m_ImagePath);
}
