//
// Created by 翁廷豪 on 2024/3/11.
//

#include "GameMechanics.hpp"
#include "Util/Input.hpp"
#include "App.hpp"

//Move(the character you want to control)
void App::Move(const std::shared_ptr<Character>& player) const{
    IsEnemyHitTrap();

    std::shared_ptr<Character> tempPtr = std::make_shared<Character>(RESOURCE_DIR"/Image/Character/player.png");
    std::shared_ptr<Character> collidtion;

    if (Util::Input::IsKeyDown(Util::Keycode::A)) {
        tempPtr->SetPosition({player->GetPosition().x - grid_size, player->GetPosition().y});
        collidtion = tempPtr->IfCollideSomething(m_CollideObjects);

        if (collidtion == nullptr) {
            ChangeSpikeTrap();
            player->SetLastTouched(Character::Tag::Null);
            player->SetPosition({player->GetPosition().x - grid_size, player->GetPosition().y});
            m_StepText->ShowLeftStep();
        }
        else if (collidtion->GetTag() == Character::Tag::Boundary || collidtion->GetTag() == Character::Tag::LaserMech) {
            player->SetLastTouched(collidtion->GetTag());
            tempPtr.reset();
            collidtion.reset();
            return;
        }
        else if (collidtion->GetTag() == Character::Tag::Chest) {
            player->SetLastTouched(collidtion->GetTag());
            if (m_Key->GetVisibility()) {
                if (player->GetLastTouched() == Character::Tag::SpikeTrap) {
                    ChangeSpikeTrap();
                    m_StepText->ShowLeftStep();
                    player->SetLastTouched(Character::Tag::Null);
                }
                tempPtr.reset();
                collidtion.reset();
                return;
            }
            else {
                ChangeSpikeTrap();
                collidtion->SetVisible(false);
                collidtion->SetPosition({-1000, -1000});
                player->SetPosition({player->GetPosition().x - grid_size, player->GetPosition().y});
                m_StepText->ShowLeftStep();
            }
        }
        else if (collidtion->GetTag() == Character::Tag::Key) {
            if (collidtion->GetVisibility()) {
                ChangeSpikeTrap();
                player->SetLastTouched(collidtion->GetTag());
                GetKey(collidtion);
                player->SetPosition({player->GetPosition().x - grid_size, player->GetPosition().y});
                m_StepText->ShowLeftStep();
            }
        }
        else if (collidtion->GetTag() == Character::Tag::SpikeTrap) {
            ChangeSpikeTrap();
            player->SetPosition({player->GetPosition().x - grid_size, player->GetPosition().y});
            m_StepText->ShowLeftStep();
            if (collidtion->GetVisibility()) {
                player->SetLastTouched(collidtion->GetTag());
                m_StepText->ShowLeftStep();
            }
        }
        else if (collidtion->GetTag() == Character::Tag::Enemy) {
            ChangeSpikeTrap();
            if (player->GetLastTouched() == Character::Tag::SpikeTrap) {
                m_StepText->ShowLeftStep();
                player->SetLastTouched(Character::Tag::Null);
            }
            player->SetLastTouched(collidtion->GetTag());
            Push(player, collidtion, 'A');
            m_StepText->ShowLeftStep();
        }
        else if (collidtion->GetTag() == Character::Tag::Rock) {
            ChangeSpikeTrap();
            if (player->GetLastTouched() == Character::Tag::SpikeTrap) {
                m_StepText->ShowLeftStep();
                player->SetLastTouched(Character::Tag::Null);
            }
            player->SetLastTouched(collidtion->GetTag());
            Push(player, collidtion, 'A');
            m_StepText->ShowLeftStep();
        }
        else {
            ChangeSpikeTrap();
            player->SetLastTouched(collidtion->GetTag());
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
            ChangeSpikeTrap();
            player->SetLastTouched(Character::Tag::Null);
            player->SetPosition({player->GetPosition().x + grid_size, player->GetPosition().y});
            m_StepText->ShowLeftStep();
        }
        else if (collidtion->GetTag() == Character::Tag::Boundary) {
            player->SetLastTouched(collidtion->GetTag());
            tempPtr.reset();
            collidtion.reset();
            return;
        }
        else if (collidtion->GetTag() == Character::Tag::Chest) {
            player->SetLastTouched(collidtion->GetTag());
            if (m_Key->GetVisibility()) {
                if (player->GetLastTouched() == Character::Tag::SpikeTrap) {
                    m_StepText->ShowLeftStep();
                    player->SetLastTouched(Character::Tag::Null);
                }
                tempPtr.reset();
                collidtion.reset();
                return;
            }
            else {
                ChangeSpikeTrap();
                collidtion->SetVisible(false);
                player->SetPosition({player->GetPosition().x + grid_size, player->GetPosition().y});
                m_StepText->ShowLeftStep();
            }
        }
        else if (collidtion->GetTag() == Character::Tag::Key && collidtion->GetVisibility()) {
            if (collidtion->GetVisibility()) {
                ChangeSpikeTrap();
                player->SetLastTouched(collidtion->GetTag());
                GetKey(collidtion);
                player->SetPosition({player->GetPosition().x + grid_size, player->GetPosition().y});
                m_StepText->ShowLeftStep();
            }
        }
        else if (collidtion->GetTag() == Character::Tag::SpikeTrap) {
            ChangeSpikeTrap();
            player->SetPosition({player->GetPosition().x + grid_size, player->GetPosition().y});
            m_StepText->ShowLeftStep();
            if (collidtion->GetVisibility()) {
                player->SetLastTouched(collidtion->GetTag());
                m_StepText->ShowLeftStep();
            }
        }
        else if (collidtion->GetTag() == Character::Tag::Enemy) {
            ChangeSpikeTrap();
            if (player->GetLastTouched() == Character::Tag::SpikeTrap) {
                m_StepText->ShowLeftStep();
                player->SetLastTouched(Character::Tag::Null);
            }
            player->SetLastTouched(collidtion->GetTag());
            Push(player, collidtion, 'D');
            m_StepText->ShowLeftStep();
        }
        else if (collidtion->GetTag() == Character::Tag::Rock) {
            ChangeSpikeTrap();
            if (player->GetLastTouched() == Character::Tag::SpikeTrap) {
                m_StepText->ShowLeftStep();
                player->SetLastTouched(Character::Tag::Null);
            }
            player->SetLastTouched(collidtion->GetTag());
            Push(player, collidtion, 'D');
            m_StepText->ShowLeftStep();
        }
        else {
            ChangeSpikeTrap();
            player->SetLastTouched(collidtion->GetTag());
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
            ChangeSpikeTrap();
            player->SetLastTouched(Character::Tag::Null);
            player->SetPosition({player->GetPosition().x, player->GetPosition().y - grid_size});
            m_StepText->ShowLeftStep();
        }
        else if (collidtion->GetTag() == Character::Tag::Boundary) {
            player->SetLastTouched(collidtion->GetTag());
            tempPtr.reset();
            collidtion.reset();
            return;
        }
        else if (collidtion->GetTag() == Character::Tag::Chest) {
            player->SetLastTouched(collidtion->GetTag());
            if (m_Key->GetVisibility()) {
                if (player->GetLastTouched() == Character::Tag::SpikeTrap) {
                    m_StepText->ShowLeftStep();
                    player->SetLastTouched(Character::Tag::Null);
                }
                tempPtr.reset();
                collidtion.reset();
                return;
            }
            else {
                ChangeSpikeTrap();
                collidtion->SetVisible(false);
                player->SetPosition({player->GetPosition().x, player->GetPosition().y - grid_size});
                m_StepText->ShowLeftStep();
            }
        }
        else if (collidtion->GetTag() == Character::Tag::Key && collidtion->GetVisibility()) {
            if (collidtion->GetVisibility()) {
                ChangeSpikeTrap();
                player->SetLastTouched(collidtion->GetTag());
                GetKey(collidtion);
                player->SetPosition({player->GetPosition().x, player->GetPosition().y - grid_size});
                m_StepText->ShowLeftStep();
            }
        }
        else if (collidtion->GetTag() == Character::Tag::SpikeTrap) {
            ChangeSpikeTrap();
            player->SetPosition({player->GetPosition().x, player->GetPosition().y - grid_size});
            m_StepText->ShowLeftStep();
            if (collidtion->GetVisibility()) {
                player->SetLastTouched(collidtion->GetTag());
                m_StepText->ShowLeftStep();
            }
        }
        else if (collidtion->GetTag() == Character::Tag::Enemy) {
            ChangeSpikeTrap();
            if (player->GetLastTouched() == Character::Tag::SpikeTrap) {
                m_StepText->ShowLeftStep();
                player->SetLastTouched(Character::Tag::Null);
            }
            player->SetLastTouched(collidtion->GetTag());
            Push(player, collidtion, 'S');
            m_StepText->ShowLeftStep();
        }
        else if (collidtion->GetTag() == Character::Tag::Rock) {
            ChangeSpikeTrap();
            if (player->GetLastTouched() == Character::Tag::SpikeTrap) {
                m_StepText->ShowLeftStep();
                player->SetLastTouched(Character::Tag::Null);
            }
            player->SetLastTouched(collidtion->GetTag());
            Push(player, collidtion, 'S');
            m_StepText->ShowLeftStep();
        }
        else {
            ChangeSpikeTrap();
            player->SetLastTouched(collidtion->GetTag());
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
            ChangeSpikeTrap();
            player->SetLastTouched(Character::Tag::Null);
            player->SetPosition({player->GetPosition().x, player->GetPosition().y + grid_size});
            m_StepText->ShowLeftStep();
        }
        else if (collidtion->GetTag() == Character::Tag::Boundary) {
            player->SetLastTouched(collidtion->GetTag());
            tempPtr.reset();
            collidtion.reset();
            return;
        }
        else if (collidtion->GetTag() == Character::Tag::Chest) {
            player->SetLastTouched(collidtion->GetTag());
            if (m_Key->GetVisibility()) {
                if (player->GetLastTouched() == Character::Tag::SpikeTrap) {
                    m_StepText->ShowLeftStep();
                    player->SetLastTouched(Character::Tag::Null);
                }
                tempPtr.reset();
                collidtion.reset();
                return;
            }
            else {
                ChangeSpikeTrap();
                collidtion->SetVisible(false);
                player->SetPosition({player->GetPosition().x, player->GetPosition().y + grid_size});
                m_StepText->ShowLeftStep();
            }
        }
        else if (collidtion->GetTag() == Character::Tag::Key && collidtion->GetVisibility()) {
            if (collidtion->GetVisibility()) {
                ChangeSpikeTrap();
                player->SetLastTouched(collidtion->GetTag());
                GetKey(collidtion);
                player->SetPosition({player->GetPosition().x, player->GetPosition().y + grid_size});
                m_StepText->ShowLeftStep();
            }
        }
        else if (collidtion->GetTag() == Character::Tag::SpikeTrap) {
            ChangeSpikeTrap();
            player->SetPosition({player->GetPosition().x, player->GetPosition().y + grid_size});
            m_StepText->ShowLeftStep();
            if (collidtion->GetVisibility()) {
                player->SetLastTouched(collidtion->GetTag());
                m_StepText->ShowLeftStep();
            }
        }
        else if (collidtion->GetTag() == Character::Tag::Enemy || collidtion->GetTag() == Character::Tag::Rock) {
            ChangeSpikeTrap();
            if (player->GetLastTouched() == Character::Tag::SpikeTrap) {
                m_StepText->ShowLeftStep();
                player->SetLastTouched(Character::Tag::Null);
            }
            player->SetLastTouched(collidtion->GetTag());
            Push(player, collidtion, 'W');
            m_StepText->ShowLeftStep();
        }
        else {
            ChangeSpikeTrap();
            player->SetLastTouched(collidtion->GetTag());
            player->SetPosition({player->GetPosition().x, player->GetPosition().y + grid_size});
            m_StepText->ShowLeftStep();
        }

        tempPtr.reset();
        collidtion.reset();
        return;
    }

    tempPtr.reset();
    collidtion.reset();
}

