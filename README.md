<div align="center">
  <h1>🌱 Soil Tester with ESP32</h1>
  <p><strong>NPK Sensor + 20x4 I2C LCD + Firebase + Android App</strong></p>
  <img src="https://img.shields.io/badge/Platform-ESP32-blue?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Status-Active-brightgreen?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Made%20By-QPPD-blueviolet?style=for-the-badge" />
</div>

---

<h2>📦 Project Description</h2>

<p>
This IoT-powered Soil Tester utilizes an <strong>ESP32</strong> microcontroller to measure soil <strong>Nitrogen (N)</strong>, <strong>Phosphorus (P)</strong>, and <strong>Potassium (K)</strong> levels using an <strong>NPK sensor</strong>. It displays real-time values on a <strong>20x4 I2C LCD</strong> and synchronizes data to <strong>Firebase Realtime Database</strong>, which is consumed by a custom-built <strong>Android app</strong> developed in Java using Android Studio.
</p>

---

<h2>⚙️ Components Used</h2>

<table>
  <thead>
    <tr>
      <th>Component</th>
      <th>Description</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>ESP32 Board</td>
      <td>Main microcontroller with Wi-Fi + UART</td>
    </tr>
    <tr>
      <td>NPK Sensor</td>
      <td>Measures Nitrogen, Phosphorus, and Potassium</td>
    </tr>
    <tr>
      <td>20x4 I2C LCD</td>
      <td>Displays live NPK readings</td>
    </tr>
  </tbody>
</table>

---

<h2>🔗 System Overview</h2>

<ol>
  <li><strong>ESP32</strong> reads data from the NPK sensor via UART.</li>
  <li><strong>Data is displayed</strong> on a 20x4 LCD using the I2C interface.</li>
  <li><strong>Sensor values are uploaded</strong> to Firebase Realtime Database using <code>Firebase_ESP_Client</code>.</li>
  <li><strong>Android app</strong> fetches and displays the data in a mobile-friendly UI and suggests a plant perfect for the soil.</li>
</ol>

---

<h2>💻 Arduino IDE Setup</h2>

<ol>
  <li>Install these libraries:
    <ul>
      <li><code>LiquidCrystal_I2C</code></li>
      <li><code>Firebase_ESP_Client</code></li>
    </ul>
  </li>
  <li>Configure Firebase in code:
    <ul>
      <li>Firebase Host (e.g., <code>your-project.firebaseio.com</code>)</li>
      <li>Firebase Auth / Secret Key</li>
    </ul>
  </li>
  <li>Clone the repo:
    <pre><code>git clone https://github.com/qppd/Soil-Tester.git</code></pre>
  </li>
  <li>Open <code>SoilTester_ESP32.ino</code> in Arduino IDE</li>
  <li>Select board: <strong>ESP32 Dev Module</strong></li>
  <li>Upload to your ESP32 board</li>
</ol>

---

<h2>📁 Project Structure</h2>

<pre>
Soil-Tester/
├── SoilTester.ino
├── README.md
└── .gitignore
</pre>

---

<h2>📝 License</h2>

<p>This project is licensed under the <strong>MIT License</strong>. You may use, modify, and share it freely with credit to the author.</p>

---

<h2>🙌 Acknowledgements</h2>

<ul>
  <li>ESP32 Arduino Community</li>
  <li>Firebase Realtime Database</li>
  <li>Arduino & open-source contributors</li>
</ul>

---

<h2>🔗 Connect With Me</h2>

<table>
  <tr>
    <td>📘 Facebook</td>
    <td><a href="https://facebook.com/qppd.dev" target="_blank">facebook.com/qppd.dev</a></td>
  </tr>
  <tr>
    <td>📦 GitHub</td>
    <td><a href="https://github.com/qppd" target="_blank">github.com/qppd</a></td>
  </tr>
  <tr>
    <td>🎥 TikTok</td>
    <td><a href="https://www.tiktok.com/@jed.lopez.mendoza.dev" target="_blank">@jed.lopez.mendoza.dev</a></td>
  </tr>
  <tr>
    <td>✉️ Email</td>
    <td><a href="mailto:quezon.province.pd@gmail.com">quezon.province.pd@gmail.com</a></td>
  </tr>
</table>

---

<div align="center">
  <strong>🌿 Empowering Smart Agriculture with QPPD</strong><br/>
  <em>Made with ❤️ by <a href="https://github.com/qppd">QPPD</a></em>
</div>
