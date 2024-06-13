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
        Laser,
        Machine,
        Chain,
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

    void SetUsed(bool ifUsed) {
        isUsed = ifUsed;
    }

    bool IfUsed() {
        return isUsed;
    }

    std::vector<int> GetUsedLaserIndex() {
        return usedLaser;
    }

    void SetUsedLaserIndex(int index) {
        usedLaser.push_back(index);
    }

    void ResetUsedLaserIndex() {
        usedLaser.clear();
    }

    bool IfUsedLaserEmpty() {
        return usedLaser.empty();
    };

    bool GetIfHurt() {
        return ifHurt;
    }

    void SetIfHurt(bool flag) {
        ifHurt = flag;
    }

    bool GetIfReverse() {
        return ifReverse;
    }

    void SetIfReverse(bool flag) {
        ifReverse = flag;
    }

    void ReSetHitCount() {
        hitCount = 0;
    }

    void BeingHitted() {
        hitCount++;
    }

    bool IfBroken() {
        return (hitCount == 4);
    }

private:
    void ResetPosition() { m_Transform.translation = {0, 0}; }

    Tag m_TouchedTag;

    Tag m_Tag;

    std::string m_ImagePath;

    bool isUsed = false;

    std::vector<int> usedLaser;

    bool ifHurt = false;

    bool ifReverse = false;

    int hitCount = 0;
};

#endif //CHARACTER_HPP

