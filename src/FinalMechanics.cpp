//
// Created by 翁廷豪 on 2024/6/11.
//

#include <cstdlib>
#include <ctime>
#include "FinalMechanics.hpp"
#include "Util/Input.hpp"
#include "App.hpp"

//MoveFinal(the character you want to control)
void App::MoveFinal(const std::shared_ptr<Character>& player) {
    std::shared_ptr<Character> tempPtr = std::make_shared<Character>(RESOURCE_DIR"/Image/Character/player.png");
    std::shared_ptr<Character> collidtion;

    if (Util::Input::IsKeyDown(Util::Keycode::A)) {
        tempPtr->SetPosition({player->GetPosition().x - grid_size, player->GetPosition().y});
        collidtion = tempPtr->IfCollideSomething(m_CollideObjects);

        if (collidtion == nullptr) {
            player->SetLastTouched(Character::Tag::Null);
            player->SetPosition({player->GetPosition().x - grid_size, player->GetPosition().y});
        }
        else if (collidtion->GetTag() == Character::Tag::Boundary) {
            player->SetLastTouched(collidtion->GetTag());
            tempPtr.reset();
            collidtion.reset();
            return;
        }
        else if (collidtion->GetTag() == Character::Tag::Machine) {
            collidtion->BeingHitted();
            if (collidtion->IfBroken()) {
                collidtion->SetImage(RESOURCE_DIR"/Image/Object/BEEMOdead.png");
                ChangeStateImage();
            }
            player->SetLastTouched(collidtion->GetTag());
            tempPtr.reset();
            collidtion.reset();
            return;
        }
        else {
            player->SetLastTouched(collidtion->GetTag());
            player->SetPosition({player->GetPosition().x - grid_size, player->GetPosition().y});
        }

        tempPtr.reset();
        collidtion.reset();
        return;
    }

    if (Util::Input::IsKeyDown(Util::Keycode::D)) {
        tempPtr->SetPosition({player->GetPosition().x + grid_size, player->GetPosition().y});
        collidtion = tempPtr->IfCollideSomething(m_CollideObjects);

        if (collidtion == nullptr) {
            player->SetLastTouched(Character::Tag::Null);
            player->SetPosition({player->GetPosition().x + grid_size, player->GetPosition().y});
        }
        else if (collidtion->GetTag() == Character::Tag::Boundary) {
            player->SetLastTouched(collidtion->GetTag());
            tempPtr.reset();
            collidtion.reset();
            return;
        }
        else if (collidtion->GetTag() == Character::Tag::Machine) {
            collidtion->BeingHitted();
            if (collidtion->IfBroken()) {
                collidtion->SetImage(RESOURCE_DIR"/Image/Object/BEEMOdead.png");
                ChangeStateImage();
            }
            player->SetLastTouched(collidtion->GetTag());
            tempPtr.reset();
            collidtion.reset();
            return;
        }
        else {
            player->SetLastTouched(collidtion->GetTag());
            player->SetPosition({player->GetPosition().x + grid_size, player->GetPosition().y});
        }

        tempPtr.reset();
        collidtion.reset();
        return;
    }

    if (Util::Input::IsKeyDown(Util::Keycode::S)) {
        tempPtr->SetPosition({player->GetPosition().x, player->GetPosition().y - grid_size});
        collidtion = tempPtr->IfCollideSomething(m_CollideObjects);

        if (collidtion == nullptr) {
            player->SetLastTouched(Character::Tag::Null);
            player->SetPosition({player->GetPosition().x, player->GetPosition().y - grid_size});
        }
        else if (collidtion->GetTag() == Character::Tag::Boundary) {
            player->SetLastTouched(collidtion->GetTag());
            tempPtr.reset();
            collidtion.reset();
            return;
        }
        else if (collidtion->GetTag() == Character::Tag::Machine) {
            collidtion->BeingHitted();
            if (collidtion->IfBroken()) {
                collidtion->SetImage(RESOURCE_DIR"/Image/Object/BEEMOdead.png");
                ChangeStateImage();
            }
            player->SetLastTouched(collidtion->GetTag());
            tempPtr.reset();
            collidtion.reset();
            return;
        }
        else {
            player->SetLastTouched(collidtion->GetTag());
            player->SetPosition({player->GetPosition().x, player->GetPosition().y - grid_size});
        }

        tempPtr.reset();
        collidtion.reset();
        return;
    }

    if (Util::Input::IsKeyDown(Util::Keycode::W)) {
        tempPtr->SetPosition({player->GetPosition().x, player->GetPosition().y + grid_size});
        collidtion = tempPtr->IfCollideSomething(m_CollideObjects);

        if (collidtion == nullptr) {
            player->SetLastTouched(Character::Tag::Null);
            player->SetPosition({player->GetPosition().x, player->GetPosition().y + grid_size});
        }
        else if (collidtion->GetTag() == Character::Tag::Boundary) {
            player->SetLastTouched(collidtion->GetTag());
            tempPtr.reset();
            collidtion.reset();
            return;
        }
        else if (collidtion->GetTag() == Character::Tag::Machine) {
            collidtion->BeingHitted();
            if (collidtion->IfBroken()) {
                collidtion->SetImage(RESOURCE_DIR"/Image/Object/BEEMOdead.png");
                ChangeStateImage();
            }
            player->SetLastTouched(collidtion->GetTag());
            tempPtr.reset();
            collidtion.reset();
            return;
        }
        else {
            player->SetLastTouched(collidtion->GetTag());
            player->SetPosition({player->GetPosition().x, player->GetPosition().y + grid_size});
        }

        tempPtr.reset();
        collidtion.reset();
        return;
    }

    tempPtr.reset();
    collidtion.reset();
}

