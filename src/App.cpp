#include "App.hpp"

#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"

void App::Start() {
    LOG_TRACE("Start");

    m_player = std::make_shared<Character>("/Users/wengtinghao/-tiptree/Resources/Image/Character/player.png");
    m_player->SetPosition({-400, 0});
    m_player->SetZIndex(50);
    m_player->SetVisible(true);
    m_Root.AddChild(m_player);

    m_boss1 = std::make_shared<Character>("/Users/wengtinghao/-tiptree/Resources/Image/Character/boss1.png");
    m_boss1->SetPosition({150.1f, 50});
    m_boss1->SetZIndex(50);
    m_boss1->SetVisible(true);
    m_Root.AddChild(m_boss1);

    m_PRM = std::make_shared<PhaseResourceManger>();
    m_Root.AddChildren(m_PRM->GetChildren());

    m_CurrentState = State::UPDATE;
}

void App::Update() {
    //make character move
    if (Util::Input::IsKeyPressed(Util::Keycode::A)){
        float  old_x = m_player->GetPosition()[0];
        float  old_y = m_player->GetPosition()[1];
        m_player->SetPosition({old_x - 5.0f, old_y});
    }

    if (Util::Input::IsKeyPressed(Util::Keycode::D)){
        float  old_x = m_player->GetPosition()[0];
        float  old_y = m_player->GetPosition()[1];
        m_player->SetPosition({old_x + 5.0f, old_y});
    }

    if (Util::Input::IsKeyPressed(Util::Keycode::S)){
        float  old_x = m_player->GetPosition()[0];
        float  old_y = m_player->GetPosition()[1];
        m_player->SetPosition({old_x, old_y - 5.0f});
    }

    if (Util::Input::IsKeyPressed(Util::Keycode::W)){
        float  old_x = m_player->GetPosition()[0];
        float  old_y = m_player->GetPosition()[1];
        m_player->SetPosition({old_x, old_y + 5.0f});
    }

    if (m_player->IfCollides(m_boss1)) {
        float  old_x = m_boss1->GetPosition()[0];
        float  old_y = m_boss1->GetPosition()[1];
        m_boss1->SetPosition({old_x + 5.0f, old_y});
    }
    
    if (m_EnterDown) {
        if (!Util::Input::IsKeyPressed(Util::Keycode::RETURN)) {
            ValidTask();
        }
    }
    m_EnterDown = Util::Input::IsKeyPressed(Util::Keycode::RETURN);

    /*
     * Do not touch the code below as they serve the purpose for
     * closing the window.
     */

    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
        Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }

    m_Root.Update();
}

void App::End() { // NOLINT(this method will mutate members in the future)
    LOG_TRACE("End");
}
