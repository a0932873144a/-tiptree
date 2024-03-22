//
// Created by 翁廷豪 on 2024/3/11.
//

#include "GameMechanics.hpp"
#include "Util/Input.hpp"
#include "App.hpp"

//TODO: if there is something behind the rock, then it can't be pushed (you can't push rock to crush enemy)
//TODO: if enemy is pushed to boundary, it will be crush too
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
        switch (player->PushDirection(other)) {
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


//make character hit the boundaries
//HitBoundary(the character you want to keep it on the table)
void App::HitBoundary(const std::shared_ptr<Character>& other) const{

    if (other->IfCollides(m_BoundaryL1))
        other->SetPosition({other->GetPosition().x + grid_size, other->GetPosition().y});
    if (other->IfCollides(m_BoundaryL2))
        other->SetPosition({other->GetPosition().x + grid_size, other->GetPosition().y});
    if (other->IfCollides(m_BoundaryL3))
        other->SetPosition({other->GetPosition().x + grid_size, other->GetPosition().y});
    if (other->IfCollides(m_BoundaryL4))
        other->SetPosition({other->GetPosition().x + grid_size, other->GetPosition().y});
    if (other->IfCollides(m_BoundaryL5))
        other->SetPosition({other->GetPosition().x + grid_size, other->GetPosition().y});


    if (other->IfCollides(m_BoundaryR1))
        other->SetPosition({other->GetPosition().x - grid_size, other->GetPosition().y});
    if (other->IfCollides(m_BoundaryR2))
        other->SetPosition({other->GetPosition().x - grid_size, other->GetPosition().y});
    if (other->IfCollides(m_BoundaryR3))
        other->SetPosition({other->GetPosition().x - grid_size, other->GetPosition().y});
    if (other->IfCollides(m_BoundaryR5))
        other->SetPosition({other->GetPosition().x - grid_size, other->GetPosition().y});
    if (other->IfCollides(m_BoundaryR6))
        other->SetPosition({other->GetPosition().x - grid_size, other->GetPosition().y});

    if (other->IfCollides(m_BoundaryT1))
        other->SetPosition({other->GetPosition().x, other->GetPosition().y - grid_size});
    if (other->IfCollides(m_BoundaryT2))
        other->SetPosition({other->GetPosition().x, other->GetPosition().y - grid_size});
    if (other->IfCollides(m_BoundaryT3))
        other->SetPosition({other->GetPosition().x, other->GetPosition().y - grid_size});
    if (other->IfCollides(m_BoundaryT4))
        other->SetPosition({other->GetPosition().x, other->GetPosition().y - grid_size});
    if (other->IfCollides(m_BoundaryT5))
        other->SetPosition({other->GetPosition().x, other->GetPosition().y - grid_size});
    if (other->IfCollides(m_BoundaryR4))
        other->SetPosition({other->GetPosition().x, other->GetPosition().y - grid_size});


    if (other->IfCollides(m_BoundaryB1))
        other->SetPosition({other->GetPosition().x, other->GetPosition().y + grid_size});
    if (other->IfCollides(m_BoundaryB2))
        other->SetPosition({other->GetPosition().x, other->GetPosition().y + grid_size});
    if (other->IfCollides(m_BoundaryB3))
        other->SetPosition({other->GetPosition().x, other->GetPosition().y + grid_size});
    if (other->IfCollides(m_BoundaryB4))
        other->SetPosition({other->GetPosition().x, other->GetPosition().y + grid_size});
    if (other->IfCollides(m_BoundaryB5))
        other->SetPosition({other->GetPosition().x, other->GetPosition().y + grid_size});
    if (other->IfCollides(m_BoundaryB6))
        other->SetPosition({other->GetPosition().x, other->GetPosition().y + grid_size});
    if (other->IfCollides(m_BoundaryB7))
        other->SetPosition({other->GetPosition().x, other->GetPosition().y + grid_size});


}

//TODO: make CrushEnemy really delete the object
//if the player let an enemy crash something, the enemy will die
//CrushEnemy(the enemy, something being hit)
void App::CrushEnemy(const std::shared_ptr<Character>& enemy, const std::shared_ptr<Character>& other) const{
    if (enemy->IfCollides(other)) {
        enemy->SetVisible(false);
        enemy->SetPosition({-1000, -1000});
    }
}
