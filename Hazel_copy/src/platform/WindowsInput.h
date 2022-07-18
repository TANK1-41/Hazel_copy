#pragma once

#include "Input.h"

namespace Hazel
{
    class WindowsInput : public Input {
    protected:
        virtual bool IsKeyPressedImpl(int keycode) override;

        virtual bool IsMouseButtonPressedImpl(int button) override;

        virtual float GetMouseXImpl() override;

        virtual float GetMouseYImpl() override;

        std::pair<float, float> GetMousePositionImpl() override;
    };
}// namespace Hazel
