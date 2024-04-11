#include "App.hpp"

#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"

App::App(){
    //player
    m_Player = std::make_shared<Character>(RESOURCE_DIR"/Image/Character/player.png");
    m_Player->SetZIndex(50);
    m_Player->SetTag(Character::Tag::Player);
    m_Root.AddChild(m_Player);

    //boss1
    m_Boss1 = std::make_shared<Character>(RESOURCE_DIR"/Image/Character/boss1.png");
    m_Boss1->SetZIndex(50);
    m_Boss1->SetTag(Character::Tag::Boss);
    m_Root.AddChild(m_Boss1);

    //rocks
    for (int i = 0; i < 20; i++) {
        m_Rocks.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Object/rock.png"));
        m_Rocks[i]->SetZIndex(50);
        m_Rocks[i]->SetTag(Character::Tag::Rock);
        m_Root.AddChild(m_Rocks[i]);
    }

    //enemies
    for (int i = 0; i < 20; i++) {
        m_Enemies.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Character/enemy.png"));
        m_Enemies[i]->SetZIndex(50);
        m_Enemies[i]->SetTag(Character::Tag::Enemy);
        m_Root.AddChild(m_Enemies[i]);
    }

    //boundaries_precise
    for (int i = 0; i < 20; ++i) {
        m_BoundaryTs.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Background/Boundary/boundaryRocks.png"));
        m_BoundaryTs[i]->SetZIndex(5);
        m_BoundaryTs[i]->SetVisible(false);
        m_BoundaryTs[i]->SetTag(Character::Tag::Boundary);
        m_Root.AddChild(m_BoundaryTs[i]);
    }

    for (int i = 0; i < 20; ++i) {
        m_BoundaryLs.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Background/Boundary/boundaryRocks.png"));
        m_BoundaryLs[i]->SetZIndex(5);
        m_BoundaryLs[i]->SetVisible(false);
        m_BoundaryLs[i]->SetTag(Character::Tag::Boundary);
        m_Root.AddChild(m_BoundaryLs[i]);
    }

    for (int i = 0; i < 20; ++i) {
        m_BoundaryRs.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Background/Boundary/boundaryRocks.png"));
        m_BoundaryRs[i]->SetZIndex(5);
        m_BoundaryRs[i]->SetVisible(false);
        m_BoundaryRs[i]->SetTag(Character::Tag::Boundary);
        m_Root.AddChild(m_BoundaryRs[i]);
    }

    for (int i = 0; i < 20; ++i) {
        m_BoundaryIBs.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Background/Boundary/boundaryRocks.png"));
        m_BoundaryIBs[i]->SetZIndex(5);
        m_BoundaryIBs[i]->SetVisible(false);
        m_BoundaryIBs[i]->SetTag(Character::Tag::Boundary);
        m_Root.AddChild(m_BoundaryIBs[i]);
    }

    for (int i = 0; i < 7; ++i) {
        m_BoundaryBs.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Background/Boundary/boundaryRocks.png"));
        m_BoundaryBs[i]->SetZIndex(5);
        m_BoundaryBs[i]->SetVisible(false);
        m_BoundaryBs[i]->SetTag(Character::Tag::Boundary);
        m_Root.AddChild(m_BoundaryBs[i]);
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

    m_CurrentState = State::UPDATE;
}

void App::Update() {
    //make player move
    Move(m_Player);

    //Restart the game
    if (Util::Input::IsKeyUp(Util::Keycode::R)) {
        m_CurrentState = State::START;
    }

    //If the step become zero, restart the game
    if (m_StepText->IsStepZero()) {
        m_CurrentState = State::START;
    }

    //closing the window
    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
        Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }

    //update the root
    m_Root.Update();

    //Phase1 setting
    if (m_Phase == Phase::Phase1) {
        //push object
        for (int i = 0; i < 4; i++) {
            Push(m_Player, m_Rocks[i]);
        }
        for (int i = 0; i < 3; i++) {
            Push(m_Player, m_Enemies[i]);
        }

        //set the boundaries reaction
        for (int i = 0; i < 5; ++i) {
            HitBoundaryGetBack(m_Player, m_BoundaryTs[i]);
            for (int j = 0; j < 4; j++) {
                HitBoundaryGetBack(m_Rocks[j], m_BoundaryTs[i]);
            }
            for (int k = 0; k < 3; k++) {
                CrushEnemy(m_Enemies[k], m_BoundaryTs[i]);
            }
        }
        for (int i = 0; i < 5; ++i){
            HitBoundaryGetBack(m_Player, m_BoundaryLs[i]);
            for (int j = 0; j < 4; j++) {
                HitBoundaryGetBack(m_Rocks[j], m_BoundaryLs[i]);
            }
            for (int k = 0; k < 3; k++) {
                CrushEnemy(m_Enemies[k], m_BoundaryLs[i]);
            }
        }
        for (int i = 0; i < 6; ++i){
            HitBoundaryGetBack(m_Player, m_BoundaryRs[i]);
            for (int j = 0; j < 4; j++) {
                HitBoundaryGetBack(m_Rocks[j], m_BoundaryRs[i]);
            }
            for (int k = 0; k < 3; k++) {
                CrushEnemy(m_Enemies[k], m_BoundaryRs[i]);
            }
        }
        for (int i = 0; i < 4; ++i){
            HitBoundaryGetBack(m_Player, m_BoundaryIBs[i]);
            for (int j = 0; j < 4; j++) {
                HitBoundaryGetBack(m_Rocks[j], m_BoundaryIBs[i]);
            }
            for (int k = 0; k < 3; k++) {
                CrushEnemy(m_Enemies[k], m_BoundaryIBs[i]);
            }
        }
        for (int i = 0; i < 7; ++i){
            HitBoundaryGetBack(m_Player, m_BoundaryBs[i]);
            for (int j = 0; j < 4; j++) {
                HitBoundaryGetBack(m_Rocks[j], m_BoundaryBs[i]);
            }
            for (int k = 0; k < 3; k++) {
                CrushEnemy(m_Enemies[k], m_BoundaryBs[i]);
            }
        }

        //if the enemy crash rock, it will die
        //if the rock crash enemy, it can't move
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                CrushEnemy(m_Enemies[i], m_Rocks[j]);
                HitBoundaryGetBack(m_Rocks[j], m_Enemies[i]);
            }
        }

        //if the enemy crash enemy, it will die
        for (int i = 0; i < 3; i++) {
            for (int j = i; j < 3; j++) {
                if (i == j) {
                    continue;
                }
                else {
                    CrushEnemy(m_Enemies[i], m_Enemies[j]);
                }
            }
        }

        //if the rock crash the other rock, it can't move
        for (int i = 0; i < 4; i++) {
            for (int j = i; j < 4; j++) {
                if (i == j) {
                    continue;
                }
                else {
                    HitBoundaryGetBack(m_Rocks[i], m_Rocks[j]);
                }
            }
        }

        //check if phase1 is passed
        if (IsPhase1Passed()) {
            m_Phase = Phase::Phase2;
            m_PRM->NextPhase();
            m_CurrentState = State::START;
        }
    }

    if (m_Phase == Phase::Phase2) {

        for (int i = 0; i < 2; i++) {
            Push(m_Player, m_Rocks[i]);
        }
        for (int i = 0; i < 2; i++) {
            Push(m_Player, m_Enemies[i]);
        }

        //set the boundaries reaction
        for (int i = 0; i < 6; ++i) {
            HitBoundaryGetBack(m_Player, m_BoundaryTs[i]);
            for (int j = 0; j < 4; j++) {
                HitBoundaryGetBack(m_Rocks[j], m_BoundaryTs[i]);
            }
            for (int k = 0; k < 3; k++) {
                CrushEnemy(m_Enemies[k], m_BoundaryTs[i]);
            }
        }
        for (int i = 0; i < 5; ++i){
            HitBoundaryGetBack(m_Player, m_BoundaryLs[i]);
            for (int j = 0; j < 4; j++) {
                HitBoundaryGetBack(m_Rocks[j], m_BoundaryLs[i]);
            }
            for (int k = 0; k < 3; k++) {
                CrushEnemy(m_Enemies[k], m_BoundaryLs[i]);
            }
        }
        for (int i = 0; i < 6; ++i){
            HitBoundaryGetBack(m_Player, m_BoundaryRs[i]);
            for (int j = 0; j < 4; j++) {
                HitBoundaryGetBack(m_Rocks[j], m_BoundaryRs[i]);
            }
            for (int k = 0; k < 3; k++) {
                CrushEnemy(m_Enemies[k], m_BoundaryRs[i]);
            }
        }
        for (int i = 0; i < 10; ++i){
            HitBoundaryGetBack(m_Player, m_BoundaryIBs[i]);
            for (int j = 0; j < 4; j++) {
                HitBoundaryGetBack(m_Rocks[j], m_BoundaryIBs[i]);
            }
            for (int k = 0; k < 3; k++) {
                CrushEnemy(m_Enemies[k], m_BoundaryIBs[i]);
            }
        }
        for (int i = 0; i < 7; ++i){
            HitBoundaryGetBack(m_Player, m_BoundaryBs[i]);
            for (int j = 0; j < 4; j++) {
                HitBoundaryGetBack(m_Rocks[j], m_BoundaryBs[i]);
            }
            for (int k = 0; k < 3; k++) {
                CrushEnemy(m_Enemies[k], m_BoundaryBs[i]);
            }
        }
    }

    //temporary pass phase
    if (Util::Input::IsKeyDown(Util::Keycode::NUM_1)) {
        m_Phase = Phase::Phase1;
        m_PRM->SetPhase(0);
        m_PRM->NextPhase();
        m_CurrentState = State::START;
    }
    else if (Util::Input::IsKeyDown(Util::Keycode::NUM_2)) {
        m_Phase = Phase::Phase2;
        m_PRM->SetPhase(1);
        m_PRM->NextPhase();
        m_CurrentState = State::START;
    }
    else if (Util::Input::IsKeyDown(Util::Keycode::NUM_3)) {
        m_Phase = Phase::Phase3;
        m_PRM->SetPhase(2);
        m_PRM->NextPhase();
        m_CurrentState = State::START;
    }
}

void App::End() { // NOLINT(this method will mutate members in the future)
    LOG_TRACE("End");
}