void App::ChangeChainPattern() {
    srand(time(nullptr));

    int maxNum = FM.GetState();
    int chainNum = rand() % (maxNum + 1);
    int choiceVH = rand() % 2;
    int choiceV = rand() % 7;
    int choiceH = rand() % 5;

    for (int i = 0; i <= chainNum; i++) {
        if (choiceVH == 0) {
            while (m_ChainVerticals[choiceV]->IfUsed()) {
                choiceV = rand() % 7;
            }
            ShootChain(m_ChainVerticals[choiceV]);
        }
        else {
            while (m_ChainHorizontals[choiceH]->IfUsed()) {
                choiceH = rand() % 5;
            }
            ShootChain(m_ChainHorizontals[choiceH]);
        }

        choiceVH = rand() % 2;
    }
}

void App::ShootChain(const std::shared_ptr<Character>& chain) {
    chain->SetVisible(true);
    chain->SetUsed(true);
}

void App::InitiateBlinkChain() {
    for (const auto &m_ChainVertical: m_ChainVerticals) {
        m_ChainVertical->SetImage(RESOURCE_DIR"/Image/Object/Transparent.png");
        m_ChainVertical->SetVisible(true);
        m_ChainVertical->SetUsed(false);
        m_ChainVertical->SetIfReverse(false);
    }
    for (const auto &m_ChainHorizontal: m_ChainHorizontals) {
        m_ChainHorizontal->SetImage(RESOURCE_DIR"/Image/Object/Transparent.png");
        m_ChainHorizontal->SetVisible(true);
        m_ChainHorizontal->SetUsed(false);
        m_ChainHorizontal->SetIfReverse(false);
    }
}

//blink the chain
void App::BlinkChain() {
    if (timer > 0.6) {
        if (switchCount < 3) {
            for (const auto &m_ChainVertical: m_ChainVerticals) {
                if (m_ChainVertical->IfUsed()) {
                    if (switchCount == 0) {
                        m_ChainVertical->SetImage(RESOURCE_DIR"/Image/Object/chainAttackVerticalTemp.png");
                    }
                    else if (switchCount == 1) {
                        m_ChainVertical->SetImage(RESOURCE_DIR"/Image/Object/chainAttackVertical.png");
                    }
                    else if (switchCount == 2){
                        m_ChainVertical->SetImage(RESOURCE_DIR"/Image/Object/Transparent.png");
                    }
                }
            }
            for (const auto &m_ChainHorizontal: m_ChainHorizontals) {
                if (m_ChainHorizontal->IfUsed()) {
                    if (switchCount == 0) {
                        m_ChainHorizontal->SetImage(RESOURCE_DIR"/Image/Object/chainAttackHorizontalTemp.png");
                    }
                    else if (switchCount == 1) {
                        m_ChainHorizontal->SetImage(RESOURCE_DIR"/Image/Object/chainAttackHorizontal.png");
                    }
                    else if (switchCount == 2){
                        m_ChainHorizontal->SetImage(RESOURCE_DIR"/Image/Object/Transparent.png");
                    }
                }
            }

            switchCount++;
            timer = 0;
        }
        else {
            switchCount = 0;
            InitiateBlinkChain();
            ChangeChainPattern();
            FM.AddCycle();
        }
    }
}

