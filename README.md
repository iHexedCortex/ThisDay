<div align="center">

<img src="resources/images/title.png" width="620" alt="ThisDay Logo" style="margin-bottom: 20px;">

# 🌤️ ThisDay Weather Engine
### `Cinematic Glassmorphic Dashboard • High-Performance Systems Engineering`

[![System Status](https://img.shields.io/badge/System-Stable-41CD52?style=for-the-badge&logo=qt&logoColor=white)](https://github.com/iHexedCortex/ThisDay)
[![Kernel](https://img.shields.io/badge/Kernel-Qt_6.6+-blue?style=for-the-badge&logo=qt&logoColor=white)](https://www.qt.io/)
[![Architecture](https://img.shields.io/badge/Architecture-DDD/Onion-orange?style=for-the-badge)](https://github.com/iHexedCortex/ThisDay)
[![Performance](https://img.shields.io/badge/Render-GPU_Accelerated-red?style=for-the-badge)](https://github.com/iHexedCortex/ThisDay)

---

<img src="screenshots/dark_mode_today_page.jpg" width="100%" alt="ThisDay Dashboard Dark Mode" style="border-radius: 10px;">

*"Weather data isn't just numbers; it's a narrative. ThisDay interprets atmospheric complexity into human insight."*

</div>

<br />

## 🛰️ Core Philosophy
**ThisDay** is a native desktop engine built to prove that C++ performance and modern "glassmorphic" aesthetics aren't mutually exclusive. By leveraging the **Qt 6 Framework**, it delivers a fluid 60 FPS experience on modern hardware—like the HP Victus platform—while maintaining a zero-latency UI thread through advanced asynchronous polling.

<br />

## 🛠️ The Tech Stack (Engine Room)

| Layer | Technologies | Purpose |
| :--- | :--- | :--- |
| **Frontend** | `QML`, `Qt Quick`, `JavaScript` | Declarative UI & Fluid Animations |
| **Backend** | `C++ 20`, `Qt Network`, `CMake` | Logic, Networking, & Resource Management |
| **Storage** | `JSON Serialization`, `Qt Settings` | Configuration Persistence |
| **API** | `Open-Meteo Geocoding & Forecast` | Real-time Global Data (No API Key Required) |
| **Design** | `Figma`, `Custom SVG Assets` | Visual Identity & Glass Systems |

<br />

## 🏗️ Architectural Excellence
* **Onion Architecture**: Strict separation between the Core Weather Engine (C++) and the Presentation Layer (QML).
* **Zero-Config API**: Utilizes the **Open-Meteo** ecosystem, removing the friction of API key management while providing high-resolution global forecasting.
* **Smart Summaries**: Real-time calculated properties (`ComfortLevel`, `ActivityScore`, `AQVibe`) that interpret complex atmospheric data into actionable human insights.
* **Network Heartbeat**: Built-in connectivity monitoring to ensure the "Synced" status indicator accurately reflects real-time data availability.

<br />

## 🖼️ Visual Subsystems

### 🧩 Perceived Performance (Skeleton State)
To eliminate "blank screen fatigue," ThisDay utilizes a custom **Skeleton Loading System**.
<p align="center">
  <img src="screenshots/dark_mode_today_page_skeleton.png" width="45%" alt="Dark Mode Today Page Skeleton">
  <img src="screenshots/light_mode_today_page_skeleton.png" width="45%" alt="Light Mode Today Page Skeleton">
</p>

### 🌓 Dual-Theme Ecosystem
* **System Core (Dark)**: Optimized for "Cyber-Noir" desktop setups with deep contrast and neon accents.
* **Solar-Optimized (Light)**: High-legibility mode designed for high-glare environments.
<p align="center">
  <img src="screenshots/dark_mode_today_page.jpg" width="45%" alt="Dark Mode Today Page">
  <img src="screenshots/light_mode_today_page.jpg" width="45%" alt="Light Mode Today Page">
</p>

<br />

## 🛠️ Build Guide

Since **ThisDay** uses **Open-Meteo**, there are no API keys required for the build process.

### 1. The Qt Creator Way (Recommended)
This is the most reliable method for Windows users to ensure all environment variables are mapped correctly.

1. **Open Project:** Launch Qt Creator and open the `CMakeLists.txt` file.
2. **Select Kit:** Select **Desktop Qt 6.x.x MinGW 64-bit**.
3. **Set Build Type:** Go to the **Projects** tab and set the **Build type** to `Release`.
4. **Configure CMake:** If Qt6 is not found, add this variable in the CMake section:
   * **Key:** `CMAKE_PREFIX_PATH`
   * **Value:** `C:/Qt/6.x.x/mingw_64` (Adjust to your actual path).
5. **Build:** Press `Ctrl + B`.

---

### 2. The Terminal Way
Use this approach if you prefer building via Command Line or PowerShell.
```powershell
# 1. Clone the repository
git clone [https://github.com/iHexedCortex/ThisDay.git](https://github.com/iHexedCortex/ThisDay.git)
cd ThisDay

# 2. Configure the project
# Replace the path below with your actual Qt MinGW installation folder
cmake -B build -S . -DCMAKE_PREFIX_PATH="D:/Qt/6.9.2/mingw_64" -DCMAKE_BUILD_TYPE=Release

# 3. Build the executable
cmake --build build --config Release
