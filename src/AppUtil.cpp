//
// Created by 翁廷豪 on 2024/3/6.
//

#include "AppUtil.hpp"
#include "App.hpp"

/**
 * @brief The function to validate the tasks.
 * @warning Do not modify this function.
 * @note See README.md for the task details.
 */
void App::ValidTask() {
    bool isBeeLooping;
    bool isBeePlaying;
    LOG_DEBUG("Validating the task {}", static_cast<int>(m_Phase));
    switch (m_Phase) {
        case Phase::Phase1:
            if (m_player->GetImagePath() == "/Users/wengtinghao/-tiptree/Resources/Image/Character/player.png") {
        m_Phase = Phase::Phase2;
        m_player->SetPosition({-112.5f, -140.5f});

        m_PRM->NextPhase();
    } else {
        LOG_DEBUG("The image is not correct");
        LOG_DEBUG("The image path is {} instead.", m_player->GetImagePath());
    }
            break;

        case Phase::Phase2:
            if (isInsideTheSquare(*m_player)) {
                LOG_DEBUG("Congratulations! You have completed Giraffe Adventure!");
                m_CurrentState = State::END;
            } else {
                LOG_DEBUG("The giraffe is not inside the square");
            }
            break;
    }
}
