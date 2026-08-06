

https://github.com/user-attachments/assets/d4c5ad5a-ca1c-4e24-b23c-197601783280


# Ventilator Waveform Simulator

A CPU RT medical monitor simulation built with Qt/C++/QML. Implements clinical ECG, Airway Pressure (Paw), Flow, and Capnography ($\text{EtCO}_2$) waveforms at 60fps 

---


## Key Features

* **CPU Rendering:** deterministic performance on embedded ARM and x86 targets.
* **Physiologically Accurate Physics:**
  * **ECG:** Gaussian modeled P-QRS-T complex with smoothed BPM transitions.
  * **Paw / Flow:** Dynamic I:E ratio 
  * **$\text{EtCO}_2$:** Phase-correct capnography tied to flow, dead space washout, alveolar plateau, expiration washout).
  
* **Delta Time Simulation:** identical sweep speed at 30fps, 60fps, 144fps.
* **Dynamic Status Indicators:** Battery level and WiFi signal strength

---

## Build Instructions
```powershell
qmake ..\VentilatorWaveformSim.pro CONFIG+=release
mingw32-make -j4

# Run
.\release\VentilatorWaveformSim.exe
