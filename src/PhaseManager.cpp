//
// Created by 翁廷豪 on 2024/3/6.
//

#include "PhaseResourceManger.hpp"

PhaseResourceManger::PhaseResourceManger() {
    m_TaskText = std::make_shared<TaskText>();
    m_Background = std::make_shared<BackgroundImage>();
}

void PhaseResourceManger::NextPhase() {
    m_Background->NextPhase(m_Phase);
    m_TaskText->NextPhase(m_Phase++);
}

void PhaseResourceManger::GameStart() {
    m_Background->SetImage(RESOURCE_DIR"/Image/Background/Map/map0.png");
    m_Background->SetZIndex(-10);
    m_TaskText->SetVisible(true);
}

bool PhaseResourceManger::IfStartScene() {
    return m_Background->GetImagePath() == RESOURCE_DIR"/Image/Background/Map/StartScene.png";
}