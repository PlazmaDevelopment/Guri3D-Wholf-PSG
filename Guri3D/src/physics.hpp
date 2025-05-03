#ifndef GURI3D_PHYSICS_HPP
#define GURI3D_PHYSICS_HPP

#include <string>
#include <memory>
#include <vector>
#include <functional>

namespace Guri3D {
    // 3D fizik nesnesi
    class PhysicsObject3D {
    public:
        float x, y, z;
        float velocityX, velocityY, velocityZ;
        float accelerationX, accelerationY, accelerationZ;
        float mass;
        float friction;
        
        PhysicsObject3D(float x = 0, float y = 0, float z = 0, float mass = 1.0f)
            : x(x), y(y), z(z), mass(mass), friction(0.9f) {}
        
        void update(float deltaTime) {
            // Hız güncelleme
            velocityX += accelerationX * deltaTime;
            velocityY += accelerationY * deltaTime;
            velocityZ += accelerationZ * deltaTime;
            
            // Pozisyon güncelleme
            x += velocityX * deltaTime;
            y += velocityY * deltaTime;
            z += velocityZ * deltaTime;
            
            // Sürükleme uygulama
            velocityX *= friction;
            velocityY *= friction;
            velocityZ *= friction;
        }
        
        void applyForce(float forceX, float forceY, float forceZ) {
            accelerationX += forceX / mass;
            accelerationY += forceY / mass;
            accelerationZ += forceZ / mass;
        }
    };
    
    // 3D fizik yöneticisi
    class PhysicsManager3D {
    private:
        std::vector<std::shared_ptr<PhysicsObject3D>> objects;
        float gravity;
        float deltaTime;
        
    public:
        PhysicsManager3D(float gravity = 9.81f)
            : gravity(gravity), deltaTime(0.0f) {}
        
        void addObject(std::shared_ptr<PhysicsObject3D> object) {
            objects.push_back(object);
        }
        
        void update(float deltaTime) {
            this->deltaTime = deltaTime;
            
            for (auto& object : objects) {
                // Yerçekimi uygulama
                object->applyForce(0, gravity * object->mass, 0);
                
                // Nesne güncelleme
                object->update(deltaTime);
            }
        }
        
        bool checkCollision(std::shared_ptr<PhysicsObject3D> obj1, std::shared_ptr<PhysicsObject3D> obj2) {
            float distance = std::sqrt(
                std::pow(obj1->x - obj2->x, 2) +
                std::pow(obj1->y - obj2->y, 2) +
                std::pow(obj1->z - obj2->z, 2)
            );
            
            return distance < 1.0f; // Simple collision detection
        }
    };
    
    // 3D fizik istemcisi
    class PhysicsClient3D {
    private:
        std::shared_ptr<PhysicsManager3D> manager;
        
    public:
        PhysicsClient3D(std::shared_ptr<PhysicsManager3D> manager)
            : manager(manager) {}
        
        void addObject(std::shared_ptr<PhysicsObject3D> object) {
            manager->addObject(object);
        }
        
        void update(float deltaTime) {
            manager->update(deltaTime);
        }
        
        bool checkCollision(std::shared_ptr<PhysicsObject3D> obj1, std::shared_ptr<PhysicsObject3D> obj2) {
            return manager->checkCollision(obj1, obj2);
        }
    };
}

#endif // GURI3D_PHYSICS_HPP
