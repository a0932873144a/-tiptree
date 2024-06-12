#include "App.hpp"

#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include "Util/Time.hpp"

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
        m_Bosses.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Character/boss/boss1.png"));
        m_Bosses[i]->SetZIndex(50);
        m_Bosses[i]->SetTag(Character::Tag::Boss);
        m_Root.AddChild(m_Bosses[i]);
        m_CollideObjects.push_back(m_Bosses[i]);
    }

    //Machines
    for (int i = 0; i < 4; i++) {
        m_Machines.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Object/BEEMO.png"));
        m_Machines[i]->SetZIndex(50);
        m_Machines[i]->SetTag(Character::Tag::Machine);
        m_Root.AddChild(m_Machines[i]);
        m_CollideObjects.push_back(m_Machines[i]);
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
    for (int i = 0; i < 15; i++) {
        m_SpikeTraps.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Object/spikeTrap.png"));
        m_SpikeTraps[i]->SetZIndex(45);
        m_SpikeTraps[i]->SetTag(Character::Tag::SpikeTrap);
        m_Root.AddChild(m_SpikeTraps[i]);
        m_CollideObjects.push_back(m_SpikeTraps[i]);
    }

    //hiddenSpikeTraps
    for (int i = 0; i < 10; i++) {
        m_HiddenSpikeTraps.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Object/spikeTrap_hidden.png"));
        m_HiddenSpikeTraps[i]->SetZIndex(40);
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

    //laserMechBoxes
    for (int i = 0; i < 10; ++i) {
        m_LaserMechBoxes.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Object/laserMechBox.png"));
        m_LaserMechBoxes[i]->SetZIndex(50);
        m_LaserMechBoxes[i]->SetTag(Character::Tag::LaserMech);
        m_Root.AddChild(m_LaserMechBoxes[i]);
        m_CollideObjects.push_back(m_LaserMechBoxes[i]);
    }

    //lasers
    for (int i = 0; i < 20; ++i) {
        m_LaserTs.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Object/laserBeamT.png"));
        m_LaserTs[i]->SetZIndex(70);
        m_LaserTs[i]->SetTag(Character::Tag::Laser);
        m_Root.AddChild(m_LaserTs[i]);
        m_CollideObjects.push_back(m_LaserTs[i]);
        m_LaserTs[i]->SetIfHurt(true);
    }
    for (int i = 0; i < 20; ++i) {
        m_LaserLs.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Object/laserBeamL.png"));
        m_LaserLs[i]->SetZIndex(70);
        m_LaserLs[i]->SetTag(Character::Tag::Laser);
        m_Root.AddChild(m_LaserLs[i]);
        m_CollideObjects.push_back(m_LaserLs[i]);
        m_LaserLs[i]->SetIfHurt(true);
    }
    for (int i = 0; i < 20; ++i) {
        m_LaserRs.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Object/laserBeamR.png"));
        m_LaserRs[i]->SetZIndex(70);
        m_LaserRs[i]->SetTag(Character::Tag::Laser);
        m_Root.AddChild(m_LaserRs[i]);
        m_CollideObjects.push_back(m_LaserRs[i]);
        m_LaserRs[i]->SetIfHurt(true);
    }
    for (int i = 0; i < 20; ++i) {
        m_LaserBs.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Object/laserBeamB.png"));
        m_LaserBs[i]->SetZIndex(70);
        m_LaserBs[i]->SetTag(Character::Tag::Laser);
        m_Root.AddChild(m_LaserBs[i]);
        m_CollideObjects.push_back(m_LaserBs[i]);
        m_LaserBs[i]->SetIfHurt(true);
    }

    //boundaries_precise
    for (int i = 0; i < 12; ++i) {
        m_BoundaryTs.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Background/Boundary/newRock.png"));
        m_BoundaryTs[i]->SetZIndex(5);
        m_BoundaryTs[i]->SetVisible(false);
        m_BoundaryTs[i]->SetTag(Character::Tag::Boundary);
        m_Root.AddChild(m_BoundaryTs[i]);
        m_CollideObjects.push_back(m_BoundaryTs[i]);
    }
    for (int i = 0; i < 11; ++i) {
        m_BoundaryLs.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Background/Boundary/newRock.png"));
        m_BoundaryLs[i]->SetZIndex(5);
        m_BoundaryLs[i]->SetVisible(false);
        m_BoundaryLs[i]->SetTag(Character::Tag::Boundary);
        m_Root.AddChild(m_BoundaryLs[i]);
        m_CollideObjects.push_back(m_BoundaryLs[i]);
    }
    for (int i = 0; i < 11; ++i) {
        m_BoundaryRs.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Background/Boundary/newRock.png"));
        m_BoundaryRs[i]->SetZIndex(5);
        m_BoundaryRs[i]->SetVisible(false);
        m_BoundaryRs[i]->SetTag(Character::Tag::Boundary);
        m_Root.AddChild(m_BoundaryRs[i]);
        m_CollideObjects.push_back(m_BoundaryRs[i]);
    }
    for (int i = 0; i < 10; ++i) {
        m_BoundaryIBs.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Background/Boundary/newRock.png"));
        m_BoundaryIBs[i]->SetZIndex(5);
        m_BoundaryIBs[i]->SetVisible(false);
        m_BoundaryIBs[i]->SetTag(Character::Tag::Boundary);
        m_Root.AddChild(m_BoundaryIBs[i]);
        m_CollideObjects.push_back(m_BoundaryIBs[i]);
    }
    for (int i = 0; i < 11; ++i) {
        m_BoundaryBs.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Background/Boundary/newRock.png"));
        m_BoundaryBs[i]->SetZIndex(5);
        m_BoundaryBs[i]->SetVisible(false);
        m_BoundaryBs[i]->SetTag(Character::Tag::Boundary);
        m_Root.AddChild(m_BoundaryBs[i]);
        m_CollideObjects.push_back(m_BoundaryBs[i]);
    }

    //chains
    for (int i = 0; i < 7; ++i) {
        m_ChainVerticals.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Object/chainAttackVertical.png"));
        m_ChainVerticals[i]->SetZIndex(80);
        m_ChainVerticals[i]->SetVisible(false);
        m_ChainVerticals[i]->SetTag(Character::Tag::Chain);
        m_Root.AddChild(m_ChainVerticals[i]);
        m_CollideObjects.push_back(m_ChainVerticals[i]);
    }
    for (int i = 0; i < 5; ++i) {
        m_ChainHorizontals.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Object/chainAttackHorizontal.png"));
        m_ChainHorizontals[i]->SetZIndex(80);
        m_ChainHorizontals[i]->SetVisible(false);
        m_ChainHorizontals[i]->SetTag(Character::Tag::Chain);
        m_Root.AddChild(m_ChainHorizontals[i]);
        m_CollideObjects.push_back(m_ChainHorizontals[i]);
    }

    for (int i = 0; i < 4; ++i) {
        m_Crosses.push_back(std::make_shared<Character>(RESOURCE_DIR"/Image/Object/cross.png"));
        m_Crosses[i]->SetZIndex(80);
        m_Crosses[i]->SetVisible(false);
        m_Crosses[i]->SetTag(Character::Tag::Null);
        m_Root.AddChild(m_Crosses[i]);
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

    m_Player->SetLastTouched(Character::Tag::Null);
    timer = 0;
    invincibleTime = 0;
    switchImage = false;
    switchCount = 0;
    FM.ResetCycle();
    FM.ResetState();

    ValidTask();
    if (m_PRM->IfStartScene()) {
        m_StepText->SetVisible(false);
    }
    m_CurrentState = State::UPDATE;
}

void App::Update() {
    //update the root
    m_Root.Update();

    if (m_PRM->IfStartScene()) {
        if (Util::Input::IsKeyDown(Util::Keycode::SPACE)) {
            m_PRM->GameStart();
            m_StepText->SetVisible(true);
        }
    }

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
    else if (Util::Input::IsKeyDown(Util::Keycode::NUM_6)) {
        m_Phase = Phase::Phase6;
        m_PRM->SetPhase(5);
        m_PRM->NextPhase();
        m_CurrentState = State::START;
        return;
    }
    else if (Util::Input::IsKeyDown(Util::Keycode::NUM_7)) {
        m_Phase = Phase::Phase7;
        m_PRM->SetPhase(6);
        m_PRM->NextPhase();
        m_CurrentState = State::START;
        return;
    }
    else if (Util::Input::IsKeyDown(Util::Keycode::NUM_8)) {
        m_Phase = Phase::Phase8;
        m_PRM->SetPhase(7);
        m_PRM->NextPhase();
        m_CurrentState = State::START;
        return;
    }
    else if (Util::Input::IsKeyDown(Util::Keycode::NUM_9)) {
        m_Phase = Phase::Phase9;
        m_PRM->SetPhase(8);
        m_PRM->NextPhase();
        m_CurrentState = State::START;
        return;
    }
    else if (Util::Input::IsKeyDown(Util::Keycode::NUM_0)) {
        m_Phase = Phase::Phase10;
        m_PRM->SetPhase(9);
        m_PRM->NextPhase();
        m_CurrentState = State::START;
        return;
    }
    else if (Util::Input::IsKeyDown(Util::Keycode::F)) {
        m_Phase = Phase::PhaseFindal;
        m_PRM->SetPhase(15);
        m_PRM->NextPhase();
        m_CurrentState = State::START;
        return;
    }

    //Skip the puzzle
    if (Util::Input::IsKeyUp(Util::Keycode::N)) {
        m_Phase = nextPhase(m_Phase);
        m_PRM->NextPhase();
        m_CurrentState = State::START;
        return;
    }

    //Restart the game
    if (Util::Input::IsKeyUp(Util::Keycode::R)) {
        if (m_Phase == Phase::Phase8_2) {
            m_Phase = Phase::Phase8;
            m_PRM->SwitchTo8();
        }
        m_CurrentState = State::START;
        return;
    }

    //closing the window
    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
        Util::Input::IfExit()) {
        m_CurrentState = State::END;
        return;
    }

    //Phase1 setting
    if (m_Phase == Phase::Phase1) {
        //make player move
        if (m_Player->GetVisibility()) {
            Move(m_Player);
        }

        //check if phase1 is passed
        if (IsPhasePassed()) {
            m_Phase = Phase::Phase2;
            m_PRM->NextPhase();
            m_CurrentState = State::START;
            return;
        }
    }

    if (m_Phase == Phase::Phase2) {
        //make player move
        if (m_Player->GetVisibility()) {
            Move(m_Player);
        }

        //check if phase2 is passed
        if (IsPhasePassed()) {
            m_Phase = Phase::Phase3;
            m_PRM->NextPhase();
            m_CurrentState = State::START;
            return;
        }
    }

    if (m_Phase == Phase::Phase3) {
        //make player move
        if (m_Player->GetVisibility()) {
            Move(m_Player);
        }

        //check if phase3 is passed
        if (IsPhase3Passed()) {
            m_Phase = Phase::Phase4;
            m_PRM->NextPhase();
            m_CurrentState = State::START;
            return;
        }
    }

    if (m_Phase == Phase::Phase4) {
        //make player move
        if (m_Player->GetVisibility()) {
            Move(m_Player);
        }

        //check if phase4 is passed
        if (IsPhasePassed()) {
            m_Phase = Phase::Phase5;
            m_PRM->NextPhase();
            m_CurrentState = State::START;
            return;
        }
    }

    if (m_Phase == Phase::Phase5) {
        //make player move
        if (m_Player->GetVisibility()) {
            Move(m_Player);
        }

        //check if phase5 is passed
        if (IsPhasePassed()) {
            m_Phase = Phase::Phase6;
            m_PRM->NextPhase();
            m_CurrentState = State::START;
            return;
        }
    }

    if (m_Phase == Phase::Phase6) {
        //make player move
        if (m_Player->GetVisibility()) {
            Move(m_Player);
        }

        //check if phase6 is passed
        if (IsPhasePassed()) {
            m_Phase = Phase::Phase7;
            m_PRM->NextPhase();
            m_CurrentState = State::START;
            return;
        }
    }

    if (m_Phase == Phase::Phase7) {
        //make player move
        if (m_Player->GetVisibility()) {
            Move(m_Player);
        }

        //check if phase7 is passed
        if (IsPhasePassed()) {
            m_Phase = Phase::Phase8;
            m_PRM->NextPhase();
            m_CurrentState = State::START;
            return;
        }
    }

    if (m_Phase == Phase::Phase8 || m_Phase == Phase::Phase8_2) {
        //make player move
        if (m_Player->GetVisibility()) {
            Move(m_Player);
        }

        //check if phase8 is passed
        if (IsPhasePassed()) {
            m_Phase = Phase::Phase9;
            m_PRM->NextPhase();
            m_CurrentState = State::START;
            return;
        }

        //check if switch background
        if (m_Player->GetPosition().y > 280) {
            m_Phase = Phase::Phase8_2;
            m_PRM->SwitchTo8_2();
            m_CurrentState = State::START;
            return;
        }
        else if (m_Player->GetPosition().y < -280) {
            m_Phase = Phase::Phase8;
            m_PRM->SwitchTo8();
            m_CurrentState = State::START;
            return;
        }

        if (m_Phase == Phase::Phase8_2) {
            if (m_StepText->IsStepZero()) {
                m_Phase = Phase::Phase8;
                m_PRM->SwitchTo8();
                m_CurrentState = State::START;
                return;
            }
        }
    }

    if (m_Phase == Phase::Phase9) {
        //make player move
        if (m_Player->GetVisibility()) {
            Move(m_Player);
        }

        //check if phase9 is passed
        if (IsPhasePassed()) {
            m_Phase = Phase::Phase10;
            m_PRM->NextPhase();
            m_CurrentState = State::START;
            return;
        }
    }

    if (m_Phase == Phase::Phase10) {
        //make player move
        if (m_Player->GetVisibility()) {
            MoveEx(m_Player);
        }

        //check if phase10 is passed
        if (IsPhaseExPassed()) {
            m_Phase = Phase::Phase11;
            m_PRM->NextPhase();
            m_CurrentState = State::START;
            return;
        }
    }

    if (m_Phase == Phase::Phase11) {
        timer += Util::Time::GetDeltaTime();

        //make lasers blink
        BlinkLaser();

        //make player move
        if (m_Player->GetVisibility()) {
            MoveEx(m_Player);
        }

        //Check if player touched the layer
        IfPlayerTouchLaser();

        //check if phase11 is passed
        if (IsPhaseExPassed()) {
            m_Phase = Phase::Phase12;
            m_PRM->NextPhase();
            m_CurrentState = State::START;
            return;
        }
    }

    if (m_Phase == Phase::Phase12) {
        //make player move
        if (m_Player->GetVisibility()) {
            MoveEx(m_Player);
        }

        //check if phase12 is passed
        if (IsPhaseExPassed()) {
            m_Phase = Phase::Phase13;
            m_PRM->NextPhase();
            m_CurrentState = State::START;
            return;
        }
    }

    if (m_Phase == Phase::Phase13) {
        timer += Util::Time::GetDeltaTime();

        //make lasers blink
        BlinkLaser();

        //make player move
        if (m_Player->GetVisibility()) {
            MoveEx(m_Player);
        }

        //Check if player touched the layer
        IfPlayerTouchLaser();

        //check if phase13 is passed
        if (IsPhaseExPassed()) {
            m_Phase = Phase::Phase14;
            m_PRM->NextPhase();
            m_CurrentState = State::START;
            return;
        }
    }

    if (m_Phase == Phase::Phase14) {
        //make player move
        if (m_Player->GetVisibility()) {
            MoveEx(m_Player);
        }

        //check if phase14 is passed
        if (IsPhaseExPassed()) {
            m_Phase = Phase::Phase15;
            m_PRM->NextPhase();
            m_CurrentState = State::START;
            return;
        }
    }

    if (m_Phase == Phase::Phase15) {
        timer += Util::Time::GetDeltaTime();

        //make lasers blink
        BlinkLaser();

        //make player move
        if (m_Player->GetVisibility()) {
            MoveEx(m_Player);
        }

        //Check if player touched the layer
        IfPlayerTouchLaser();

        //check if phase15 is passed
        if (IsPhaseExPassed()) {
            m_Phase = Phase::PhaseFindal;
            m_PRM->NextPhase();
            m_CurrentState = State::START;
            return;
        }
    }

    if (m_Phase == Phase::PhaseFindal) {
        timer += Util::Time::GetDeltaTime();
        invincibleTime += Util::Time::GetDeltaTime();

        //make chains blink
        BlinkChain();

        if (!FM.IsCycleDone()) {
            UpGoingPlayer();
        }
        else {
            ValidState();
        }

        //make player move
        if (m_Player->GetVisibility()) {
            MoveFinal(m_Player);
        }

        //Check if player touched the chain and spike
        if (invincibleTime > 1) {
            IfPlayerTouchChain();
            IfPlayerTouchSpike();
        }

        //check if phaseFinal is passed

    }

    //If the step become zero, restart the game
    if (m_StepText->IsStepZero()) {
        m_CurrentState = State::START;
        return;
    }
}

void App::End() { // NOLINT(this method will mutate members in the future)
    LOG_TRACE("End");
}