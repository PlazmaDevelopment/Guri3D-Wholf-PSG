#ifndef GURI3D_GRAPHICS_HPP
#define GURI3D_GRAPHICS_HPP

#include <string>
#include <memory>
#include <vector>
#include <functional>

namespace Guri3D {
    // 3D nesne
    class Object3D {
    public:
        float x, y, z;
        float rotationX, rotationY, rotationZ;
        float scale;
        
        Object3D(float x = 0, float y = 0, float z = 0)
            : x(x), y(y), z(z), rotationX(0), rotationY(0), rotationZ(0), scale(1.0f) {}
        
        void setPosition(float x, float y, float z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }
        
        void setRotation(float x, float y, float z) {
            rotationX = x;
            rotationY = y;
            rotationZ = z;
        }
        
        void setScale(float scale) {
            this->scale = scale;
        }
    };
    
    // 3D grafik yöneticisi
    class GraphicsManager {
    private:
        std::vector<std::shared_ptr<Object3D>> objects;
        
    public:
        // Nesne ekleme
        void addObject(std::shared_ptr<Object3D> object) {
            objects.push_back(object);
        }
        
        // Grafik güncelleme
        void update(float deltaTime) {
            for (auto& object : objects) {
                // Nesne güncelleme
            }
        }
        
        // Kamera yönetimi
        void setCameraPosition(float x, float y, float z) {
            // Kamera pozisyonu
        }
        
        void setCameraRotation(float x, float y, float z) {
            // Kamera rotasyonu
        }
        
        void setCameraZoom(float zoom) {
            // Kamera zoom
        }
    };
    
    // 3D grafik istemcisi
    class GraphicsClient {
    private:
        std::shared_ptr<GraphicsManager> manager;
        
    public:
        GraphicsClient(std::shared_ptr<GraphicsManager> manager)
            : manager(manager) {}
        
        void addObject(std::shared_ptr<Object3D> object) {
            manager->addObject(object);
        }
        
        void update(float deltaTime) {
            manager->update(deltaTime);
        }
        
        void setCameraPosition(float x, float y, float z) {
            manager->setCameraPosition(x, y, z);
        }
        
        void setCameraRotation(float x, float y, float z) {
            manager->setCameraRotation(x, y, z);
        }
        
        void setCameraZoom(float zoom) {
            manager->setCameraZoom(zoom);
        }
    };
}

#endif // GURI3D_GRAPHICS_HPP
