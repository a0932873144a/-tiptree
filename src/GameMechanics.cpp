//
// Created by 翁廷豪 on 2024/3/11.
//

#include "GameMechanics.hpp"
#include "Util/Input.hpp"
#include "App.hpp"

//Move(the character you want to control)
void App::Move(const std::shared_ptr<Character>& player) const{
    std::shared_ptr<Character> tempPtr = std::make_shared<Character>(RESOURCE_DIR"/Image/Character/player.png");
    std::shared_ptr<Character> collidtion;
    if (Util::Input::IsKeyDown(Util::Keycode::A)) {
        tempPtr->SetPosition({player->GetPosition().x - grid_size, player->GetPosition().y});
        collidtion = tempPtr->IfCollideSomething(m_CollideObjects);
        if (collidtion == nullptr) {
            player->SetPosition({player->GetPosition().x - grid_size, player->GetPosition().y});
            m_StepText->ShowLeftStep();
        }
        else if (collidtion->GetTag() == Character::Tag::Boundary) {
            tempPtr.reset();
            collidtion.reset();
            return;
        }
        else if (collidtion->GetTag() == Character::Tag::Enemy) {
            Push(player, collidtion, 'A');
            m_StepText->ShowLeftStep();
        }
        else if (collidtion->GetTag() == Character::Tag::Rock) {
            Push(player, collidtion, 'A');
            m_StepText->ShowLeftStep();
        }
        else {
            player->SetPosition({player->GetPosition().x - grid_size, player->GetPosition().y});
            m_StepText->ShowLeftStep();
        }
        tempPtr.reset();
        collidtion.reset();
        return;
    }

    if (Util::Input::IsKeyDown(Util::Keycode::D)) {
        tempPtr->SetPosition({player->GetPosition().x + grid_size, player->GetPosition().y});
        collidtion = tempPtr->IfCollideSomething(m_CollideObjects);
        if (collidtion == nullptr) {
            player->SetPosition({player->GetPosition().x + grid_size, player->GetPosition().y});
            m_StepText->ShowLeftStep();
        }
        else if (collidtion->GetTag() == Character::Tag::Boundary) {
            tempPtr.reset();
            collidtion.reset();
            return;
        }
        else if (collidtion->GetTag() == Character::Tag::Enemy) {
            Push(player, collidtion, 'D');
            m_StepText->ShowLeftStep();
        }
        else if (collidtion->GetTag() == Character::Tag::Rock) {
            Push(player, collidtion, 'D');
            m_StepText->ShowLeftStep();
        }
        else {
            player->SetPosition({player->GetPosition().x + grid_size, player->GetPosition().y});
            m_StepText->ShowLeftStep();
        }
        tempPtr.reset();
        collidtion.reset();
        return;
    }

    if (Util::Input::IsKeyDown(Util::Keycode::S)) {
        tempPtr->SetPosition({player->GetPosition().x, player->GetPosition().y - grid_size});
        collidtion = tempPtr->IfCollideSomething(m_CollideObjects);
        if (collidtion == nullptr) {
            player->SetPosition({player->GetPosition().x, player->GetPosition().y - grid_size});
            m_StepText->ShowLeftStep();
        }
        else if (collidtion->GetTag() == Character::Tag::Boundary) {
            tempPtr.reset();
            collidtion.reset();
            return;
        }
        else if (collidtion->GetTag() == Character::Tag::Enemy) {
            Push(player, collidtion, 'S');
            m_StepText->ShowLeftStep();
        }
        else if (collidtion->GetTag() == Character::Tag::Rock) {
            Push(player, collidtion, 'S');
            m_StepText->ShowLeftStep();
        }
        else {
            player->SetPosition({player->GetPosition().x, player->GetPosition().y - grid_size});
            m_StepText->ShowLeftStep();
        }
        tempPtr.reset();
        collidtion.reset();
        return;
    }

    if (Util::Input::IsKeyDown(Util::Keycode::W)) {
        tempPtr->SetPosition({player->GetPosition().x, player->GetPosition().y + grid_size});
        collidtion = tempPtr->IfCollideSomething(m_CollideObjects);
        if (collidtion == nullptr) {
            player->SetPosition({player->GetPosition().x, player->GetPosition().y + grid_size});
            m_StepText->ShowLeftStep();
        }
        else if (collidtion->GetTag() == Character::Tag::Boundary) {
            tempPtr.reset();
            collidtion.reset();
            return;
        }
        else if (collidtion->GetTag() == Character::Tag::Enemy || collidtion->GetTag() == Character::Tag::Rock) {
            Push(player, collidtion, 'W');
            m_StepText->ShowLeftStep();
        }
        else {
            player->SetPosition({player->GetPosition().x, player->GetPosition().y + grid_size});
            m_StepText->ShowLeftStep();
        }
        tempPtr.reset();
        collidtion.reset();
        return;
    }

    tempPtr.reset();
}

