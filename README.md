# Edge Anomaly Detection & Sensor Processing Engine
C++/Python TinyML reference pipeline for 3-axis vibration sensing: fixed-size windows, spectral feature extraction, RMS/peak/crest/dominant-frequency features, INT8 feature quantization/classifier, static working-set budget check, and Python calibration.

`pytest -q` validates the reference feature/calibration behavior. The `<64 KB RAM` figure is treated as a design budget until measured on the actual MCU/toolchain.
