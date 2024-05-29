//
// Created by 翁廷豪 on 2024/3/6.
//

#ifndef ANIMATED_CHARACTER_HPP
#define ANIMATED_CHARACTER_HPP

#include <vector>
#include <string>

#include "Util/Animation.hpp"
#include "Util/GameObject.hpp"


class AnimatedCharacter : public Util::GameObject {

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
    };

    explicit AnimatedCharacter(const std::vector<std::string>& AnimationPaths);

    [[nodiscard]] bool IsLooping() const {
        return std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->GetLooping();
    }

    [[nodiscard]] bool IsPlaying() const {
        return std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->GetState() == Util::Animation::State::PLAY;
    }

    void SetLooping(bool looping) {
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
        temp->SetLooping(looping);
    }

    [[nodiscard]] bool IfAnimationEnds() const;

    void PlayAnimation() const;

    void PauseAnimation() const;

    [[nodiscard]] const std::vector<std::string>& GetImagePath() const { return m_AnimationPaths; }

    [[nodiscard]] const glm::vec2& GetPosition() const { return m_Transform.translation; }

    [[nodiscard]] bool GetVisibility() const { return m_Visible; }

    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }

    //Collision detection function
    [[nodiscard]] bool IfCollides(const std::shared_ptr<AnimatedCharacter>& other) const {
        // Check if the bounding boxes of the characters overlap
        bool collideX = this->GetPosition().x < other->GetPosition().x + other->GetScaledSize().x &&
                        this->GetPosition().x + this->GetScaledSize().x > other->GetPosition().x;
        bool collideY = this->GetPosition().y < other->GetPosition().y + other->GetScaledSize().y &&
                        this->GetPosition().y + this->GetScaledSize().y > other->GetPosition().y;

        return collideX && collideY;
    }

    //Check if collide something
    [[nodiscard]] std::shared_ptr<AnimatedCharacter> IfCollideSomething(const std::vector<std::shared_ptr<AnimatedCharacter>>& list) const {
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

    void SetLastTouched(Tag tag) {
        m_TouchedTag = tag;
    }

    Tag GetLastTouched() {
        return m_TouchedTag;
    }

    [[nodiscard]] Tag GetTag() const {
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

private:
    void ResetPosition() { m_Transform.translation = {0, 0}; }

    Tag m_TouchedTag;

    Tag m_Tag;

    std::vector<std::string> m_AnimationPaths;

    bool isUsed = false;

    std::vector<int> usedLaser;
};

#endif //ANIMATED_CHARACTER_HPP