void App::IfPlayerTouchChain() {
    for (const auto &m_ChainVertical: m_ChainVerticals) {
        if (m_ChainVertical->GetVisibility() && m_ChainVertical->IfUsed()) {
            if (m_Player->IfCollides(m_ChainVertical) && m_ChainVertical->GetImagePath() == RESOURCE_DIR"/Image/Object/chainAttackVertical.png") {
                DamagePlayer();
                invincibleTime = 0;
                return;
            }
        }
    }
    for (const auto &m_ChainHorizontal: m_ChainHorizontals) {
        if (m_ChainHorizontal->GetVisibility() && m_ChainHorizontal->IfUsed()) {
            if (m_Player->IfCollides(m_ChainHorizontal) && m_ChainHorizontal->GetImagePath() == RESOURCE_DIR"/Image/Object/chainAttackHorizontal.png") {
                DamagePlayer();
                invincibleTime = 0;
                return;
            }
        }
    }
}

void App::IfPlayerTouchSpike() {
    for (const auto &m_SpikeTrap: m_SpikeTraps) {
        if (m_SpikeTrap->GetVisibility()) {
            if (m_Player->IfCollides(m_SpikeTrap)) {
                DamagePlayer();
                invincibleTime = 0;
                return;
            }
        }
    }
}

void App::UpGoingPlayer() {
    float old_x = m_Player->GetPosition().x;
    float old_y = m_Player->GetPosition().y;

    m_Player->SetPosition({old_x, old_y - (1.5 * grid_size * Util::Time::GetDeltaTime())});
}

void App::DamagePlayer() {
    for (const auto &m_Cross: m_Crosses) {
        if (m_Cross->GetVisibility()) {
            continue;
        }
        else {
            m_Cross->SetVisible(true);
            break;
        }
    }

    //if all crosses show up
    if (m_Crosses[3]->GetVisibility()) {
        m_CurrentState = State::START;
    }
}

void App::Healing() {
    for (const auto &m_Cross: m_Crosses) {
        m_Cross->SetVisible(false);
    }
}

void App::ValidState() {
    if (!FM.GetIfSetUP()) {
        ResetBeemo();
        FM.SetBeemo(true);

        switch (FM.GetState()) {
            case 1:
                m_Machines[0]->SetPosition({-280, 0});
                m_Machines[0]->SetVisible(true);
                m_Machines[1]->SetPosition({-280, -140});
                m_Machines[1]->SetVisible(true);
                m_Machines[2]->SetPosition({280, 70});
                m_Machines[2]->SetVisible(true);
                m_Machines[3]->SetPosition({280, -210});
                m_Machines[3]->SetVisible(true);
                break;
            case 2:
                m_Machines[0]->SetPosition({-280, 70});
                m_Machines[0]->SetVisible(true);
                m_Machines[1]->SetPosition({280, -210});
                m_Machines[1]->SetVisible(true);
                m_Machines[2]->SetPosition({280, 0});
                m_Machines[2]->SetVisible(true);
                m_Machines[3]->SetPosition({280, -70});
                m_Machines[3]->SetVisible(true);
                break;
            case 3:
                m_Machines[0]->SetPosition({-280, -70});
                m_Machines[0]->SetVisible(true);
                m_Machines[1]->SetPosition({-280, 70});
                m_Machines[1]->SetVisible(true);
                m_Machines[2]->SetPosition({280, -140});
                m_Machines[2]->SetVisible(true);
                m_Machines[3]->SetPosition({280, -210});
                m_Machines[3]->SetVisible(true);
                break;
            case 4:
                m_Machines[0]->SetPosition({-280, 0});
                m_Machines[0]->SetVisible(true);
                m_Machines[1]->SetPosition({-280, -140});
                m_Machines[1]->SetVisible(true);
                m_Machines[2]->SetPosition({280, 70});
                m_Machines[2]->SetVisible(true);
                m_Machines[3]->SetPosition({280, -140});
                m_Machines[3]->SetVisible(true);
                break;
            default:
                break;
        }
    }
    else {
        bool flag = false;
        for (const auto &m_Machine: m_Machines) {
            if (m_Machine->GetVisibility()) {
                if (m_Machine->GetImagePath() == RESOURCE_DIR"/Image/Object/BEEMOdead.png") {
                    flag = true;
                }
                else {
                    flag = false;
                    break;
                }
            }
        }

        if (flag) {
            ChangeStateImage();
            FM.AddState();
            FM.ResetCycle();
            ResetBeemo();
            FM.SetBeemo(false);
            Healing();
            m_StateImage->SetVisible(false);
        }
    }
}

void App::ResetBeemo() {
    for (const auto &m_Machine: m_Machines) {
        m_Machine->SetImage(RESOURCE_DIR"/Image/Object/BEEMO.png");
        m_Machine->SetPosition({-1000, -1000});
        m_Machine->SetVisible(false);
        m_Machine->ReSetHitCount();
    }
}

