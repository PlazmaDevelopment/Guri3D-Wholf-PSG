# Guri3D

Guri3D, Wholf dilinde 3D oyun geliştirme için kullanılan güçlü bir kütüphanedir.

## Özellikler

- 3D Grafik sistemi
- 3D Fizik sistemi
- 3D Ses sistemi
- Kullanıcı girişi sistemi (Tuş, Fare, Joystick)
- Olay yönetimi
- Performans optimizasyonları

## Kurulum

```wholf
fort import "Guri3D"
```

## Kullanım

### Temel Kullanım

```wholf
// 3D nesne ekleme
fegn Guri3D {
    addObject3D: (object) => {
        Console.log("3D nesne eklendi")
    }
}

// Kamera yönetimi
fegn Guri3D {
    setCameraPosition: (x, y, z) => {
        Console.log("Kamera pozisyonu güncellendi")
    }
}
```

### Fizik Sistemi

```wholf
// 3D fizik nesnesi ekle
fegn Guri3D {
    addPhysicsObject3D: (object) => {
        Console.log("3D fizik nesnesi eklendi")
    }
}

// Fizik güncelleme
fegn Guri3D {
    updatePhysics: (deltaTime) => {
        Console.log("3D fizik güncellendi")
    }
}
```

### Ses Sistemi

```wholf
// 3D ses ekle
fegn Guri3D {
    addSound3D: ("music", "music.mp3") => {
        Console.log("3D ses eklendi")
    }
}

// Ses pozisyonu
fegn Guri3D {
    setSoundPosition: ("music", x, y, z) => {
        Console.log("3D ses pozisyonu güncellendi")
    }
}
```

### Kullanıcı Girişi

```wholf
// Tuş olayları
fegn Guri3D {
    onKeyDown: (key, callback) => {
        Console.log("Tuş basıldı: " + key)
    }
}

// Joystick olayları
fegn Guri3D {
    onJoystickMove: (callback) => {
        Console.log("Joystick hareket etti")
    }
}
```

## Lisans

MIT License
