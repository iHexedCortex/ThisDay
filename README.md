<div align="center">

# ☁️ ThisDay Weather Engine
### `High-Performance Glassmorphic Desktop Experience`

[![System Status](https://img.shields.io/badge/System-Stable-41CD52?style=for-the-badge&logo=qt&logoColor=white)](https://github.com/iHexedCortex/ThisDay)
[![Kernel](https://img.shields.io/badge/Kernel-Qt_6.x-blue?style=for-the-badge&logo=cpp&logoColor=white)](https://www.qt.io/)
[![Architecture](https://img.shields.io/badge/Architecture-Onion/DDD-orange?style=for-the-badge)](https://github.com/iHexedCortex/ThisDay)

---

<img src="screenshots/dark_mode_today_page.jpg" width="100%" alt="ThisDay Dashboard Dark Mode">

</div>

## 🛰️ Technical Overview
**ThisDay** is a native desktop application designed to bridge the gap between heavy system performance and elegant, modern aesthetics. Built on the **Qt 6 framework**, it utilizes a dual-layer architecture: a high-speed **C++ backend** for data handling and a **QML frontend** for GPU-accelerated rendering.

## 🖼️ Visual Subsystems (Gallery)

| Dark Mode (System Core) | Light Mode (High Contrast) |
| :---: | :---: |
| <img src="screenshots/dark_mode_today_page.jpg" width="400"> | <img src="screenshots/light_mode_today_page.jpg" width="400"> |
| *Full Cinematic Dashboard* | *Solar-Optimized UI* |

### 🧩 UI/UX Architecture
<p align="center">
  <img src="screenshots/dark_mode_today_page_skeleton.png" width="280" alt="Skeleton Loading Dark">
  <img src="screenshots/light_mode_today_page_skeleton.png" width="280" alt="Skeleton Loading Light">
</p>

* **Adaptive Loaders**: Custom QML skeleton components for low-latency perceived performance during API fetches.
* **Sidebar Engine**: Fully animatable collapsed state to maximize screen real estate.
* **Glassmorphic Design**: Custom-built widgets with real-time transparency effects.

## 🏗️ System Architecture
* **Backend**: C++ / Qt Network (OpenWeather API integration).
* **Frontend**: QML / Qt Quick Controls 2 / Custom Shaders.
* **Design Pattern**: Feature-based modular architecture for scalability.
* **Performance**: Asynchronous API polling to ensure the UI thread remains at 60 FPS.

## 🚀 Installation & Build
```bash
# Clone the repository
git clone [https://github.com/iHexedCortex/ThisDay.git](https://github.com/iHexedCortex/ThisDay.git)

# Navigate to directory
cd ThisDay

# Build using CMake
mkdir build && cd build
cmake ..
make
