# The-DES-Algorithm-Illustrated-for-C-code

by writer J. Orlin Grabbe

- **Secure Hash Algorithms**, also known as SHA, are a family of cryptographic functions designed to keep data secured. It works by transforming the data using a hash function: an algorithm that consists of bitwise operations, modular additions, and compression functions. The hash function then produces a fixed-size string that looks nothing like the original. These algorithms are designed to be one-way functions, meaning that once they’re transformed into their respective hash values, it’s virtually impossible to transform them back into the original data. A few algorithms of interest are SHA-1, SHA-2, and SHA-3, each of which was successively designed with increasingly stronger encryption in response to hacker attacks. SHA-0, for instance, is now obsolete due to the widely exposed vulnerabilities.

- A common application of SHA is to encrypting passwords, as the server side only needs to keep track of a specific user’s hash value, rather than the actual password. This is helpful in case an attacker hacks the database, as they will only find the hashed functions and not the actual passwords, so if they were to input the hashed value as a password, the hash function will convert it into another string and subsequently deny access. Additionally, SHAs exhibit the avalanche effect, where the modification of very few letters being encrypted causes a big change in output; or conversely, drastically different strings produce similar hash values. This effect causes hash values to not give any information regarding the input string, such as its original length. In addition, SHAs are also used to detect the tampering of data by attackers, where if a text file is slightly changed and barely noticeable, the modified file’s hash value will be different than the original file’s hash value, and the tampering will be rather noticeable.
  But first a bit of history of how DES came about is appropriate, as well as a look toward the future.

## **Algoritm**

![](https://ds055uzetaobb.cloudfront.net/brioche/uploads/3MYOioyY35-screen-shot-2016-06-25-at-32727-pm.png?width=1200)

## \*\*Source:

- https://brilliant.org/wiki/secure-hashing-algorithms/
- https://www.ipa.go.jp/security/rfc/RFC3174EN.html
