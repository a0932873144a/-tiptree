#include "App.hpp"

#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"

App::App(){
    //player
    m_Player = std::make_shared<Character>(RESOURCE_DIR"/Image/Character/nlnlouo.png");
    m_Player->SetZIndex(60);
    m_Player->SetTag(Character::Tag::Player);
    m_Root.AddChild(m_Player);
    m_CollideObjects.push_back(m_Player);

    //boss
    m_Boss = std::make_shared<Character>(RESOURCE_DIR"/Image/Character/boss/boss1.png");
    m_Boss->SetZIndex(50);
    m_Boss->SetTag(Character::Tag::Boss);
    m_Root.AddChild(m_Boss);
    m_CollideObjects.push_back(m_Boss);

    //bosses
    for (int i = 0; i < 3; i++) {
        m_Bosses.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Character/boss1.png"));
        m_Bosses[i]->SetZIndex(50);
        m_Bosses[i]->SetTag(Character::Tag::Boss);
        m_Root.AddChild(m_Bosses[i]);
        m_CollideObjects.push_back(m_Bosses[i]);
    }

    //rocks
    for (int i = 0; i < 15; i++) {
        m_Rocks.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Object/rock.png"));
        m_Rocks[i]->SetZIndex(50);
        m_Rocks[i]->SetTag(Character::Tag::Rock);
        m_Root.AddChild(m_Rocks[i]);
        m_CollideObjects.push_back(m_Rocks[i]);
    }

    //enemies
    for (int i = 0; i < 10; i++) {
        m_Enemies.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Character/enemy.png"));
        m_Enemies[i]->SetZIndex(50);
        m_Enemies[i]->SetTag(Character::Tag::Enemy);
        m_Root.AddChild(m_Enemies[i]);
        m_CollideObjects.push_back(m_Enemies[i]);
    }

    //spikeTraps
    for (int i = 0; i < 10; i++) {
        m_SpikeTraps.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Object/spikeTrap.png"));
        m_SpikeTraps[i]->SetZIndex(50);
        m_SpikeTraps[i]->SetTag(Character::Tag::SpikeTrap);
        m_Root.AddChild(m_SpikeTraps[i]);
        m_CollideObjects.push_back(m_SpikeTraps[i]);
    }

    //hiddenSpikeTraps
    for (int i = 0; i < 10; i++) {
        m_HiddenSpikeTraps.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Object/spikeTrap_hidden.png"));
        m_HiddenSpikeTraps[i]->SetZIndex(50);
        m_HiddenSpikeTraps[i]->SetTag(Character::Tag::Null);
        m_Root.AddChild(m_HiddenSpikeTraps[i]);
    }

    //key
    m_Key = std::make_shared<Character>(RESOURCE_DIR"/Image/Object/key.png");
    m_Key->SetZIndex(50);
    m_Key->SetTag(Character::Tag::Key);
    m_Root.AddChild(m_Key);
    m_CollideObjects.push_back(m_Key);

    //treasureBox
    m_TreasureBox = std::make_shared<Character>(RESOURCE_DIR"/Image/Object/treasureBox.png");
    m_TreasureBox->SetZIndex(50);
    m_TreasureBox->SetTag(Character::Tag::Chest);
    m_Root.AddChild(m_TreasureBox);
    m_CollideObjects.push_back(m_TreasureBox);

    //boundaries_precise
    for (int i = 0; i < 10; ++i) {
        m_BoundaryTs.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Background/Boundary/boundaryRocks.png"));
        m_BoundaryTs[i]->SetZIndex(5);
        m_BoundaryTs[i]->SetVisible(false);
        m_BoundaryTs[i]->SetTag(Character::Tag::Boundary);
        m_Root.AddChild(m_BoundaryTs[i]);
        m_CollideObjects.push_back(m_BoundaryTs[i]);
    }
    for (int i = 0; i < 10; ++i) {
        m_BoundaryLs.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Background/Boundary/boundaryRocks.png"));
        m_BoundaryLs[i]->SetZIndex(5);
        m_BoundaryLs[i]->SetVisible(false);
        m_BoundaryLs[i]->SetTag(Character::Tag::Boundary);
        m_Root.AddChild(m_BoundaryLs[i]);
        m_CollideObjects.push_back(m_BoundaryLs[i]);
    }
    for (int i = 0; i < 10; ++i) {
        m_BoundaryRs.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Background/Boundary/boundaryRocks.png"));
        m_BoundaryRs[i]->SetZIndex(5);
        m_BoundaryRs[i]->SetVisible(false);
        m_BoundaryRs[i]->SetTag(Character::Tag::Boundary);
        m_Root.AddChild(m_BoundaryRs[i]);
        m_CollideObjects.push_back(m_BoundaryRs[i]);
    }
    for (int i = 0; i < 10; ++i) {
        m_BoundaryIBs.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Background/Boundary/boundaryRocks.png"));
        m_BoundaryIBs[i]->SetZIndex(5);
        m_BoundaryIBs[i]->SetVisible(false);
        m_BoundaryIBs[i]->SetTag(Character::Tag::Boundary);
        m_Root.AddChild(m_BoundaryIBs[i]);
        m_CollideObjects.push_back(m_BoundaryIBs[i]);
    }
    for (int i = 0; i < 10; ++i) {
        m_BoundaryBs.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Background/Boundary/boundaryRocks.png"));
        m_BoundaryBs[i]->SetZIndex(5);
        m_BoundaryBs[i]->SetVisible(false);
        m_BoundaryBs[i]->SetTag(Character::Tag::Boundary);
        m_Root.AddChild(m_BoundaryBs[i]);
        m_CollideObjects.push_back(m_BoundaryBs[i]);
    }

    //StepText
    m_StepText = std::make_shared<StepText>();
    m_Root.AddChild(m_StepText);

    //PhaseResourceManger
    m_PRM = std::make_shared<PhaseResourceManger>();
    m_Root.AddChildren(m_PRM->GetChildren());
}

