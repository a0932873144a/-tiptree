//
// Created by 翁廷豪 on 2024/3/11.
//

#include "GameMechanics.hpp"
#include "Util/Input.hpp"
#include "App.hpp"

//TODO: if there is something behind the rock, then it can't be pushed (you can't push rock to crush enemy)
//make character move
//Move(the character you want to control)
void App::Move(const std::shared_ptr<Character>& other) const{
    if (Util::Input::IsKeyDown(Util::Keycode::A)) {
        m_StepText->ShowLeftStep();
        other->SetPosition({other->GetPosition().x - grid_size, other->GetPosition().y});
    }

    if (Util::Input::IsKeyDown(Util::Keycode::D)) {
        m_StepText->ShowLeftStep();
        other->SetPosition({other->GetPosition().x + grid_size, other->GetPosition().y});
    }

    if (Util::Input::IsKeyDown(Util::Keycode::S)) {
        m_StepText->ShowLeftStep();
        other->SetPosition({other->GetPosition().x, other->GetPosition().y - grid_size});
    }

    if (Util::Input::IsKeyDown(Util::Keycode::W)) {
        m_StepText->ShowLeftStep();
        other->SetPosition({other->GetPosition().x, other->GetPosition().y + grid_size});
    }
}

//make character push other object
//Push(the one pushes, the other being pushed)
void App::Push(const std::shared_ptr<Character>& player, const std::shared_ptr<Character>& other) const{
    if (player->IfCollides(other)){
        switch (player->MoveDirection(other)) {
            case 'A':
                player->SetPosition({player->GetPosition().x + grid_size, player->GetPosition().y});
                other->SetPosition({other->GetPosition().x - grid_size, other->GetPosition().y});
                break;
            case 'D':
                player->SetPosition({player->GetPosition().x - grid_size, player->GetPosition().y});
                other->SetPosition({other->GetPosition().x + grid_size, other->GetPosition().y});
                break;
            case 'S':
                player->SetPosition({player->GetPosition().x, player->GetPosition().y + grid_size});
                other->SetPosition({other->GetPosition().x, other->GetPosition().y - grid_size});
                break;
            case 'W':
                player->SetPosition({player->GetPosition().x, player->GetPosition().y - grid_size});
                other->SetPosition({other->GetPosition().x, other->GetPosition().y + grid_size});
                break;
            default:
                break;
        }
    }
}

//make character hit the boundaries and get back
//HitBoundaryGetBack(the character you want to keep it on the table)
void App::HitBoundaryGetBack(const std::shared_ptr<Character>& ptr, const std::shared_ptr<Character>& boundary) const{
    if (ptr->IfCollides(boundary)) {
        switch (ptr->MoveDirection(boundary)) {
            case 'A':
                ptr->SetPosition({ptr->GetPosition().x + grid_size, ptr->GetPosition().y});
                break;
            case 'D':
                ptr->SetPosition({ptr->GetPosition().x - grid_size, ptr->GetPosition().y});
                break;
            case 'S':
                ptr->SetPosition({ptr->GetPosition().x, ptr->GetPosition().y + grid_size});
                break;
            case 'W':
                ptr->SetPosition({ptr->GetPosition().x, ptr->GetPosition().y - grid_size});
                break;
            default:
                break;
        }
    }
}

//if the player let an enemy crash something, the enemy will die
//CrushEnemy(the enemy, something being hit)
void App::CrushEnemy(const std::shared_ptr<Character>& enemy, const std::shared_ptr<Character>& other) {
    if (enemy->IfCollides(other)) {
        enemy->SetVisible(false);
        enemy->SetPosition({-1000, -1000});
    }
}

bool App::IsPhase1Passed() {
    if (m_Player->GetPosition().x + 70 >= m_Boss1->GetPosition().x && m_Player->GetPosition().y - 20 <= m_Boss1->GetPosition().y) {
        return true;
    }
    else {
        return false;
    }
}