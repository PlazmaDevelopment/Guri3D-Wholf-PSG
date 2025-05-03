#ifndef GURI3D_SOUND_HPP
#define GURI3D_SOUND_HPP

#include <string>
#include <memory>
#include <map>
#include <functional>

namespace Guri3D {
    // 3D ses nesnesi
    class Sound3D {
    public:
        std::string path;
        float volume;
        bool isLooping;
        float x, y, z;
        
        Sound3D(const std::string& path)
            : path(path), volume(1.0f), isLooping(false), x(0), y(0), z(0) {}
        
        void play() {
            // Ses oynatma
        }
        
        void stop() {
            // Ses durdurma
        }
        
        void setVolume(float volume) {
            this->volume = volume;
        }
        
        void setLooping(bool isLooping) {
            this->isLooping = isLooping;
        }
        
        void setPosition(float x, float y, float z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }
    };
    
    // 3D ses yöneticisi
    class SoundManager3D {
    private:
        std::map<std::string, std::shared_ptr<Sound3D>> sounds;
        
    public:
        void addSound(const std::string& name, const std::string& path) {
            sounds[name] = std::make_shared<Sound3D>(path);
        }
        
        void play(const std::string& name) {
            if (sounds.find(name) != sounds.end()) {
                sounds[name]->play();
            }
        }
        
        void stop(const std::string& name) {
            if (sounds.find(name) != sounds.end()) {
                sounds[name]->stop();
            }
        }
        
        void setVolume(const std::string& name, float volume) {
            if (sounds.find(name) != sounds.end()) {
                sounds[name]->setVolume(volume);
            }
        }
        
        void setLooping(const std::string& name, bool isLooping) {
            if (sounds.find(name) != sounds.end()) {
                sounds[name]->setLooping(isLooping);
            }
        }
        
        void setPosition(const std::string& name, float x, float y, float z) {
            if (sounds.find(name) != sounds.end()) {
                sounds[name]->setPosition(x, y, z);
            }
        }
    };
    
    // 3D ses istemcisi
    class SoundClient3D {
    private:
        std::shared_ptr<SoundManager3D> manager;
        
    public:
        SoundClient3D(std::shared_ptr<SoundManager3D> manager)
            : manager(manager) {}
        
        void addSound(const std::string& name, const std::string& path) {
            manager->addSound(name, path);
        }
        
        void play(const std::string& name) {
            manager->play(name);
        }
        
        void stop(const std::string& name) {
            manager->stop(name);
        }
        
        void setVolume(const std::string& name, float volume) {
            manager->setVolume(name, volume);
        }
        
        void setLooping(const std::string& name, bool isLooping) {
            manager->setLooping(name, isLooping);
        }
        
        void setPosition(const std::string& name, float x, float y, float z) {
            manager->setPosition(name, x, y, z);
        }
    };
}

#endif // GURI3D_SOUND_HPP
