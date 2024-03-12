#include "App.hpp"

#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"

App::App(){
    //player
    m_Player = std::make_shared<Character>(RESOURCE_DIR"/Image/Character/player.png");
    m_Player->SetZIndex(50);
    m_Root.AddChild(m_Player);

    //boss1
    m_Boss1 = std::make_shared<Character>(RESOURCE_DIR"/Image/Character/boss1.png");
    m_Boss1->SetZIndex(50);
    m_Root.AddChild(m_Boss1);

    //rock
    m_Rock = std::make_shared<Character>(RESOURCE_DIR"/Image/Character/rock.png");
    m_Rock->SetZIndex(50);
    m_Root.AddChild(m_Rock);

    //enemy
    m_Enemy = std::make_shared<Character>(RESOURCE_DIR"/Image/Character/enemy.png");
    m_Enemy->SetZIndex(50);
    m_Root.AddChild(m_Enemy);

    //TODO(to RAY): example here (but not SetPosition here, go to AppUtil.cpp instead)
    //rocks
//    for (int i = 0; i < 3; ++i) {
//        m_Rocks_Phase1.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Character/rock.png"));
//        m_Rocks_Phase1[i]->SetZIndex(50);
//        m_Rocks_Phase1[i]->SetPosition({205.5f - 80.f * i, -3.5f});
//        m_Rocks_Phase1[i]->SetVisible(false);
//        m_Root.AddChild(m_Rocks_Phase1[i]);
//    }

    //boundaries
    m_BoundaryL = std::make_shared<Character>(RESOURCE_DIR"/Image/Background/boundary_straight.png");
    m_BoundaryL->SetZIndex(50);
    m_Root.AddChild(m_BoundaryL);
    m_BoundaryR = std::make_shared<Character>(RESOURCE_DIR"/Image/Background/boundary_straight.png");
    m_BoundaryR->SetZIndex(50);
    m_Root.AddChild(m_BoundaryR);
    m_BoundaryT = std::make_shared<Character>(RESOURCE_DIR"/Image/Background/boundary_ horizontal.png");
    m_BoundaryT->SetZIndex(50);
    m_Root.AddChild(m_BoundaryT);
    m_BoundaryB = std::make_shared<Character>(RESOURCE_DIR"/Image/Background/boundary_ horizontal.png");
    m_BoundaryB->SetZIndex(50);
    m_Root.AddChild(m_BoundaryB);

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

    //push object
    Push(m_Player, m_Rock);
    Push(m_Player, m_Enemy);

    //the characters can't cross the boundaries
    HitBoundary(m_Player);
    HitBoundary(m_Rock);
    HitBoundary(m_Enemy);

    //if the enemy crash something, it will die
    CrushEnemy(m_Enemy, m_Rock);

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
}

void App::End() { // NOLINT(this method will mutate members in the future)
    LOG_TRACE("End");
}
