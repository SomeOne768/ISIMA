# Programmation avancée — Java

Version to use: [main](https://github.com/ol-v-er/isima-poa-2023-TP7-ZOGHLAMI). Branch main updated ✅

## TP7 – Threads

This repository is an answer of the exercises from TP7 that you can find [here](https://etudiants.openium.fr/javaf5/java_3A_F5_TP7.pdf).<br/>
It contains the source code and informations associate to TP7 of Advanced Java Programmation and it aims to make us 
being familiar with Threads.

### Behavior
This repository contains multiples branches because of multiple fails during test:
1. [alternative-wait-with-ms](https://github.com/ol-v-er/isima-poa-2023-TP7-ZOGHLAMI/tree/alternative-wait-with-ms) where we directly make the current thread wait with a delay (4s)
2. [alternative](https://github.com/ol-v-er/isima-poa-2023-TP7-ZOGHLAMI/tree/alternative) where threads such as Producteur will wait by itself with synchronized method dectecting stock empty
3. [V4](https://github.com/ol-v-er/isima-poa-2023-TP7-ZOGHLAMI/tree/V4) where now everything is synchronized on the stock but if something wrong happens, consummer will forget the quantity he wanted
4. [V5](https://github.com/ol-v-er/isima-poa-2023-TP7-ZOGHLAMI/tree/V5) is the one to use. This not optimal because we use a lot of notifyAll() and wake for all for nothing. However, this is the one respecting the most the subject.

### Added rules:
To be sure that consumers don't die and stay healthy, we put a max of 100 santas to buy.
Also, our factory begin to be used and too old after 500 pieces producted. So, we close them after this time.


## Author
Abdeljalil ZOGHLAMI <br/>
ZZ3 F5 - ISIMA <br/>
Year 2023/2024 <br/>

## Emoji for commit
You can find a lot of them [here](https://gist.github.com/parmentf/035de27d6ed1dce0b36a).

The ones I often use:
- 🗑️
- 📦 : package :
- 🔧 : wrench :
- 🔨 : hammer :
- 🔥 : fire :
- ✨ : sparkles :
- 📚 : books :
- ♻️ : recycle :
- ✅ : white_check_mark :