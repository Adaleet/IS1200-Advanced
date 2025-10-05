# IS1200-Advanced: A Security Demo - Encryption on DTEK-V

**Authors:**
- Adalet Adiljan
- Munira Ahmed

**Date:** 2025-09-15

## 🎯 Objective
This project demonstrates simple encryption and decryption on the DTEK-V embedded platform.  
Users can input plaintext via UART, select an algorithm and mode, and receive ciphertext back.

## ✅ Features
- Caesar cipher (encrypt/decrypt)
- XOR encryption (encrypt/decrypt)
- UART input/output
- Mode and algorithm selection with buttons/switches 
- (Optional) LEDs and 7-segment display for feedback  

## 🛠️ Build & Run
1. Clone the repo:  
   ```bash
   git clone https://github.com/Adaleet/IS1200-Advanced.git
   cd IS1200-Advanced
   ```

Build with the RISC-V toolchain:
   ```bash
make
   ```

Upload to the DTEK-V board (adjust if needed):

   ```bash
dtekv-loader project.bin
   ```