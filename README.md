
# Jump Trading Market Microstructure Analytics 🌍⚖️

Welcome to the **JumpTradingInterview.ipynb** repository! This project provides powerful visual analytics on trade fills, market data, and order behavior using real-world-like data from two trading engines: **RAINBOW** and **UNICORN**.

![image](https://github.com/user-attachments/assets/41ce56e2-3262-4353-8d18-7039a42b67fd)



https://github.com/user-attachments/assets/cd2e35da-34b8-45ef-8019-567e12b926bb


---

## 🌐 Dataset Overview

The following CSV and TXT files are used:
- `JumpTradingInterview-Fills.RAINBOW.csv`
- `JumpTradingInterview-Fills.UNICORN.csv`
- `JumpTradingInterview-MarketData-ASCII.RAINBOW.txt`
- `JumpTradingInterview-MarketData-ASCII.UNICORN.txt`

These datasets include columns like:
- `Firm`, `Trader`, `Symbol`, `OrderId`
- `IsAggressor`, `IsBuy`, `Price`, `Quantity`
- `ExchangePublishTimestamp`, `ExchangeReceiptTimestamp`

> ⚠️ **Note:** Timestamps are in nanoseconds since epoch and converted using `pd.to_datetime(..., unit='ns')`.

---

## 📊 Key Visual Analytics & Features

### 1. Buy/Sell Trade Side Breakdown
- Vertical bar chart & donut chart
- Stacked comparisons for RAINBOW vs UNICORN
- KPIs in tabular format with percentage breakdown

### 2. Aggressiveness Analysis ⚡
- Aggressor rate per firm
- Aggressor impact = Rate × Fill count
- Annotated horizontal bar plots

### 3. Heatmaps ᾜa
- Firm × Price Level (Raw + Normalized)
- Price × Time (with quantity intensity)
- Color-mapped using seaborn's `coolwarm`, `YlOrBr`, `YlGnBu`

### 4. Spread & Volatility Analysis ⚖️
- Spread over first 1000 packets
- Rolling mean overlay
- Volatility spikes detection

### 5. Price Activity Insights 📈
- Most active price levels by fill count
- Top price comparison RAINBOW vs UNICORN

### 6. Latency Distribution ⏱
- Exchange latency histogram + boxplot
- Mean & median overlays

### 7. Time-Series Fill Activity ⏰
- Firm-level fill count over time (line chart)
- Reveals active windows for each trading firm

### 8. Firm Behavioral Clustering 🧠
- Features: IsAggressor, IsBuy, Quantity, Price (avg)
- KMeans clustering (n=3)
- Seaborn `pairplot()` for behavioral insight

---

## ⚖️ Structure of Notebook

```bash
JumpTradingInterview.ipynb
├── Data Load & Preprocessing
├── Trade Side Analysis (Sell/Buy)
├── Aggressor Analysis
├── Heatmaps (Firm vs Price, Price vs Time)
├── Price-Level Activity
├── Spread & Volatility
├── Latency Insights
├── Time-Series Fill Activity
├── Clustering for Behavioral Grouping
```

---

## 🚀 Requirements

```bash
pip install pandas numpy seaborn matplotlib scikit-learn
```

---

## 🧠 Predictive Ideas (Next Phase)

- **Latency Prediction:** Train regression models using spread, quantity, and price levels.
- **Anomaly Detection:** Flag aggressive spikes and unusually active firms.
- **Firm Fingerprinting:** Predict firm identity from behavior vectors.
- **Real-time Fill Monitoring Dashboard:** Extend this to a streaming dashboard using Plotly Dash or Streamlit.

---

## 📚 Notable Features

- 🌟 Dual-layer heatmaps with normalization
- 🔍 Spread spike detection logic
- 🏦 VWAP calculation per firm
- ⚖️ Aggressiveness metrics (rarely seen visualized this way)
- 🧠 Firm clustering (unsupervised ML)

---

## 📈 Charts & Visuals Used
- Bar Charts (vertical + horizontal + stacked)
- Donut Pie Chart
- Heatmaps
- Rolling Line Chart
- Boxplot + Histogram
- Pairplot (Clustering)

---

## 🎓 Author
Developed for the Jump Trading Take-Home Exercise by **Lahiru Prasad**

---

## 🚪 License
This notebook is provided for educational and demonstration purposes only.

---

Feel free to fork, improve, or integrate this into your own data science workflow! 🚀

