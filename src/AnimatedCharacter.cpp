//
// Created by 翁廷豪 on 2024/3/6.
//

#include "AnimatedCharacter.hpp"


AnimatedCharacter::AnimatedCharacter(const std::vector<std::string>& AnimationPaths) {
    m_Drawable = std::make_shared<Util::Animation>(AnimationPaths, false, 500, false, 0);
}

bool AnimatedCharacter::IfAnimationEnds() const {
    auto animation = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
    return animation->GetCurrentFrameIndex() == animation->GetFrameCount() - 1;
}

void AnimatedCharacter::PlayAnimation() const {
    auto animation = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
    animation->Play();
}

void AnimatedCharacter::PauseAnimation() const {
    auto animation = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
    animation->Pause();
}