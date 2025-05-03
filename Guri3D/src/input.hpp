#ifndef GURI3D_INPUT_HPP
#define GURI3D_INPUT_HPP

#include <string>
#include <memory>
#include <map>
#include <functional>

namespace Guri3D {
    // Tuş durumu
    enum class KeyState {
        Released,
        Pressed,
        Held
    };
    
    // Fare durumu
    enum class MouseState {
        Released,
        Pressed,
        Moved
    };
    
    // Joystick durumu
    enum class JoystickState {
        Released,
        Pressed,
        Moved
    };
    
    // Girdi yöneticisi
    class InputManager3D {
    private:
        std::map<int, KeyState> keyStates;
        std::map<int, MouseState> mouseStates;
        std::map<int, JoystickState> joystickStates;
        
        // Olay yöneticileri
        std::map<int, std::function<void()>> keyDownCallbacks;
        std::map<int, std::function<void()>> keyUpCallbacks;
        std::map<int, std::function<void(int, int)>> mouseMoveCallbacks;
        std::map<int, std::function<void(float, float, float)>> joystickMoveCallbacks;
        
    public:
        // Tuş durumu
        KeyState getKeyState(int key) {
            if (keyStates.find(key) != keyStates.end()) {
                return keyStates[key];
            }
            return KeyState::Released;
        }
        
        // Fare durumu
        MouseState getMouseState(int button) {
            if (mouseStates.find(button) != mouseStates.end()) {
                return mouseStates[button];
            }
            return MouseState::Released;
        }
        
        // Joystick durumu
        JoystickState getJoystickState(int button) {
            if (joystickStates.find(button) != joystickStates.end()) {
                return joystickStates[button];
            }
            return JoystickState::Released;
        }
        
        // Tuş olayları
        void onKeyDown(int key, const std::function<void()>& callback) {
            keyDownCallbacks[key] = callback;
        }
        
        void onKeyUp(int key, const std::function<void()>& callback) {
            keyUpCallbacks[key] = callback;
        }
        
        void onMouseMove(const std::function<void(int, int)>& callback) {
            mouseMoveCallbacks[0] = callback; // 0 represents any button
        }
        
        void onJoystickMove(const std::function<void(float, float, float)>& callback) {
            joystickMoveCallbacks[0] = callback; // 0 represents any button
        }
        
        // Girdi güncelleme
        void update() {
            // Tuş olayları
            for (auto& pair : keyStates) {
                if (pair.second == KeyState::Pressed) {
                    if (keyDownCallbacks.find(pair.first) != keyDownCallbacks.end()) {
                        keyDownCallbacks[pair.first]();
                    }
                    pair.second = KeyState::Held;
                }
            }
            
            // Fare olayları
            for (auto& pair : mouseStates) {
                if (pair.second == MouseState::Pressed) {
                    if (mouseMoveCallbacks.find(pair.first) != mouseMoveCallbacks.end()) {
                        mouseMoveCallbacks[pair.first](0, 0); // Mouse position
                    }
                    pair.second = MouseState::Moved;
                }
            }
            
            // Joystick olayları
            for (auto& pair : joystickStates) {
                if (pair.second == JoystickState::Pressed) {
                    if (joystickMoveCallbacks.find(pair.first) != joystickMoveCallbacks.end()) {
                        joystickMoveCallbacks[pair.first](0, 0, 0); // Joystick position
                    }
                    pair.second = JoystickState::Moved;
                }
            }
        }
    };
    
    // Girdi istemcisi
    class InputClient3D {
    private:
        std::shared_ptr<InputManager3D> manager;
        
    public:
        InputClient3D(std::shared_ptr<InputManager3D> manager)
            : manager(manager) {}
        
        KeyState getKeyState(int key) {
            return manager->getKeyState(key);
        }
        
        MouseState getMouseState(int button) {
            return manager->getMouseState(button);
        }
        
        JoystickState getJoystickState(int button) {
            return manager->getJoystickState(button);
        }
        
        void onKeyDown(int key, const std::function<void()>& callback) {
            manager->onKeyDown(key, callback);
        }
        
        void onKeyUp(int key, const std::function<void()>& callback) {
            manager->onKeyUp(key, callback);
        }
        
        void onMouseMove(const std::function<void(int, int)>& callback) {
            manager->onMouseMove(callback);
        }
        
        void onJoystickMove(const std::function<void(float, float, float)>& callback) {
            manager->onJoystickMove(callback);
        }
        
        void update() {
            manager->update();
        }
    };
}

#endif // GURI3D_INPUT_HPP
