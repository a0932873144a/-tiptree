//
// Created by 翁廷豪 on 2024/3/6.
//

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

#include "Util/GameObject.hpp"

class Character : public Util::GameObject {
public:
    explicit Character(const std::string& ImagePath);

    Character(const Character&) = delete;

    Character(Character&&) = delete;

    Character& operator=(const Character&) = delete;

    Character& operator=(Character&&) = delete;

    [[nodiscard]] const std::string& GetImagePath() const { return m_ImagePath; }

    [[nodiscard]] const glm::vec2& GetPosition() const { return m_Transform.translation; }

    [[nodiscard]] bool GetVisibility() const { return m_Visible; }

    void SetImage(const std::string& ImagePath);

    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }

    // Collision detection function
    [[nodiscard]] bool IfCollides(const std::shared_ptr<Character>& other) const {
        float positionX = this->GetPosition()[0];
        float positionY = this->GetPosition()[1];
        float width = this->GetScaledSize()[0];
        float height = this->GetScaledSize()[1];

        float other_positionX = other->GetPosition()[0];
        float other_positionY = other->GetPosition()[1];
        float other_width = other->GetScaledSize()[0];
        float other_height = other->GetScaledSize()[1];

        // Check if the bounding boxes of the characters overlap
        bool collideX = positionX < other_positionX + other_width &&
                        positionX + width > other_positionX;
        bool collideY = positionY < other_positionY + other_height &&
                        positionY + height > other_positionY;

        return collideX && collideY;
    }

private:
    void ResetPosition() { m_Transform.translation = {0, 0}; }

    std::string m_ImagePath;
};


#endif //CHARACTER_HPP

