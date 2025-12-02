**ESP32 WiFi Scanner（僅列出 SSID）**

- **檔案**: `src/main.cpp`
- **板子**: `nodemcu-32s`（在 `platformio.ini` 已設定）
- **說明**: 這個專案示範如何用 ESP32 掃描周遭的 WiFi 熱點，程式每 10 秒執行一次掃描，並在序列埠僅列出找到的 SSID 清單（每行一個 SSID）。

**建置與上傳 (PowerShell / PlatformIO)**
- **編譯**:
```powershell
C:\Users\st01\.platformio\penv\Scripts\platformio.exe run -e nodemcu-32s
```
- **上傳**:
```powershell
C:\Users\st01\.platformio\penv\Scripts\platformio.exe run -e nodemcu-32s -t upload --upload-port COM7
```
（若系統找不到 `pio`，請使用上面完整路徑或把 PlatformIO 的執行檔加入 PATH；請先確定沒有其他程式（例如序列監視器）佔用 COM 埠）

**序列埠監視**
- 程式使用 `Serial.begin(115200)`，請以 `115200` baud 開啟序列監視器：
```powershell
C:\Users\st01\.platformio\penv\Scripts\platformio.exe device monitor -b 115200
```
或使用 PlatformIO 的快速命令：
```powershell
pio run -e nodemcu-32s -t monitor
```

**程式行為**
- 啟動後將 WiFi 設為 Station 模式，呼叫 `WiFi.scanNetworks()` 掃描周遭熱點。
- 若找到熱點，會輸出類似：

```
共找到 5 個網路:
1: MyHomeWiFi
2: CoffeeShop
3: OfficeNet
...
```

**檔案說明**
- `src/main.cpp`: 主程式，負責掃描並輸出 SSID。
- `platformio.ini`: 專案設定（已設定為 `nodemcu-32s` 與 `framework = arduino`）。

**下一步建議**
- 如果需要，我可以：
	- 把結果輸出成 JSON，或發送到 MQTT/HTTP。 
	- 加入 RSSI 篩選或去重功能（移除重複 SSID 或同一 BSSID）。

---
更新日期：2025-12-02