//make character push other object
//Push(the one pushes, the other being pushed)
void App::Push(const std::shared_ptr<Character>& player, const std::shared_ptr<Character>& other, char direction) const{
    std::shared_ptr<Character> tempPtr = std::make_shared<Character>(RESOURCE_DIR"/Image/Character/player.png");
    std::shared_ptr<Character> collidtion;
    switch (direction) {
        case 'A':
            tempPtr->SetPosition({other->GetPosition().x - grid_size, other->GetPosition().y});
            collidtion = tempPtr->IfCollideSomething(m_CollideObjects);
            if (collidtion == nullptr) {
                other->SetPosition({other->GetPosition().x - grid_size, other->GetPosition().y});
            }
            else if (collidtion->GetTag() == Character::Tag::Boss) {

            }
            else if (collidtion->GetTag() == Character::Tag::Chest && collidtion->GetVisibility()) {

            }
            else if (collidtion->GetTag() == Character::Tag::Boundary) {
                other->SetLastTouched(collidtion->GetTag());
                if (other->GetTag() == Character::Tag::Enemy) {
                    CrushEnemy(other);
                }
            }
            else if (collidtion->GetTag() == Character::Tag::Enemy) {
                other->SetLastTouched(collidtion->GetTag());
                if (other->GetTag() == Character::Tag::Enemy) {
                    CrushEnemy(other);
                }
            }
            else if (collidtion->GetTag() == Character::Tag::Rock) {
                other->SetLastTouched(collidtion->GetTag());
                if (other->GetTag() == Character::Tag::Enemy) {
                    CrushEnemy(other);
                }
            }
            else {
                other->SetLastTouched(collidtion->GetTag());
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
            else if (collidtion->GetTag() == Character::Tag::Chest && collidtion->GetVisibility()) {

            }
            else if (collidtion->GetTag() == Character::Tag::Boundary) {
                other->SetLastTouched(collidtion->GetTag());
                if (other->GetTag() == Character::Tag::Enemy) {
                    CrushEnemy(other);
                }
            }
            else if (collidtion->GetTag() == Character::Tag::Enemy) {
                other->SetLastTouched(collidtion->GetTag());
                if (other->GetTag() == Character::Tag::Enemy) {
                    CrushEnemy(other);
                }
            }
            else if (collidtion->GetTag() == Character::Tag::Rock) {
                other->SetLastTouched(collidtion->GetTag());
                if (other->GetTag() == Character::Tag::Enemy) {
                    CrushEnemy(other);
                }
            }
            else {
                other->SetLastTouched(collidtion->GetTag());
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
            else if (collidtion->GetTag() == Character::Tag::Chest && collidtion->GetVisibility()) {

            }
            else if (collidtion->GetTag() == Character::Tag::Boundary) {
                other->SetLastTouched(collidtion->GetTag());
                if (other->GetTag() == Character::Tag::Enemy) {
                    CrushEnemy(other);
                }
            }
            else if (collidtion->GetTag() == Character::Tag::Enemy) {
                other->SetLastTouched(collidtion->GetTag());
                if (other->GetTag() == Character::Tag::Enemy) {
                    CrushEnemy(other);
                }
            }
            else if (collidtion->GetTag() == Character::Tag::Rock) {
                other->SetLastTouched(collidtion->GetTag());
                if (other->GetTag() == Character::Tag::Enemy) {
                    CrushEnemy(other);
                }
            }
            else {
                other->SetLastTouched(collidtion->GetTag());
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
            else if (collidtion->GetTag() == Character::Tag::Chest && collidtion->GetVisibility()) {

            }
            else if (collidtion->GetTag() == Character::Tag::Boundary) {
                other->SetLastTouched(collidtion->GetTag());
                if (other->GetTag() == Character::Tag::Enemy) {
                    CrushEnemy(other);
                }
            }
            else if (collidtion->GetTag() == Character::Tag::Enemy) {
                other->SetLastTouched(collidtion->GetTag());
                if (other->GetTag() == Character::Tag::Enemy) {
                    CrushEnemy(other);
                }
            }
            else if (collidtion->GetTag() == Character::Tag::Rock) {
                other->SetLastTouched(collidtion->GetTag());
                if (other->GetTag() == Character::Tag::Enemy) {
                    CrushEnemy(other);
                }
            }
            else {
                other->SetLastTouched(collidtion->GetTag());
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
    return false;
}

//Check if phase3 is passed, phase3 is special because of mutiple bosses
bool App::IsPhase3Passed() {
    if (m_Player->IfCollides(m_Bosses[0])) {
        if (m_Player->GetVisibility() && m_Bosses[0]->GetVisibility()) {
            return true;
        }
    }
    return false;
}

//If enemy crash trap, it dies.
void App::IsEnemyHitTrap() const {
    for (const auto& enemy : m_Enemies) {
        for (const auto& spike : m_SpikeTraps) {
            if (enemy->IfCollides(spike)) {
                CrushEnemy(enemy);
            }
        }
    }
}

//change moving spike trap
void App::ChangeSpikeTrap() const {
    if (m_Phase == Phase::Phase5 || m_Phase == Phase::Phase6 || m_Phase == Phase::Phase7) {
        for (const auto& spike : m_SpikeTraps) {
            if (spike->GetVisibility()) {
                spike->SetVisible(false);
            }
            else {
                spike->SetVisible(true);
            }
        }
    }
}

//detect if laser hit someting

//laserRight
void App::ShootLaserR(const std::shared_ptr<Character>& laserMech) {

}

//laserLeft
void App::ShootLaserL(const std::shared_ptr<Character> &laserMech) {
    int laserCount = 0;
    bool collisionDetected = false;

    //清除以前的laser
    if (!laserMech->IfUsedLaserEmpty()) {
        std::vector<int> index = laserMech->GetUsedLaserIndex();
        for (auto &i : index) {
            m_LaserLs[i]->SetPosition({-1000, -1000});
            m_LaserLs[i]->SetVisible(false);
            m_LaserLs[i]->SetUsed(false);
        }
        //清空laser列表
        laserMech->ResetUsedLaserIndex();
    }

    //分配laser
    while (!collisionDetected) {
        auto tempPtr = std::make_shared<Character>(RESOURCE_DIR"/Image/Object/laserBeamL.png");
        tempPtr->SetPosition({laserMech->GetPosition().x - (grid_size * (laserCount + 1)), laserMech->GetPosition().y});
        auto collidtion = tempPtr->IfCollideSomething(m_CollideObjects);
        if (collidtion == nullptr) {
            for (int i = 0; i < m_LaserLs.size(); ++i) {
                if (!m_LaserLs[i]->IfUsed()) {
                    m_LaserLs[i]->SetUsed(true);
                    laserMech->SetUsedLaserIndex(i);
                }
            }
            laserCount++;
        }
        else if (collidtion->GetTag() == Character::Tag::Boundary || collidtion->GetTag() == Character::Tag::Rock) {
            collisionDetected = true;
        }
    }
}

//laserTop
void App::ShootLaserT(const std::shared_ptr<Character>& laserMech) {

}

//laserDown
void App::ShootLaserB(const std::shared_ptr<Character>& laserMech) {

}

//Move(the character you want to control)
void App::MoveEx(const std::shared_ptr<Character>& player) {
    std::shared_ptr<Character> tempPtr = std::make_shared<Character>(RESOURCE_DIR"/Image/Character/player.png");
    std::shared_ptr<Character> collidtion;

    if (Util::Input::IsKeyDown(Util::Keycode::A)) {
        tempPtr->SetPosition({player->GetPosition().x - grid_size, player->GetPosition().y});
        collidtion = tempPtr->IfCollideSomething(m_CollideObjects);

        if (collidtion == nullptr) {
            player->SetLastTouched(Character::Tag::Null);
            player->SetPosition({player->GetPosition().x - grid_size, player->GetPosition().y});
            if (m_Phase == Phase::Phase10) {

            }
            else {
                m_StepText->ShowLeftStep();
            }
        }
        else if (collidtion->GetTag() == Character::Tag::Boundary) {
            player->SetLastTouched(collidtion->GetTag());
            tempPtr.reset();
            collidtion.reset();
            return;
        }
        else if (collidtion->GetTag() == Character::Tag::Rock) {
            player->SetLastTouched(collidtion->GetTag());
            Push(player, collidtion, 'A');
            if (m_Phase == Phase::Phase10) {

            }
            else {
                m_StepText->ShowLeftStep();
            }
        }
        else {
            player->SetLastTouched(collidtion->GetTag());
            player->SetPosition({player->GetPosition().x - grid_size, player->GetPosition().y});
            if (m_Phase == Phase::Phase10) {

            }
            else {
                m_StepText->ShowLeftStep();
            }
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
            if (m_Phase == Phase::Phase10) {

            }
            else {
                m_StepText->ShowLeftStep();
            }
        }
        else if (collidtion->GetTag() == Character::Tag::Boundary) {
            player->SetLastTouched(collidtion->GetTag());
            tempPtr.reset();
            collidtion.reset();
            return;
        }
        else if (collidtion->GetTag() == Character::Tag::Rock) {
            player->SetLastTouched(collidtion->GetTag());
            Push(player, collidtion, 'D');
            if (m_Phase == Phase::Phase10) {

            }
            else {
                m_StepText->ShowLeftStep();
            }
        }
        else {
            player->SetLastTouched(collidtion->GetTag());
            player->SetPosition({player->GetPosition().x + grid_size, player->GetPosition().y});
            if (m_Phase == Phase::Phase10) {

            }
            else {
                m_StepText->ShowLeftStep();
            }
        }

        tempPtr.reset();
        collidtion.reset();
        return;
    }

    if (Util::Input::IsKeyDown(Util::Keycode::S)) {
        ShootLaserL(m_LaserMechBoxes[0]);
        tempPtr->SetPosition({player->GetPosition().x, player->GetPosition().y - grid_size});
        collidtion = tempPtr->IfCollideSomething(m_CollideObjects);

        if (collidtion == nullptr) {
            player->SetLastTouched(Character::Tag::Null);
            player->SetPosition({player->GetPosition().x, player->GetPosition().y - grid_size});
            if (m_Phase == Phase::Phase10) {

            }
            else {
                m_StepText->ShowLeftStep();
            }
        }
        else if (collidtion->GetTag() == Character::Tag::Boundary) {
            player->SetLastTouched(collidtion->GetTag());
            tempPtr.reset();
            collidtion.reset();
            return;
        }
        else if (collidtion->GetTag() == Character::Tag::Rock) {
            player->SetLastTouched(collidtion->GetTag());
            Push(player, collidtion, 'S');
            if (m_Phase == Phase::Phase10) {

            }
            else {
                m_StepText->ShowLeftStep();
            }
        }
        else if (collidtion->GetTag() == Character::Tag::Laser) {
            tempPtr.reset();
            collidtion.reset();
            m_CurrentState = State::START;
            return;
        }
        else {
            player->SetLastTouched(collidtion->GetTag());
            player->SetPosition({player->GetPosition().x, player->GetPosition().y - grid_size});
            if (m_Phase == Phase::Phase10) {

            }
            else {
                m_StepText->ShowLeftStep();
            }
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
            if (m_Phase == Phase::Phase10) {

            }
            else {
                m_StepText->ShowLeftStep();
            }
        }
        else if (collidtion->GetTag() == Character::Tag::Boundary) {
            player->SetLastTouched(collidtion->GetTag());
            tempPtr.reset();
            collidtion.reset();
            return;
        }
        else if (collidtion->GetTag() == Character::Tag::Rock) {
            player->SetLastTouched(collidtion->GetTag());
            Push(player, collidtion, 'W');
            if (m_Phase == Phase::Phase10) {

            }
            else {
                m_StepText->ShowLeftStep();
            }
        }
        else {
            player->SetLastTouched(collidtion->GetTag());
            player->SetPosition({player->GetPosition().x, player->GetPosition().y + grid_size});
            if (m_Phase == Phase::Phase10) {

            }
            else {
                m_StepText->ShowLeftStep();
            }
        }

        tempPtr.reset();
        collidtion.reset();
        return;
    }

    tempPtr.reset();
    collidtion.reset();
}