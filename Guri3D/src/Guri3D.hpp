#ifndef GURI3D_HPP
#define GURI3D_HPP

#include "graphics.hpp"
#include "physics.hpp"
#include "sound.hpp"
#include "input.hpp"

namespace Guri3D {
    // Guri3D motoru
    class Guri3D {
    private:
        std::shared_ptr<GraphicsClient> graphics;
        std::shared_ptr<PhysicsClient3D> physics;
        std::shared_ptr<SoundClient3D> sound;
        std::shared_ptr<InputClient3D> input;
        
    public:
        Guri3D()
            : graphics(std::make_shared<GraphicsClient>(std::make_shared<GraphicsManager>())),
              physics(std::make_shared<PhysicsClient3D>(std::make_shared<PhysicsManager3D>())),
              sound(std::make_shared<SoundClient3D>(std::make_shared<SoundManager3D>())),
              input(std::make_shared<InputClient3D>(std::make_shared<InputManager3D>())) {}
        
        // Grafik yönetimi
        void addObject3D(std::shared_ptr<Object3D> object) {
            graphics->addObject(object);
        }
        
        void setCameraPosition(float x, float y, float z) {
            graphics->setCameraPosition(x, y, z);
        }
        
        void setCameraRotation(float x, float y, float z) {
            graphics->setCameraRotation(x, y, z);
        }
        
        void setCameraZoom(float zoom) {
            graphics->setCameraZoom(zoom);
        }
        
        // Fizik yönetimi
        void addPhysicsObject3D(std::shared_ptr<PhysicsObject3D> object) {
            physics->addObject(object);
        }
        
        void updatePhysics(float deltaTime) {
            physics->update(deltaTime);
        }
        
        // Ses yönetimi
        void addSound3D(const std::string& name, const std::string& path) {
            sound->addSound(name, path);
        }
        
        void playSound3D(const std::string& name) {
            sound->play(name);
        }
        
        void stopSound3D(const std::string& name) {
            sound->stop(name);
        }
        
        void setSoundPosition(const std::string& name, float x, float y, float z) {
            sound->setPosition(name, x, y, z);
        }
        
        // Girdi yönetimi
        void onKeyDown(int key, const std::function<void()>& callback) {
            input->onKeyDown(key, callback);
        }
        
        void onKeyUp(int key, const std::function<void()>& callback) {
            input->onKeyUp(key, callback);
        }
        
        void onMouseMove(const std::function<void(int, int)>& callback) {
            input->onMouseMove(callback);
        }
        
        void onJoystickMove(const std::function<void(float, float, float)>& callback) {
            input->onJoystickMove(callback);
        }
        
        void updateInput() {
            input->update();
        }
        
        // Motor durumu
        bool isRunning() const {
            return true; // Default olarak çalışır durumda
        }
        
        void update(float deltaTime) {
            updatePhysics(deltaTime);
            updateInput();
        }
    };
}

#endif // GURI3D_HPP