void App::Start() {
    LOG_TRACE("Start");

    ValidTask();

    m_Player->SetLastTouched(Character::Tag::Null);
    m_CurrentState = State::UPDATE;
}

void App::Update() {
    //update the root
    m_Root.Update();

    //temporary pass phase
    if (Util::Input::IsKeyDown(Util::Keycode::NUM_1)) {
        m_Phase = Phase::Phase1;
        m_PRM->SetPhase(0);
        m_PRM->NextPhase();
        m_CurrentState = State::START;
        return;
    }
    else if (Util::Input::IsKeyDown(Util::Keycode::NUM_2)) {
        m_Phase = Phase::Phase2;
        m_PRM->SetPhase(1);
        m_PRM->NextPhase();
        m_CurrentState = State::START;
        return;
    }
    else if (Util::Input::IsKeyDown(Util::Keycode::NUM_3)) {
        m_Phase = Phase::Phase3;
        m_PRM->SetPhase(2);
        m_PRM->NextPhase();
        m_CurrentState = State::START;
        return;
    }
    else if (Util::Input::IsKeyDown(Util::Keycode::NUM_4)) {
        m_Phase = Phase::Phase4;
        m_PRM->SetPhase(3);
        m_PRM->NextPhase();
        m_CurrentState = State::START;
        return;
    }
    else if (Util::Input::IsKeyDown(Util::Keycode::NUM_5)) {
        m_Phase = Phase::Phase5;
        m_PRM->SetPhase(4);
        m_PRM->NextPhase();
        m_CurrentState = State::START;
        return;
    }

    //make player move
    if (m_Player->GetVisibility()) {
        Move(m_Player);
    }

    //Restart the game
    if (Util::Input::IsKeyUp(Util::Keycode::R)) {
        m_CurrentState = State::START;
        return;
    }

    //If the step become zero, restart the game
    if (m_StepText->IsStepZero()) {
        m_CurrentState = State::START;
    }

    //closing the window
    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
        Util::Input::IfExit()) {
        m_CurrentState = State::END;
        return;
    }

    //Phase1 setting
    if (m_Phase == Phase::Phase1) {
        //check if phase1 is passed
        if (IsPhasePassed()) {
            m_Phase = Phase::Phase2;
            m_PRM->NextPhase();
            m_CurrentState = State::START;
            return;
        }
    }

    if (m_Phase == Phase::Phase2) {
        //check if phase2 is passed
        if (IsPhasePassed()) {
            m_Phase = Phase::Phase3;
            m_PRM->NextPhase();
            m_CurrentState = State::START;
            return;
        }
    }

    if (m_Phase == Phase::Phase3) {
        //check if phase3 is passed
        if (IsPhase3Passed()) {
            m_Phase = Phase::Phase4;
            m_PRM->NextPhase();
            m_CurrentState = State::START;
            return;
        }
    }

    if (m_Phase == Phase::Phase4) {
        //check if phase3 is passed
        if (IsPhasePassed()) {
            m_Phase = Phase::Phase5;
            m_PRM->NextPhase();
            m_CurrentState = State::START;
            return;
        }
    }

    if (m_Phase == Phase::Phase5) {
        //check if phase3 is passed
        if (IsPhasePassed()) {
            m_Phase = Phase::Phase6;
            m_PRM->NextPhase();
            m_CurrentState = State::START;
            return;
        }
    }
}

void App::End() { // NOLINT(this method will mutate members in the future)
    LOG_TRACE("End");
}