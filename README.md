# The-DES-Algorithm-Illustrated-for-C-code



- **Secure Hash Algorithms**, also known as SHA, are a family of cryptographic functions designed to keep data secured. It works by transforming the data using a hash function: an algorithm that consists of bitwise operations, modular additions, and compression functions. The hash function then produces a fixed-size string that looks nothing like the original. These algorithms are designed to be one-way functions, meaning that once they’re transformed into their respective hash values, it’s virtually impossible to transform them back into the original data. A few algorithms of interest are SHA-1, SHA-2, and SHA-3, each of which was successively designed with increasingly stronger encryption in response to hacker attacks. SHA-0, for instance, is now obsolete due to the widely exposed vulnerabilities.

- A lot of times when you work on some project, you want to display data on computer. This can be done with USART peripheral on MCU. With USART you can connect more than just computer, you can connect with GSM modules, GPRS, bluetooth and so much more. Our discovery board supports up to 8 USART channels. In this tutorial we will use USART1 to show principle how to use USART in our project. But first, we have to initialize our pins and peripheral.
- This example runs on STM32F407xx/417xx, STM32F429xx and STM32F439xx devices on STM32 Standard Peripheral Libraries.

| U(S)ARTx  | TX  | RX | APB |                      
| :------------ |:---------------:| -----:| -----:|
| USART1      | PA9 | PA10 | 2 |
| USART2      | PA2 | PA3 | 1 |
| USART3      | PA10 | PB11 | 1 |
| USART4      | PA0 | PA1 | 1 |
| USART5      | PC12 | PD2 | 1 |
| USART6      | PC6 | PC7 | 1 |
| USART7      | PE8 | PE7 | 1 |
| USART7      | PE1 | PE0 | 1 |
#### Hyperterminal configuration:
    - Word Length = 8 Bits
    - One Stop Bit
    - No parity
    - BaudRate = 115200 baud
    - flow control: None
### USART1 uses pins
- PA9 -TX for transmitting data
- PA10 -RX for receiving data;
![](http://2.bp.blogspot.com/-oaqvBEOZy_g/VTta340i9iI/AAAAAAAAAY0/IX7GS22VwS8/s1600/stm32f4%2Bto%2Bdb9.jpg)
### LED3 & LED4 uses pins
- PG13 green led
- PG14 yellow led
  But first a bit of history of how DES came about is appropriate, as well as a look toward the future.

## **Algoritm**

![](https://ds055uzetaobb.cloudfront.net/brioche/uploads/3MYOioyY35-screen-shot-2016-06-25-at-32727-pm.png?width=1200)

## \*\*Source:

- https://brilliant.org/wiki/secure-hashing-algorithms/
- https://www.ipa.go.jp/security/rfc/RFC3174EN.html
