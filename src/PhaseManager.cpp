//
// Created by 翁廷豪 on 2024/3/6.
//

#include "PhaseResourceManger.hpp"

PhaseResourceManger::PhaseResourceManger() {
    m_TaskText = std::make_shared<TaskText>();
    m_Background = std::make_shared<BackgroundImage>();
}

void PhaseResourceManger::NextPhase() {
    //TODO: remember to change the number here
    if (m_Phase == 15) return;
    LOG_DEBUG("Passed! Next phase: {}", m_Phase);
    m_Background->NextPhase(m_Phase);
    m_TaskText->NextPhase(m_Phase++);
}