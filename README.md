# UART Interface for Embedded Communication

## 1. Introduction

The purpose of this project is to directly communicate with the **ATmega328P microcontroller** from a computer using the **Arduino Uno** board. It demonstrates how data can be transmitted and received serially using the **UART communication protocol** through the TX and RX pins on the Arduino board.

Since the project involves both **digital input** and **digital output** components, it also shows how to combine these operations in pure C language alongside UART communication.

The main goal of this project is to understand how UART is used in embedded systems and how to receive commands that trigger hardware actions, such as turning on an LED or detecting a button press.

---

## 2. Project Code

**GitHub Repository:**
[Embedded_Systems_ROKAIA_2301199](https://github.com/Rokaia34/Embedded_Systems_ROKAIA_2301199)

**Local Root Directory:**
[`Embedded_Systems_CW1_ROKAIA`](./Embedded_Systems_CW1_ROKAIA/)

---

## 3. Test Cases

Automated test cases were developed using the **[Robot Framework](https://robotframework.org/)** to verify UART communication logic for both transmission and reception.

**Test Suite Path:**
[`uart_tests.robot`](./tests/uart_tests.robot)

---

## 4. Bill of Materials (BOM)

**BOM:**
[`bom.csv`](./BOM/bom.csv)

**Optimized BOM:**
[`optimized_bom.csv`](./BOM/optimized_bom.csv)

---

## 5. Video Demonstration

A short demonstration video showcasing UART transmission and reception in action.
[📽️ Watch Demonstration Video](./Video%20demonstration/Video.mp4)

---

## 6. Design

System design and implementation details are described in the design document.
[`Project_Design_Document.md`](./Documents/Project_Design_Document.md)