void App::ChangeStateImage() {
    if (m_StateImage->GetImagePath() == RESOURCE_DIR"/Image/Character/healthBar/state1_1.png")
        m_StateImage->SetImage(RESOURCE_DIR"/Image/Character/healthBar/state1_2.png");
    else if (m_StateImage->GetImagePath() == RESOURCE_DIR"/Image/Character/healthBar/state1_2.png")
        m_StateImage->SetImage(RESOURCE_DIR"/Image/Character/healthBar/state1_3.png");
    else if (m_StateImage->GetImagePath() == RESOURCE_DIR"/Image/Character/healthBar/state1_3.png")
        m_StateImage->SetImage(RESOURCE_DIR"/Image/Character/healthBar/state1_4.png");
    else if (m_StateImage->GetImagePath() == RESOURCE_DIR"/Image/Character/healthBar/state1_4.png")
        m_StateImage->SetImage(RESOURCE_DIR"/Image/Character/healthBar/state1_5.png");
    else if (m_StateImage->GetImagePath() == RESOURCE_DIR"/Image/Character/healthBar/state1_5.png")
        m_StateImage->SetImage(RESOURCE_DIR"/Image/Character/healthBar/state2_1.png");
    else if (m_StateImage->GetImagePath() == RESOURCE_DIR"/Image/Character/healthBar/state2_1.png")
        m_StateImage->SetImage(RESOURCE_DIR"/Image/Character/healthBar/state2_2.png");
    else if (m_StateImage->GetImagePath() == RESOURCE_DIR"/Image/Character/healthBar/state2_2.png")
        m_StateImage->SetImage(RESOURCE_DIR"/Image/Character/healthBar/state2_3.png");
    else if (m_StateImage->GetImagePath() == RESOURCE_DIR"/Image/Character/healthBar/state2_3.png")
        m_StateImage->SetImage(RESOURCE_DIR"/Image/Character/healthBar/state2_4.png");
    else if (m_StateImage->GetImagePath() == RESOURCE_DIR"/Image/Character/healthBar/state2_4.png")
        m_StateImage->SetImage(RESOURCE_DIR"/Image/Character/healthBar/state2_5.png");
    else if (m_StateImage->GetImagePath() == RESOURCE_DIR"/Image/Character/healthBar/state2_5.png")
        m_StateImage->SetImage(RESOURCE_DIR"/Image/Character/healthBar/state3_1.png");
    else if (m_StateImage->GetImagePath() == RESOURCE_DIR"/Image/Character/healthBar/state3_1.png")
        m_StateImage->SetImage(RESOURCE_DIR"/Image/Character/healthBar/state3_2.png");
    else if (m_StateImage->GetImagePath() == RESOURCE_DIR"/Image/Character/healthBar/state3_2.png")
        m_StateImage->SetImage(RESOURCE_DIR"/Image/Character/healthBar/state3_3.png");
    else if (m_StateImage->GetImagePath() == RESOURCE_DIR"/Image/Character/healthBar/state3_3.png")
        m_StateImage->SetImage(RESOURCE_DIR"/Image/Character/healthBar/state3_4.png");
    else if (m_StateImage->GetImagePath() == RESOURCE_DIR"/Image/Character/healthBar/state3_4.png")
        m_StateImage->SetImage(RESOURCE_DIR"/Image/Character/healthBar/state3_5.png");
    else if (m_StateImage->GetImagePath() == RESOURCE_DIR"/Image/Character/healthBar/state3_5.png")
        m_StateImage->SetImage(RESOURCE_DIR"/Image/Character/healthBar/state4_1.png");
    else if (m_StateImage->GetImagePath() == RESOURCE_DIR"/Image/Character/healthBar/state4_1.png")
        m_StateImage->SetImage(RESOURCE_DIR"/Image/Character/healthBar/state4_2.png");
    else if (m_StateImage->GetImagePath() == RESOURCE_DIR"/Image/Character/healthBar/state4_2.png")
        m_StateImage->SetImage(RESOURCE_DIR"/Image/Character/healthBar/state4_3.png");
    else if (m_StateImage->GetImagePath() == RESOURCE_DIR"/Image/Character/healthBar/state4_3.png")
        m_StateImage->SetImage(RESOURCE_DIR"/Image/Character/healthBar/state4_4.png");
    else if (m_StateImage->GetImagePath() == RESOURCE_DIR"/Image/Character/healthBar/state4_4.png")
        m_StateImage->SetImage(RESOURCE_DIR"/Image/Character/healthBar/state4_5.png");
}