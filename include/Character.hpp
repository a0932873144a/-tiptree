//
// Created by 翁廷豪 on 2024/3/6.
//

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <queue>
#include "Util/GameObject.hpp"
#include "Util/Input.hpp"
#include "AnimatedCharacter.hpp"

class Character : public Util::GameObject {

public:
    enum class Tag {
        Null,
        Player,
        Rock,
        Enemy,
        Boundary,
        Boss,
        SpikeTrap,
        Key,
        Chest,
        LaserMech,
        Laser
    };

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

    //Collision detection function
    [[nodiscard]] bool IfCollides(const std::shared_ptr<Character>& other) const {
        // Check if the bounding boxes of the characters overlap
        bool collideX = this->GetPosition().x < other->GetPosition().x + other->GetScaledSize().x &&
                        this->GetPosition().x + this->GetScaledSize().x > other->GetPosition().x;
        bool collideY = this->GetPosition().y < other->GetPosition().y + other->GetScaledSize().y &&
                        this->GetPosition().y + this->GetScaledSize().y > other->GetPosition().y;

        return collideX && collideY;
    }

    //Check if collide something
    [[nodiscard]] std::shared_ptr<Character> IfCollideSomething(const std::vector<std::shared_ptr<Character>>& list) const {
        for (const auto& Object : list) {
            if (this == Object.get()) {
                continue;
            }
            else{
                if (this->IfCollides(Object)) {
                    return Object;
                }
            }
        }
        return nullptr;
    }

    //Detect where to move
    [[nodiscard]] static char MoveDirection() {
        if (Util::Input::IsKeyPressed(Util::Keycode::A)) {
            return 'A';
        }
        else if (Util::Input::IsKeyPressed(Util::Keycode::S)) {
            return 'S';
        }
        else if (Util::Input::IsKeyPressed(Util::Keycode::D)) {
            return 'D';
        }
        else if (Util::Input::IsKeyPressed(Util::Keycode::W)) {
            return 'W';
        }
        else {
            return 0;
        }
    }

    void SetLastTouched(Tag tag) {
        m_TouchedTag = tag;
    }

    Tag GetLastTouched() {
        return m_TouchedTag;
    }

    Tag GetTag() const {
        return m_Tag;
    }

    void SetTag(Tag tag) {
        m_Tag = tag;
    }

    [[nodiscard]] std::vector<std::shared_ptr<Character>> GetLaser() const {
        return m_Laser;
    }

    [[nodiscard]] std::vector<std::shared_ptr<AnimatedCharacter>> GetLaserBlink() const {
        return m_LaserBlink;
    }

    void SetLaser(std::vector<std::shared_ptr<Character>>& laser) {
        if (!laser.empty()){
            m_Laser = laser;
        }
    }

    void SetLaserBlink(std::vector<std::shared_ptr<AnimatedCharacter>>& laser) {
        if (!laser.empty()){
            m_LaserBlink = laser;
        }
    }

private:
    void ResetPosition() { m_Transform.translation = {0, 0}; }

    Tag m_TouchedTag;

    Tag m_Tag;

    std::string m_ImagePath;

    std::vector<std::shared_ptr<Character>> m_Laser;

    std::vector<std::shared_ptr<AnimatedCharacter>> m_LaserBlink;
};

#endif //CHARACTER_HPP

