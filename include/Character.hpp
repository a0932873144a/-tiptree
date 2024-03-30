//
// Created by 翁廷豪 on 2024/3/6.
//

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

#include "Util/GameObject.hpp"
#include "Util/Input.hpp"

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
        // Check if the bounding boxes of the characters overlap
        bool collideX = this->GetPosition().x < other->GetPosition().x + other->GetScaledSize().x &&
                        this->GetPosition().x + this->GetScaledSize().x > other->GetPosition().x;
        bool collideY = this->GetPosition().y < other->GetPosition().y + other->GetScaledSize().y &&
                        this->GetPosition().y + this->GetScaledSize().y > other->GetPosition().y;

        return collideX && collideY;
    }

    //detect where to move
    [[nodiscard]] char MoveDirection(const std::shared_ptr<Character>& other) const {
        if (IfCollides(other) && Util::Input::IsKeyPressed(Util::Keycode::A)) {
            return 'A';
        }
        else if (IfCollides(other) && Util::Input::IsKeyPressed(Util::Keycode::S)) {
            return 'S';
        }
        else if (IfCollides(other) && Util::Input::IsKeyPressed(Util::Keycode::D)) {
            return 'D';
        }
        else if (IfCollides(other) && Util::Input::IsKeyPressed(Util::Keycode::W)) {
            return 'W';
        }
        else {
            return 0;
        }
    }

    enum class Tag {
        Player,
        Rock,
        Enemy,
        Boundary,
        Boss,
        SpikeTrap,
        Key,
        Chest,
    };

    void SetLastTouched(Tag tag) {
        m_TouchedTag = tag;
    }

    Tag GetLastTouched() {
        return m_TouchedTag;
    }

    Tag GetTag() {
        return m_Tag;
    }

    void SetTag(Tag tag) {
        m_Tag = tag;
    }

private:
    void ResetPosition() { m_Transform.translation = {0, 0}; }

    Tag m_TouchedTag;

    Tag m_Tag;

    std::string m_ImagePath;
};


#endif //CHARACTER_HPP

