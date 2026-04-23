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
**ThisDay** is a native desktop engine built to prove that C++ performance and modern "glassmorphic" aesthetics aren't mutually exclusive. By leveraging the **Qt 6 Framework**, it delivers a 60 FPS experience on your Victus hardware while maintaining a zero-latency UI thread through advanced asynchronous polling.

<br />

## 🛠️ The Tech Stack (Engine Room)

| Layer | Technologies | Purpose |
| :--- | :--- | :--- |
| **Frontend** | `QML`, `Qt Quick`, `JavaScript` | Declarative UI & Fluid Animations |
| **Backend** | `C++ 20`, `Qt Network`, `CMake` | Logic, Networking, & Resource Management |
| **Storage** | `JSON Serialization`, `Qt Settings` | Configuration Persistence |
| **API** | `OpenWeatherMap OneCall` | Real-time Global Atmospheric Data |
| **Design** | `Figma`, `Custom SVG Assets` | Visual Identity & Glass Systems |

<br />

## 🖼️ Visual Subsystems

### 🧩 Perceived Performance (Skeleton State)
To eliminate "blank screen fatigue," ThisDay utilizes a custom **Skeleton Loading System**.
<p align="center">
  <img src="screenshots/dark_mode_today_page_skeleton.png" width="45%" alt="Skeleton Dark">
  <img src="screenshots/light_mode_today_page_skeleton.png" width="45%" alt="Skeleton Light">
</p>

### 🌓 Dual-Theme Ecosystem
* **System Core (Dark)**: Optimized for "Cyber-Noir" desktop setups with deep contrast and neon accents.
* **Solar-Optimized (Light)**: High-legibility mode designed for high-glare environments.
<p align="center">
  <img src="screenshots/dark_mode_today_page.jpg" width="45%" alt="Skeleton Dark">
  <img src="screenshots/light_mode_today_page.jpg" width="45%" alt="Skeleton Light">
</p>

<br />

## 🏗️ Architectural Excellence
* **Onion Architecture**: Strict separation between the Core Weather Engine (C++) and the Presentation Layer (QML).
* **Smart Summaries**: Real-time calculated properties (`ComfortLevel`, `ActivityScore`, `AQVibe`) that interpret humidity, UV, and visibility into actionable human insights.
* **Network Heartbeat**: Built-in connectivity monitoring to ensure the "Synced" status indicator is always accurate.

<br />

## 🚀 Fast Start
### Prerequisites
* **Qt 6.6+** (Desktop Development Kit)
* **CMake 3.20+**
* **C++ 20** compatible compiler (MSVC/MinGW)

```bash
# Clone the repository
git clone [https://github.com/iHexedCortex/ThisDay.git](https://github.com/iHexedCortex/ThisDay.git)

# Configure and Build
cd ThisDay
cmake -B build -S .
cmake --build build --config Release