//make character push other object
//Push(the one pushes, the other being pushed)
void App::Push(const std::shared_ptr<Character>& player, const std::shared_ptr<Character>& other, char direction) const{
    std::shared_ptr<Character> tempPtr = std::make_shared<Character>(RESOURCE_DIR"/Image/Character/player.png");
    std::shared_ptr<Character> collidtion;
    player->SetLastTouched(other->GetTag());
    switch (direction) {
        case 'A':
            tempPtr->SetPosition({other->GetPosition().x - grid_size, other->GetPosition().y});
            collidtion = tempPtr->IfCollideSomething(m_CollideObjects);
            if (collidtion == nullptr) {
                other->SetPosition({other->GetPosition().x - grid_size, other->GetPosition().y});
            }
            else if (collidtion->GetTag() == Character::Tag::Boss) {

            }
            else if (collidtion->GetTag() == Character::Tag::Boundary) {
                if (other->GetTag() == Character::Tag::Enemy) {
                    CrushEnemy(other);
                }
            }
            else if (collidtion->GetTag() == Character::Tag::Enemy) {
                if (other->GetTag() == Character::Tag::Enemy) {
                    CrushEnemy(other);
                }
            }
            else if (collidtion->GetTag() == Character::Tag::Rock) {
                if (other->GetTag() == Character::Tag::Enemy) {
                    CrushEnemy(other);
                }
            }
            else {
                other->SetPosition({other->GetPosition().x - grid_size, other->GetPosition().y});
            }
            tempPtr.reset();
            collidtion.reset();
            break;
        case 'D':
            tempPtr->SetPosition({other->GetPosition().x + grid_size, other->GetPosition().y});
            collidtion = tempPtr->IfCollideSomething(m_CollideObjects);
            if (collidtion == nullptr) {
                other->SetPosition({other->GetPosition().x + grid_size, other->GetPosition().y});
            }
            else if (collidtion->GetTag() == Character::Tag::Boss) {

            }
            else if (collidtion->GetTag() == Character::Tag::Boundary) {
                if (other->GetTag() == Character::Tag::Enemy) {
                    CrushEnemy(other);
                }
            }
            else if (collidtion->GetTag() == Character::Tag::Enemy) {
                if (other->GetTag() == Character::Tag::Enemy) {
                    CrushEnemy(other);
                }
            }
            else if (collidtion->GetTag() == Character::Tag::Rock) {
                if (other->GetTag() == Character::Tag::Enemy) {
                    CrushEnemy(other);
                }
            }
            else {
                other->SetPosition({other->GetPosition().x + grid_size, other->GetPosition().y});
            }
            tempPtr.reset();
            collidtion.reset();
            break;
        case 'S':
            tempPtr->SetPosition({other->GetPosition().x, other->GetPosition().y - grid_size});
            collidtion = tempPtr->IfCollideSomething(m_CollideObjects);
            if (collidtion == nullptr) {
                other->SetPosition({other->GetPosition().x, other->GetPosition().y - grid_size});
            }
            else if (collidtion->GetTag() == Character::Tag::Boss) {

            }
            else if (collidtion->GetTag() == Character::Tag::Boundary) {
                if (other->GetTag() == Character::Tag::Enemy) {
                    CrushEnemy(other);
                }
            }
            else if (collidtion->GetTag() == Character::Tag::Enemy) {
                if (other->GetTag() == Character::Tag::Enemy) {
                    CrushEnemy(other);
                }
            }
            else if (collidtion->GetTag() == Character::Tag::Rock) {
                if (other->GetTag() == Character::Tag::Enemy) {
                    CrushEnemy(other);
                }
            }
            else {
                other->SetPosition({other->GetPosition().x, other->GetPosition().y - grid_size});
            }
            tempPtr.reset();
            collidtion.reset();
            break;
        case 'W':
            tempPtr->SetPosition({other->GetPosition().x, other->GetPosition().y + grid_size});
            collidtion = tempPtr->IfCollideSomething(m_CollideObjects);
            if (collidtion == nullptr) {
                other->SetPosition({other->GetPosition().x, other->GetPosition().y + grid_size});
            }
            else if (collidtion->GetTag() == Character::Tag::Boss) {

            }
            else if (collidtion->GetTag() == Character::Tag::Boundary) {
                if (other->GetTag() == Character::Tag::Enemy) {
                    CrushEnemy(other);
                }
            }
            else if (collidtion->GetTag() == Character::Tag::Enemy) {
                if (other->GetTag() == Character::Tag::Enemy) {
                    CrushEnemy(other);
                }
            }
            else if (collidtion->GetTag() == Character::Tag::Rock) {
                if (other->GetTag() == Character::Tag::Enemy) {
                    CrushEnemy(other);
                }
            }
            else {
                other->SetPosition({other->GetPosition().x, other->GetPosition().y + grid_size});
            }
            tempPtr.reset();
            collidtion.reset();
            break;
        default:
            break;
    }
}

//Check if phase is passed
bool App::IsPhasePassed() {
    if (m_Player->IfCollides(m_Boss)) {
        if (m_Player->GetVisibility() && m_Boss->GetVisibility()) {
            return true;
        }
    }
    else {
        return false;
    }
}

//Check if phase3 is passed, phase3 is special because of mutiple bosses
bool App::IsPhase3Passed() {
    if (m_Player->IfCollides(m_Bosses[0])) {
        if (m_Player->GetVisibility() && m_Bosses[0]->GetVisibility()) {
            return true;
        }
    }
    else {
        return false;
    }
}

//if the player step into a trap, the step text will reduce 1
void App::StepIntoTrap(const std::shared_ptr<Character>& player, const std::shared_ptr<Character>& trap) {
    if (player->IfCollides(trap) && trap->GetVisibility()) {
        player->SetLastTouched(trap->GetTag());
        m_StepText->ShowLeftStep();
    }
}

//if the player get the key, the key will disappear
void App::GetKey(const std::shared_ptr<Character>& player, const std::shared_ptr<Character>& key) {
    if (player->IfCollides(key)) {
        player->SetLastTouched(key->GetTag());
        key->SetVisible(false);
    }
}